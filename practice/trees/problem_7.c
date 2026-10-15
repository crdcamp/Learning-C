#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *new_node(int data);
node *custom_tree();
int find_path_sum(node *tree, int sum);
void free_tree(node *root);

// We'll define a "root-to-leaf path" to be a sequence of nodes
// in a tree starting with the root node and proceeding downward
// to a leaf (a node with no children). We'll say that an empty
// tree contains no root-to-leaf paths.

// For this problem, we'll be concerned with the sum of the values
// of such a path.

// Given a binary tree and a sum, return true if the tree find a
// root-to-leaf path such that adding up all the values along the
// path equals the given sum. Return false if no such path can be
// found
int main(void) {
    node *root = custom_tree();
    int example_sums[] = {27, 22, 26, 18};
    int example_sums_len = sizeof(example_sums) / sizeof(example_sums[0]);

    // Check if the example sum is found in the tree
    int result;
    for (int i = 0; i < example_sums_len; i++) {
        int example_sum = example_sums[i];
        result = find_path_sum(root, example_sum);
        printf("Example sum = %i, result = %i\n", example_sum, result);
    }

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

int find_path_sum(node *tree, int sum) {
    int path_sum;
    if (tree == NULL) {
        return path_sum;
    }
    return path_sum = find_path_sum(tree->left, sum) + tree->data;
}

// ADD A LOOP ATTEMPT HERE

void free_tree(node *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}
