#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *new_tree_node(int value);
TreeNode *insert_tree_node(TreeNode *root, int value);
// Write a C program that creates a binary tree. Allow users to input nodes and build a binary tree structure.
int main(void) {
    return 0;
}

TreeNode *new_tree_node(int value) {
    // Allocate memory (don't forget too use error handling)
    TreeNode *new_node = malloc(sizeof(TreeNode));
    if (new_node == NULL) {
        printf("Error allocating memory for `new_node`\n");
        return NULL;
    }

    // Fill up dat data
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

TreeNode *insert_tree_node(TreeNode *root, int value) {
    // If there is no root... make one!
    if (root == NULL) {
        return new_tree_node(value);
    }

    // If the provided value is larger than the current
    // node's value, send it right
    if (value > root->data) {
        root->right = insert_tree_node(root, value);
    }

    // If the provided value is smaller than the current
    // node's value, send it left
    if (value < root->data) {
        root->left = insert_tree_node(root, value);
    }
}
