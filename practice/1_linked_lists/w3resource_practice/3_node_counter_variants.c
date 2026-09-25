#include <stdio.h>
#include <stdlib.h>

// Write a program in C to create a singly linked list of n nodes and count the number of nodes.
typedef struct node {
    int integer;
    struct node *next_node;
} node;

node *create_linked_list(int length);

int main(void) {
    node *linked_list = create_linked_list(6);
    if (linked_list == NULL) {
        return 1;
    }
}

node *create_linked_list(int length) {
    node *linked_list = NULL;
    for (int i = 0; i < length; i++) {
        // Allocate memory for each node
        node *n = malloc(sizeof(node));
        // If memory allocation unsuccessful, free all memory
        if (n == NULL) {
            printf("Error allocating memory for list creation\n");
            while (linked_list != NULL) {
                node *tmp = linked_list;
                linked_list = linked_list->next_node;
                free(tmp);
            }
            return NULL;
        }
        // Populate data
        n->integer = i + 1;
        n->next_node = linked_list;
        linked_list = n;
    }
    return linked_list;
}
