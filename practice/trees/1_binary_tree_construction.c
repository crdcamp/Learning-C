#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *new_tree_node(int value);
TreeNode *insert_tree_node(TreeNode *root, int value);
void print_tree(TreeNode *root, int depth);
void free_tree(TreeNode *root);

// Write a C program that creates a binary tree. Allow users to input nodes and build a binary tree structure.
int main(void) {
    // Make the root of the tree
    TreeNode *root = new_tree_node(1);

    // Make 10 test nodes and insert them into the tree
    int test_nodes[] = {5, 3, 8, 1, 4, 7, 9};
    int length = sizeof(test_nodes) / sizeof(test_nodes[0]);
    for (int i = 0; i < length; i++) {
        TreeNode *test_node = insert_tree_node(root, test_nodes[i]);
    }

    // Print the tree
    print_tree(root, 1);

    free_tree(root);

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
        root->right = insert_tree_node(root->right, value);
    }

    // If the provided value is smaller than the current
    // node's value, send it left
    if (value < root->data) {
        root->left = insert_tree_node(root->left, value);
    }

    return root;
}

void print_tree(TreeNode *root, int depth) {
    if (root == NULL) {
        return;
    }
    printf("enter %i\n", root->data);
    printf("leave %i\n", root->data);

    printf("%*sDepth %i: Node value = %i\n", depth * 4, "", depth, root->data);

    print_tree(root->left, depth + 1);
    print_tree(root->right, depth + 1);
}

void free_tree(TreeNode *root) {
    if (root == NULL) return;

    free_tree(root->left);
    free_tree(root->right);

    free(root);
}
