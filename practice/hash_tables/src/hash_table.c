#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

static ht_item* ht_new_item(const char *k, const char *v);
ht_hash_table *ht_new();
static void ht_del_item(ht_item *i);
void ht_del_hash_table(ht_hash_table *ht);

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
    free(ht->items);
    free(ht);
}
