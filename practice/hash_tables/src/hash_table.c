#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

// Here we define some initialization and deletion functions for `ht_item`s.
// This, as you might've guessed, is where we initialize some linked lists

// This is "initialized" in such a way that we store the key and value pairs
// into the chunks of memory in the linked list

// The function is marked as `static` because it will only ever be called by code
// internal to the hash table
static ht_item* ht_new_item(const char *k, const char *v) {
    ht_item *i = malloc(sizeof(ht_item));
    // `strdup` returns a pointer to a string, which is a duplicate of the string
    // pointed to by the input
    // The space for the new string is obtained as if `malloc` was invoked
    // THE RETURNED POINTER MUST BE FREED TO AVOID A MEMORY LEAK
    // Their usage of it here is a bit suspect to me, but we'll trust them
    i->key = strdup(k);
    i->value = strdup(v);
    return i;
}
