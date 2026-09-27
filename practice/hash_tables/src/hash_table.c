#include <stdlib.h>
#include <string.h>

// Here we define some initialization functions for `ht_item`s.
// This, as you might've guessed, is where we initialize some linked lists

// This is "initialized" in such a way that we store the key and value pairs
// into the chunks of memory in the linked list

// The function is marked as `static` because it will only ever be called by code
// internal to the hash table
