// This is where out key-item values will be stored (obviously)
typedef struct {
    char *key;
    char *value;
} ht_item;

// The hash table stores an array of pointers to items and some
// details about the item's size and count
typedef struct {
    int size;
    int count;
    ht_item **items;
} ht_hash_table;
