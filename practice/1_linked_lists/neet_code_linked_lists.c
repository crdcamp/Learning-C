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

node *create_linked_list(int length);
void print_linked_linked_list(char *message, node *linked_list);
void free_linked_list(node *linked_list);
node iterative_reverse_linked_list(node *first_pointer);
node recursive(node *first_pointer);

int main(void) {
    // Initiate and display original linked list
    node *linked_list = create_linked_list(5);
    print_linked_linked_list("Original linked list", linked_list);

    // If create_linked_list fails, exit the program
    if (linked_list == NULL) {
        return 1;
    }

    // Reverse linked list using an iterative method
    node iterative_reversed_linked_list = iterative_reverse_linked_list(linked_list);
    print_linked_linked_list("Iterative linked list", &iterative_reversed_linked_list);

    // Reverse the linked list using a recursive method

    // Free memory
    free_linked_list(linked_list);
}

// Create a linked linked_list that refers to 5 ordered integers
node *create_linked_list(int length) {
    // Initiate the linked_list
    node *linked_list = NULL;

    // Iterate though only 5 integers
    for (int i = 0; i < length; i++) {
        // Allocate memory for a node
        node *n = malloc(sizeof(node));
        if (n == NULL) {
            printf("Error allocating memory when creating linked list\n");
            return NULL;
        }
        // Assign an integer to the node
        n->integer = i + 1;
        // Assign a location for the next pointer
        n->next_pointer = linked_list;
        // Update `linked_list''s location for the next iteration
        linked_list = n;
    }
    return linked_list;
}

// Iterate over a linked list to free its memory
void free_linked_list(node *linked_list) {
    node *ptr = linked_list;
    while (ptr != NULL) {
        // Need to declare `next_pointer` before pointing to the next pointer
        // Without this, the last line in this loop is referring to memory that
        // has already been freed (use-after-free error)
        node *next_pointer = ptr->next_pointer;
        free(ptr);
        ptr = next_pointer;
    }
}

// Iterate over a linked list to print each entry in it
void print_linked_linked_list(char *message, node *linked_list) {
    printf("%s: ", message);
    node *ptr = linked_list;
    while (ptr != NULL) {
        printf("%i ", ptr->integer);
        ptr = ptr->next_pointer;
    }
    printf("\n");
}

node iterative_reverse_linked_list(node *linked_list) {
    // So, essentially what we want to do here is reverse
    // the pointers

    // We can use two pointer for this
    // Current pointer: initialized a pointer to the first node (head)
    // Previous pointer: initially set to `NULL`
    node *current_node = linked_list;
    while(current_node != NULL) {
        // Define next node
        node *next_node = current_node->next_pointer;
        if (next_node == NULL) {
            break;
        }


        // Iterate to next node
        current_node = next_node;
    }

    return *current_node;
}
