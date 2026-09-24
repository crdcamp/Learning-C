#include <stdio.h>
#include <stdlib.h>

// https://www.youtube.com/watch?v=G0_I-ZF0S38
// Reverse a singly linked linked_list
// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL
// A linked linked_list can be revered either iteratively or recursively

typedef struct node {
    int integer;
    struct node *next_pointer;
} node;

node create_linked_linked_list(node first_pointer);
void print_linked_linked_list(node linked_list);
node iterative(node first_pointer);
node recursive(node first_pointer);

int main(void) {
    return 0;
}

// Create a linked linked_list of 5 integers
node create_linked_linked_list(node first_pointer) {
    // Initiate the linked_list
    node *linked_list = NULL;

    // Iterate though only 5 integers
    for (int i = 0; i < 5; i++) {
        // Allocate memory for a node
        node *n = malloc(sizeof(node));
        // Assign an integer to the node
        n->integer = i + 1;
        // Assign a location for the next pointer
        n->next_pointer = linked_list;
        // Update `linked_list''s location for the next iteration
        linked_list = n;
    }

    return *linked_list;
}

void print_linked_linked_list(node linked_list) {
    return;
}

node iterative(node first_pointer) {
    // So, essentially what we want to do here is reverse
    // the pointers

    // We can use two pointer for this
    // Current pointer: initialized a pointer to the first node (head)
    // Previous pointer: initially set to `NULL`
}
