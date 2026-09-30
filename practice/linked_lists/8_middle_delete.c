#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int integer;
    struct node *next_node;
} node;

node *create_list(int length);
void print_list(node *list);
int get_list_length(node *list);
node *delete_list_middle(node *list);

// Write a program in C to delete a node from the middle of a Singly Linked List.
int main(void) {
    node *list = create_list(10);

    printf("Original list: ");
    print_list(list);

    int list_length = get_list_length(list);
    printf("List length: %i\n", list_length);

    node *middle_node = delete_list_middle(list);
    printf("After middle deletion: ");
    print_list(list);
    list_length = get_list_length(list);
    printf("New list length: %i\n", list_length);
}

node *create_list(int length){
    node *list = NULL;
    int node_size = sizeof(node);
    for (int i = 0; i < length; i++) {
        node *n = malloc(node_size);
        if (n == NULL) {
            printf("Error allocating memory when creating list\n");
            while (list != NULL) {
                node *tmp = list;
                list = tmp->next_node;
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

void print_list(node *list) {
    node *ptr = list;
    while (ptr != NULL) {
        printf("%i ", ptr->integer);
        node *next_node = ptr->next_node;
        ptr = next_node;
    }
    printf("\n");
}

// I think I might just make a function where you enter the
// index you want to delete and call it all good with these
// somewhat silly problem types
// Actually, let's just do that in another file and call it "bonus"
// or something like that
int get_list_length(node *list) {
    int list_length = 0;
    node *current_node = list;
    while (current_node != NULL) {
        list_length++;
        current_node = current_node->next_node;
    }
    return list_length;
}

node *delete_list_middle(node *list) {
    node *current_node = list;
    node *previous_node = NULL;
    int middle_index = get_list_length(list) / 2;

    // Iterate up until right before the middle index so
    // you can adjust the pointers
    for (int i = 0; i < middle_index -1; i++) {
        previous_node = current_node;
        printf("Current node value: %i\n", current_node->integer);
        current_node = current_node->next_node;
    }
    // Define the middle node
    node *middle_node = current_node->next_node;

    // Redo ze linkage
    previous_node->next_node = current_node;
    current_node->next_node = middle_node->next_node;

    printf("Middle node value: %i\n", middle_node->integer);
    free(middle_node);
    // Connect the pointers before freeing the middle node


    return list;
}
