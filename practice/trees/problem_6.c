#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *new_node(int data);
node *custom_tree(node *new_node, int data);
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
    // `int`s are spaced based on tree depth

    return 0;
}

node *new_node(int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

node *custom_tree(node *new_node, int data) {
    // Depth 1 (root)
    node *root = NULL;
    root->data = 5;

    // Depth 2
    node *depth_2_left_node = root->left;
    depth_2_left_node->data = 4;

    node *depth_2_right_node = root->right;
    depth_2_right_node->data = 8;

    // Depth 3
    // `node_1` corresponds to left, `node_2` corresponds to right
    node *depth_3_left_node_1 = depth_2_left_node->left;
    depth_3_left_node_1->data = 11;

    node *depth_3_right_node_1 = depth_2_right_node->left;
    node *depth_3_right_node_2 = depth_2_right_node->right;
    depth_3_right_node_1->data = 13;
    depth_3_right_node_2->data = 4;

    // Depth 4
    node *depth_4_left_node_1 = depth_3_left_node_1->left;
    node *depth_4_left_node_2 = depth_3_left_node_1->right;
    depth_4_left_node_1->data = 7;
    depth_4_left_node_2->data = 2;

    node *depth_4_right_node_2 = depth_3_right_node_2->right;
    depth_4_right_node_2->data = 1;

    return root;
}

void free_tree(node *tree) {
    if (tree != NULL) {
        free_tree(tree->left);
        free_tree(tree->right);
        free(tree);
    }
}
