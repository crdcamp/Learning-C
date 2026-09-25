#include <stdio.h>
#include <stdlib.h>

// Write a program in C to delete the first node of a Singly Linked List.
typedef struct node {
    int integer;
    struct node *next_node;
} node;

node *create_list(int length);
void print_list(char *message, node *list);
void free_list(node *list);

int main(void) {
    int list_length = 5;

    // Create and print original list
    node *list = create_list(list_length);
    if (list == NULL) return 1;
    print_list("Original list: ", list);



    return 0;
}

node *create_list(int length) {
    node *list = NULL;
    // We're gonna start defining the node size outside of the loop
    // How the hell didn't I spot that earlier?
    int node_size = sizeof(node);
    for (int i = 0; i < length; i++) {
        node *n = malloc(node_size);
        if (n == NULL) {
            printf("Error allocating memory when creating list\n");
            while (n != NULL) {
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



//void free_list(node *list)
