#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *new_node(int data);
node *custom_tree();
void print_postorder(node *tree_node);
void free_tree(node *root);

// Given a binary tree, print out the node of the tree according
// to a bottom-up "postorder" traversal - both subtrees of a node
// are printed out completely before the node itself is printed,
// and each left tree subtree is printed out before the right subtree
// You output should be "1 3 2 5 4"
// This is a bottom-up traversal
int main(void) {
    node *root = custom_tree();
    print_postorder(root);

    free_tree(root);

    return 0;
}

node *new_node(int data) {
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error allocating memory for `new_node`\n");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

node *custom_tree() {
    // Depth 1
    node *root;
    root->data = 4;

    // Depth 2
    root->left = new_node(2);
    root->right = new_node(5);

    // Depth 3
    root->left->left = new_node(1);
    root->left->right = new_node(3);

    return root;
}

void print_postorder(node *tree_node) {

}

void free_tree(node *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}
