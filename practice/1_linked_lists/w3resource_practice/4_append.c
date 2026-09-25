// Write a program in C to insert a new node at the end of a Singly Linked List.
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int integer;
    struct node *next_node;
} node;

node *create_linked_list(int length);
void free_linked_list(node *linked_list);
void print_linked_list(node linked_list);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s `int`\n", argv[0]);
        return 1;
    }

    // Yet another inusfficent `int` type check
    int length = atoi(argv[1]);
    if (!isdigit(length)) {
        printf("Input parameter must be a digit\n");
        return 1;
    }

    node *linked_list = create_linked_list(length);
    if (linked_list == NULL)
        return 1;

    free(linked_list);
}

node *create_linked_list(int length) {
    // Create null pointer
    node *linked_list = NULL;
    // Populate with data according to `length`
    for (int i = 0; i < length; i++) {
        // Allocate space for a node
        node *n = malloc(sizeof(node));
        if (n == NULL) {
            printf("Error allocating memory\n");
            while (linked_list != NULL) {
                node *tmp = linked_list;
                linked_list = n->next_node;
                free(tmp);
            }
            return NULL;
        }
        // Fill `integer` with an `int`
        n->integer = i + 1;
        // Populate next node
        n->next_node = linked_list;
        // Assign allocated memory to linked list for next iteration
        linked_list = n;
    }
    return linked_list;
}

void free_linked_list(node *linked_list) {
    node *ptr = linked_list;
    while (ptr != NULL) {
        node *next_node = ptr->next_node;
        free(ptr);
        ptr = next_node;
    }
}
