#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *new_node(int data);
node *custom_tree();
int has_path_sum(node *tree, int sum);
void free_tree(node *tree);

// We'll define a "root-to-leaf path" to be a sequence of nodes
// in a tree starting with the root node and proceeding downward
// to a leaf (a node with no children). We'll say that an empty
// tree contains no root-to-leaf paths.

// For this problem, we'll be concerned with the sum of the values
// of such a path.

// Given a binary tree and a sum, return true if the tree has a
// root-to-leaf path such that adding up all the values along the
// path equals the given sum. Return false if no such path can be
// found
int main(void) {
    node *tree = custom_tree();


    free_tree(tree);

    return 0;
}

node *new_node(int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

node *custom_tree() {
    // Depth 1 (root)
    node *root = new_node(5);

    // Depth 2
    root->left = new_node(4);
    root->right = new_node(8);

    // Depth 3
    root->left->left = new_node(11);
    root->right->left = new_node(13);
    root->right->right = new_node(4);

    // Depth 4
    root->left->left->left = new_node(7);
    root->left->left->right = new_node(2);
    root->right->right->right = new_node(1);

    return root;
}

int has_path_sum(node *tree, int sum) {
    // Just follow the arrows like you did when
    // You'll need to recurse down every path in
    // the tree and save each result
    if (tree == NULL) {
        return 0;
    }

}

// ADD A LOOP ATTEMPT HERE

void free_tree(node *tree) {
    if (tree != NULL) {
        free_tree(tree->left);
        free_tree(tree->right);
        free(tree);
    }
}
