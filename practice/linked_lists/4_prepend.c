#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int integer;
    struct node *next_node;
} node;

node *create_list(int length);
void print_list(char *message, node *list);
node *sort_list(node *list);
node *prepend_list(node *list, int value_to_prepend);
void free_list(node *list);

// Write a program in C to insert a new node at the beginning of a Singly Linked List.
int main(void) {
    int length = 5;
    node *list = create_list(length);
    if (list == NULL) {
        return 1;
    }
    print_list("Original: ", list);

    list = sort_list(list);
    print_list("Sorted: ", list);

    list = prepend_list(list, 67);
    print_list("Prepended: ", list);

    free_list(list);

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

node *sort_list(node *list) {
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

node *prepend_list(node *list, int value_to_prepend) {
    // Allocate memory for the node to append
    node *prepended_node = malloc(sizeof(node));
    if (prepended_node == NULL) {
        // No need for all that mumbo jumbo. The original list isn't edited at all
        printf("Error allocating memory during list creation\n");
        return list;
    }
    // Insert integer value from function parameter into node to append
    prepended_node->integer = value_to_prepend;
    // Ensure that the appended element points to the original first element
    prepended_node->next_node = list;
    // Finally, append dat node
    list = prepended_node;
    return list;
}

void free_list(node *list) {
    node *current_node = list;
    while (current_node != NULL) {
        node *next_node = current_node->next_node;
        free(current_node);
        current_node = next_node;
    }
}
