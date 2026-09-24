#include <stdio.h>
#include <stdlib.h>

// https://www.youtube.com/watch?v=G0_I-ZF0S38
// Reverse a singly linked list
// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL
// A linked list can be revered either iteratively or recursively

typedef struct node {
    int integer;
    struct node *next_pointer;
} node;

void create_linked_list(node first_pointer);
void iterative(node first_pointer);
void recursive(node first_pointer);

int main(void) {
    return 0;
}

// Create a linked list of 5 integers
void create_linked_list(node first_pointer) {
    for (int i = 0; i < 5; i++) {

    }
}

void iterative(node first_pointer) {
    // So, essentially what we want to do here is reverse
    // the pointers

    // We can use two pointer for this
    // Current pointer: initialized a pointer to the first node (head)
    // Previous pointer: initially set to `NULL`
}
