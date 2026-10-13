#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *new_node(int data);
node *insert_node(node *tree, int data);
int tree_size(node *tree_node);
void free_tree(node *root);

// This problem demonstrates simple binary tree traversal.
// Given a binary tree, count the number of nodes in the tree.
int main(void) {
    // Create the tree
    node *root = NULL;
    int input_array[] = {2, 1, 3};
    int input_array_len = sizeof(input_array) / sizeof(input_array[0]);
    for (int i = 0; i < input_array_len; i++) {
        root = insert_node(root, input_array[i]);
        // Definitely bad error handling. Pretty sure this doesn't handle all branches
        if (root == NULL) {
            printf("Error allocating memory for `new_node` on iteration %i. `data` = %i\n", i, input_array[i]);
            return 1;
        }
    }

    int size = tree_size(root);
    printf("Tree size = %i\n", size);
    free_tree(root);

    return 0;
}

node *new_node(int data) {
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

node *insert_node(node *tree, int data) {
    // If the tree is empty, fill it with the data value
    if (tree == NULL) {
        return new_node(data);
    }

    // Otherwise, recursively fill the tree
    if (data <= tree->data) tree->left = insert_node(tree->left, data);
    else if (data >= tree->data) tree->right = insert_node(tree->right, data);

    return tree;
}

void free_tree(node *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int tree_size(node *tree_node) {
    if (tree_node == NULL) {
        return 0;
    }

    // `tree_size(tree_node->left)` and `tree_size(tree_node->right)` don't actually return
    // a number by themselves. That's what the `+ 1` is for.
    // Instead `tree_size(tree_node->left)` and `tree_size(tree_node->right)` are what
    // continue the recursion down the rest of the tree, while the + 1 handles
    // the actual count (until, of course, you reach a null node)
    return tree_size(tree_node->left) + 1 + tree_size(tree_node->right);
}
