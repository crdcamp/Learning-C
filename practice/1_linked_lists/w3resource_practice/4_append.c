#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Write a program in C to insert a new node at the end of a Singly Linked List.
typedef struct node {
    int integer;
    struct node *next_node;
} node;

node *create_list(int length);
void free_list(node *list);
void print_list(char *message, node *list);
void sort_list(node *list);
void append_to_list(node *list);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s `int`\n", argv[0]);
        return 1;
    }

    // Yet another inusfficent `int` type check
    if (!isdigit(*argv[1])) {
        printf("Input parameter must be a digit\n");
        return 1;
    }

    int length = atoi(argv[1]);
    node *list = create_list(length);
    if (list == NULL)
        return 1;

    print_list("Original: ", list);

    free(list);
}

node *create_list(int length) {
    // Create null pointer
    node *list = NULL;
    // Populate with data according to `length`
    for (int i = 0; i < length; i++) {
        // Allocate space for a node
        node *n = malloc(sizeof(node));
        if (n == NULL) {
            printf("Error allocating memory\n");
            while (list != NULL) {
                node *tmp = list;
                list = n->next_node;
                free(tmp);
            }
            return NULL;
        }
        // Fill `integer` with an `int`
        n->integer = i + 1;
        // Populate next node
        n->next_node = list;
        // Assign allocated memory to linked list for next iteration
        list = n;
    }
    return list;
}

void free_list(node *list) {
    node *ptr = list;
    while (ptr != NULL) {
        node *next_node = ptr->next_node;
        free(ptr);
        ptr = next_node;
    }
}

void print_list(char *message, node *list) {
    printf("%s", message);
    node *ptr = list;
    while (ptr != NULL) {
        printf("%i ", ptr->integer);
        node *next_node = ptr->next_node;
        ptr = next_node;
    }
    printf("\n");
}

void append_to_list(node *list) {


    printf("Working on it\n");
}
