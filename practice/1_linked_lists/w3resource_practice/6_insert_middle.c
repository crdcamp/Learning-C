#include <cstddef>
#include <stdio.h>
#include <stdlib.h>

// Write a program in C to insert a node in the middle of a Singly Linked List.

typedef struct node {
    int integer;
    struct node *next_node;
} node;

node *create_list(int length);
void print_list(char *message, node *list);
node *sort_list(node *list);
node *insert_middle(node *list);
void free_list(node *list);

int main(void) {
    // Now we're gonna work with multiple lengths just to
    // be absolutely certain we're doing this right
    int lengths[] = {5, 7, 10};

    return 0;
}

// node create_list(int length) {

// }
