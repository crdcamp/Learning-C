#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *new_node(int data);
node *insert_node(node *tree_node, int data);
int find_tree_min(node *tree_node);
void free_tree(node *root);

// Given a non-empty binary search tree, return the minimum data
// value found in that tree. Note that it's not necessary to search
// the entire tree. This can be solved with recursion or a simple
// while loop
int main(void) {
    return 0;
}
