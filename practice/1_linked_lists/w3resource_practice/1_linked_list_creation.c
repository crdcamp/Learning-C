// https://www.w3resource.com/c-programming-exercises/linked_list/index.php
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *next;
} node;

// Add free memory function
//void free_links(meow meow);

// Write a program in C to create and display a Singly Linked List.
int main(int argc, char *argv[]) {
    // Only accept three parameters
    if (argc != 4) {
        printf("Usage: %s int1 int2 int3\n", argv[0]);
        return 1;
    }

    // Only accept integers (insufficient check but that's fine for now)
    for (int i = 1; i < argc; i++) {
        if (!isdigit(*argv[i])) {
            printf("Usage: %s int1 int2 int3\n", argv[0]);
            return 1;
        }
    }

    // Initiate a null pointer for list
    node *list = NULL;
    // Iterate over each argument to assign it to the linked list
    for (int i = 1; i < argc; i++) {
        // Allocate memory for the current node
        node *n = malloc(sizeof(node));
        if (n == NULL) {
            printf("Memory allocation didn't go as planned ahhhhhhh!!!!\n");
            return 1;
        }
        // Assign the argv integer to the node
        n->number = atoi(argv[i]);
        // Make next null just for safety
        n->next = NULL;
        // Assign the previous iteration's memory location
        // to `next` within the node
        n->next = list;
        // Update `list`'s memory start location
        list = n;
    }

    // Now let's print dis bitch out
    // We use `ptr` instead of directly working with `list` here because
    // is we were to just use `list` we'd end up editing the starting pointer
    // for the linked list in the final line, thus losing track of where the
    // list begins
    node *ptr = list;
    while (ptr != NULL) {
        printf("Number: %i\n", ptr->number);
        printf("Address: %p\n", ptr->next);
        ptr = ptr->next;
    }

    // And free that mf memory bbyyyyy
    while (ptr != NULL) {
        node *next= ptr->next;
        free(ptr);
        ptr = next;
    }

    return 0;
}
