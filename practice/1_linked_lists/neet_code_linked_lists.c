#include <ctype.h>
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

// General use functions
node *create_linked_list(int length);
void print_linked_list(char *message, node *linked_list);
void free_linked_list(node *linked_list);

// Functions for reversing the linked list
node *iterative_reverse_linked_list(node *first_pointer);
node *recursive_reverse_linked_list(node *first_pointer);

// NOTE that we're only allocating the original linked list to the heap here
// The reversed linked lists are not
int main(int argc, char *argv[]) {
    // Ensure only one parameter is provided
    if (argc != 2) {
        printf("Incorrect parameter entry. Usage: %s `int`\n", argv[0]);
        return 1;
    }

    // Check if user is inputting a digit (insufficient check)
    if (!isdigit(*argv[1])) {
        printf("Please provide a digit as a parameter\n");
        return 1;
    }

    // Convert user input to a digit
    int length = atoi(argv[1]);

    // Initiate and display original linked list
    node *linked_list = create_linked_list(length);
    print_linked_list("Original linked list: ", linked_list);
    if (linked_list == NULL) {
        return 1;
    }

    // Reverse linked list using an iterative method
    node *iterative_reversed_linked_list = iterative_reverse_linked_list(linked_list);
    print_linked_list("Iterative revered linked list: ", iterative_reversed_linked_list);

    // Reverse the linked list using a recursive method
    //node *recursive_reversed_linked_list = recursive_reverse_linked_list(linked_list);

    // Free memory
    free_linked_list(linked_list);
}

// Create a linked linked_list that refers to 5 ordered integers
// Note that we're assigning the results of these functions as pointers
// This is because we want to assign the result to a memory address
// Without assigning the result to a memory address,
node *create_linked_list(int length) {
    // Initiate the linked_list
    node *linked_list = NULL;

    // Iterate though only 5 integers
    for (int i = 0; i < length; i++) {
        // Allocate memory for a node
        node *n = malloc(sizeof(node));
        if (n == NULL) {
            printf("ERROR: Failed to allocate memory when creating linked list\n");
            // Make sure to free previously allocated memory if memory allocation fails part way through
            while (linked_list != NULL) {
                node *tmp_pointer = linked_list;
                linked_list = linked_list->next_pointer;
                free(tmp_pointer);
            }
            // Return null and exit program in `main`
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
void print_linked_list(char *message, node *linked_list) {
    printf("%s", message);
    node *ptr = linked_list;
    while (ptr != NULL) {
        printf("%i ", ptr->integer);
        ptr = ptr->next_pointer;
    }
    printf("\n");
}

node *iterative_reverse_linked_list(node *linked_list) {
    node *current_node = linked_list;
    node *previous_node = NULL; // Defined as `NULL` so we can put `NULL` on the opposite end of the linked list
    while(current_node != NULL) {
        // Define next node (again, to avoid a "use-after-free" error)
        node *next_node = current_node->next_pointer;
        // Assign current node as previous node
        // Since it was already defined as `NULL` before the look, we've already taken
        // care of putting `NULL` on the other end of the list with the first iteration
        // When considering the rest of the iterations, `previous_node` (as you can see in the next line)
        // is assigned as `current_node`, thus enabling us to reverse the pointer's direction
        current_node->next_pointer = previous_node;
        // Move previous node one step further (the final step for ensuring the above line works in future iterations)
        previous_node = current_node;
        // Iterate to next node
        current_node = next_node;
    }
    return previous_node;
}
