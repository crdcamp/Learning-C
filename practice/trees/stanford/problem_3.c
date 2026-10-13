#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *new_node(int data);
node *insert_node(node *new_node);
int max_depth(node *tree_node);
void free_tree(node *root);

// Given a binary tree, compute its "max depth" - the number of nodes
// along the longest path from the root node down to the farthest leaf
// node.
int main(void) {
    int input_array[] = {4, 2, 1, 3, 5};

    return 0;
}

node *new_node(int data) {
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = data;

    return new_node;
}
