#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int integer;
    struct node *next_node;
} node;

void create_list(int length);
node *list_length(node *list);
node *list_middle(node *list);
node *delete_middle(node *list);

// Write a program in C to delete a node from the middle of a Singly Linked List.
int main(void) {

}
