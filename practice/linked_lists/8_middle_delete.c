#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int integer;
    struct node *next_node;
} node;

node *create_list(int length);
void print_list(node *list);
node *list_length(node *list);
node *list_middle(node *list);
node *delete_middle(node *list);

// Write a program in C to delete a node from the middle of a Singly Linked List.
int main(void) {
    int list_length = 10;
    node *list = create_list(list_length);
    printf("Original list: ");
    print_list(list);
    printf("\n");
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
}

// I think I might just make a function where you enter the
// index you want to delete and call it all good with these
// somewhat silly problem types
// Actually, let's just do that in another file and call it "bonus"
// or something like that
