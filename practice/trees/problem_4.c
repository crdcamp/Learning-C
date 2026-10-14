#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *new_node(int data);
node *insert_node(node *root, int data);
int find_tree_min_recursive(node *tree_node);
int find_tree_min_loop(node *tree_node);
void free_tree(node *root);

// Given a non-empty binary search tree, return the minimum data
// value found in that tree. Note that it's not necessary to search
// the entire tree. This can be solved with recursion or a simple
// while loop
int main(void) {
    node *root = NULL;
    int input_array[] = {4, 2, 1, 3, 5};
    int input_array_len = sizeof(input_array) / sizeof(input_array[0]);
    for (int i = 0; i < input_array_len; i++) {
        root = insert_node(root, input_array[i]);
        // Not even bothering inputting my crappy error handling this time
    }

    int tree_min_recursive = find_tree_min_recursive(root);
    printf("Tree min (recursive) = %i\n", tree_min_recursive);

    int tree_min_loop = find_tree_min_loop(root);
    printf("Tree min (loop) = %i\n", tree_min_loop);

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

int find_tree_min_recursive(node *tree_node) {
    if (tree_node->left == NULL) {
        return tree_node->data;
    }

    // All ya gotta do is recurse all the way down the
    // leftmost side of the tree
    int tree_min = find_tree_min_recursive(tree_node->left);
    return tree_min;

}

int find_tree_min_loop(node *tree_node) {
    while (tree_node->left != NULL) {
        tree_node = tree_node->left;
    }
    return tree_node->data;
}

void free_tree(node *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}
