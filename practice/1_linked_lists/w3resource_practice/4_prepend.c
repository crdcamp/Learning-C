#include <stdio.h>
#include <stdlib.h>

// Write a program in C to insert a new node at the beginning of a Singly Linked List.
typedef struct node {
    int integer;
    struct node *next_node;
} node;

node *create_list(int length);
void print_list(char *message, node *list);
void *sort_list(node *list);
void free_list(node *list);
void *prepend_list(node *list);

int main(void) {
    int length = 5;
    node *list = create_list(length);
    if (list == NULL) {
        return 1;
    }
    print_list("Original list: ", list);

    list = sort_list(list);
    print_list("Sorted list: ", list);

    // prepend_list(list);
    // free_list(list);

    return 0;
}

node *create_list(int length) {
    node *list = NULL;
    for (int i = 0; i < length; i++) {
        node *n = malloc(sizeof(node));
        if (n == NULL) {
            printf("Error allocating memory during list creation\n");
            while (n != NULL) {
                node *tmp = list;
                list = n->next_node;
                free(tmp);
            }
            return NULL;
        }
    n->integer = i + 1;
    n->next_node = list;
    list = n;
    }
    return list;
}

void print_list(char *message, node *list) {
    printf("%s", message);
    node *current_node = list;
    while (current_node != NULL) {
        printf("%i ", current_node->integer);
        node *next_node = current_node->next_node;
        current_node = next_node;
    }
    printf("\n");
}

void *sort_list(node *list) {
    node *previous_node = NULL;
    node *current_node = list;
    while (current_node != NULL) {
        node *next_node = current_node->next_node;
        current_node->next_node = previous_node;
        previous_node = current_node;
        current_node = next_node;
    }
    return previous_node;
}
