// This is where out key-item values will be stored (obviously)
typedef struct {
    char *key;
    char *value;
} ht_item;

// Ze items go into ze hash table
// `ht_item` is a double pointer because (I think) that since an
// array is already a pointer, we need to store an address to that address (aka... a double pointer)


// The hash table stores an array of pointers to items and some
// details about the item's size and count
// `items' will become the array that stores the items. You index this array to
// find the actual `ht_item` stored inside the array.
// Consizer `size` and `count` to just be metadata that assist in the creation,
// management, and deletion of the hash table itself
typedef struct {
    int size;
    int count;
    ht_item **items;
} ht_hash_table;
