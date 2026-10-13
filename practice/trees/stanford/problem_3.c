#include <stdio.h>
#include <stdlib.h>
typedef struct node {

    int data;
    struct node *left;
    struct node *right;
} node;

node *new_node(int data);
node *insert_node(node *new_node, int data);
int max_depth(node *tree_node);
void free_tree(node *root);

// Given a binary tree, compute its "max depth" - the number of nodes
// along the longest path from the root node down to the farthest leaf
// node.
int main(void) {
    // Create the tree
    node *root = NULL;
    int input_array[] = {4, 2, 1, 3, 5};
    int input_array_len = sizeof(input_array) / sizeof(input_array[0]);
    for (int i = 0; i < input_array_len; i++) {
        insert_node(root, input_array[i]);
        // Still using insufficient error handling for tree creation
        // We'll work on that after we've completed all problems
        if (root == NULL) {
            printf("Error allocating memory\n");
            return 0;
        }
    }

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

// I think I'm gonna leave the brackets from here on out.
// Makes the code much more legible
node *insert_node(node *tree, int data) {
    if (tree == NULL) {
        return new_node(data);
    }
    if (data <= tree->data) {
        tree->left = insert_node(tree->left, data);
    }
    else if (data >= tree->data) {
        tree->right = insert_node(tree->right, data);
    }

    return tree;
}
