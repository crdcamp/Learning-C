#include <stdio.h>
#include <stdlib.h>
// Write a program to create a singly linked list of n nodes and display it in reverse order.

typedef struct node {
    int number;
    struct node *next_node;
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

        n->number = i + 1; // Assign node with an integer value to newly allocated node memory
        n->next_node = NULL; // Safety first (I forget why we even do this)
        n->next_node = list; // Assign previous node's address so we can backtrack
        list = n; // Ensure the most recent node is the beginning of the linked list
    }

    // Print list in reverse order
    node *ptr = list;
    printf("REVERSED ORDER:\n");
    while (ptr != NULL) {
        printf("Meow %i\n", ptr->number);
        ptr = ptr->next_node;
    }
    printf("\n");

    // Print the list in order
    printf("ORDERED uhhhhh... ORDER:\n");
    node *previous_node;
    node *current_node;
    ptr = list;

    if (ptr != NULL) {
        previous_node = ptr;
        // ERROR: CURRENT NODE WAS NEVER INITIALIZED
        current_node = current_node->next_node;
        ptr = ptr->next_node;
        // Convert the first node as last
        // I think we're essentially reversing the
        // list by assigning null backwards as we iterate
        previous_node->next_node = NULL;

        while(ptr != NULL) {
            ptr = ptr->next_node;
            current_node->next_node = previous_node;

            previous_node = current_node;
            current_node = ptr;
        }
        // Convert the last node as the head node
        // ERROR: YOU'RE SUPPOSED TO BE EDITING THE LIST,
        // NOT THE POINTER
        ptr = previous_node;
    }

    ptr = list;
    while (ptr != NULL) {
        printf("Meow %i\n", ptr->number);
        ptr = ptr->next_node;
    }

return 0;
}
