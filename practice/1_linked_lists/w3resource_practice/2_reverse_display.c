#include <stdio.h>
#include <stdlib.h>
// Write a program to create a singly linked list of n nodes and display it in reverse order.

typedef struct node {
    int integer;
    struct node *next;
} node;

int main(void) {
    // Initiate null pointer for ze list
    node *list = NULL;

    // Create a loop for populating linked list (we're just gonna make it 5 integers)
    for (int i = 0; i < 5; i++) {
        // Allocate memory for a newly created node
        node *n = malloc(sizeof(node));
        if (n == NULL) {
            return 1;
        }

        // Assign node with an integer value to allocated memory

    return 0;
}
