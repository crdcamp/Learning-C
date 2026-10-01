#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hash_table.h"

#define HT_INITIAL_BASE_SIZE 53
#define HT_PRIME_1 163
#define HT_PRIME_2 157

// Create
static ht_item* ht_new_item(const char *k, const char *v);
ht_hash_table *ht_new();
// Delete
static void ht_del_item(ht_item *i);
void ht_del_hash_table(ht_hash_table *ht);
// Retrieve
static int ht_get_hash(const char *s, const int num_buckets, const int attempt);
// Update
void ht_insert(ht_hash_table *ht, const char *key, const char *value);

int main(void) {
    ht_hash_table *ht = ht_new();
    ht_del_hash_table(ht);
}

// Here we define some initialization and deletion functions for
// `ht_item`s. This, as you might've guessed, is where we initialize
// some linked lists

// This is "initialized" in such a way that we store the key and value
// pairs into the chunks of memory in the linked list

// The function is marked as `static` because it will only ever be
// called by code internal to the hash table
static ht_item* ht_new_item(const char *k, const char *v) {
    ht_item *i = malloc(sizeof(ht_item));
    if (i == NULL) {
        printf("Error allocating memory for `ht_item`\n");
        return NULL;
    }
    // `strdup` returns a pointer to a string, which is a duplicate of the string ("string duplicate")
    // pointed to by the input
    // The space for the new string is obtained as if `malloc` was invoked
    // THE RETURNED POINTER MUST BE FREED TO AVOID A MEMORY LEAK
    // Since we're dealing with data storage here, the only time we're
    // freeing anything is when we delete it (for the most part).
    // So... we're probably gonna get to that later

    // Apparently the usage of `strdup` here is some form of defensive
    // programming. Something to do with ownership over variables
    // and injecting values or something like that.
    // Main takeaway: you probably want to always use `stdup` when
    // dealing with pointers to structs like this in C
    i->key = strdup(k);
    i->value = strdup(v);
    return i;
}

// In addition to wanting to be able to add a new item to a hash table,
// we also want to be able to add a new hash table (which I'm
// embarrassed to say is something I didn't consider)

// `size` defines how many items we can store, which we're fixing at
// 53 for now (more on that later)
// We also initialize an array of items with `calloc` to fill the
// array with NULL bytes, as we use NULL indicate a bucket is empty
ht_hash_table *ht_new() {
    ht_hash_table *ht = malloc(sizeof(ht_hash_table));
    ht->size = 53;
    ht->count = 0;
    // `calloc`'s first argument is number of elements in the array
    // you're allocating for
    // Thus, the second argument is the size in bytes of each
    // element in that array

    // `size_t` can "store the maximum size of a theoretically
    // possible object of any type (including array)""

    // I think it's just a data type that's basically an int?
    // Regardless, it's what the `sizeof` operator always returns,
    // so I'm not sure why they'd use it here at all

    // `calloc`'s first argument only accepts type `size_t`,
    // which (obviously) is why we need to use it here
    ht->items = calloc((size_t)ht->size, sizeof(ht_item*));
    return ht;
}

// Now we need functions for deleting items and tables to avoid
// those memory leaks mentioned earlier
static void ht_del_item(ht_item *i) {
    free(i->key);
    free(i->value);
    free(i);
}

void ht_del_hash_table(ht_hash_table *ht) {
    for (int i = 0; i < ht->size; i++) {
        ht_item *item = ht->items[i];
        if (item != NULL) {
            ht_del_item(item);
        }
    }
    // Remember that item's is a list of allocated memory (an array created with `calloc`)
    // This is why we need to free it independently of the hash table itself
    free(ht->items);
    free(ht);
}

// Now it's time for us to create a hash function
// This hash function will convert the input string to an integer
// and reduce the size of the integer to a fixed range by taking
// its remainder (in other words, pretty much the most basic of hash functions)

// The resulting variable should be a prime number larger than the size of
// the alphabet. Since we're hashing ASCII strings, which has an alphabet size
// of 128, we should chose a prime number larger than that
static int ht_hash(const char *s, const int a, const int m) {
    long hash = 0;
    const int len_s = strlen(s);
    for (int i = 0; i < len_s; i++) {
        // Get the has value by providing some arithmetic that's
        // a bit annoying to figure out the reasoning behind it
        hash += (long)pow(a, len_s - (i+1)) * s[i];
        // Get the remainder by dividing my number of buckets
        hash = hash % m;
    }
    // Return the hash number casted as an integer
    return (int)hash;
}

// As you know, a hash function ideally always returns an even distribution, yet
// this tends to be a pretty complicated thing to do
// For any hash distribution, there's a "pathological" set of inputs, which all hash
// the same value. To find this set of inputs you'd need to run a bunch of data
// through the hash function into the hash table (pretty straightforward).
// All inputs which hash to a particular bucket form a pathological set

// This obviously ties into collisions.
// Our hash table will handle collisions using a technique called "open addressing"
// with double hashing. Double hashing makes use of two hash functions to calculate
// the index an item should be stored after `i` collisions
static int ht_get_hash(const char *s, const int num_buckets, const int attempt) {
    // Convert hashes into indices to find
    const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
    const int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);
    // Since it's possible that `hash_b` will return 0, we add 1
    // to avoid inserting items into the same bucket over and over
    return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

// To insert a new key-value pair, we iterate through indexes until
// we find an empty bucket. When then insert the item into that bucket
// and increment the hash table's `count` attribute.
// The `count` value will become useful when we look at resizing
void ht_insert(ht_hash_table *ht, const char *key, const char *value) {
    ht_item *item = ht_new_item(key, value);
    int index = ht_get_hash(item->key, ht->size, 0);
    ht_item *cur_item = ht->items[index]; // Linked list type shi being used right here I'm pretty sure
    int i = 1;
    while (cur_item != NULL) {
        index = ht_get_hash(item->key, ht->size, i);
        cur_item = ht->items[index];
        i++;
    }
    //
    ht->items[index] = item;
    ht->count++;
}
