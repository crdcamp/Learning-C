// https://www.w3resource.com/c-programming-exercises/linked_list/index.php
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *next;
} node;

// Add free memory function

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
        node *n = malloc(sizeof(node));
        n->number = atoi(argv[i]);
        n->next = NULL;
        n->next = list;
    }

    return 0;
}
