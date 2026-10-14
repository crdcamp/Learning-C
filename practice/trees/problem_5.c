#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *new_node(int data);
node *insert_node(node *tree, int data);
void print_sorted_tree(node *tree);
int *sort_tree(node *tree);
void free_tree(node *tree);

// Given a binary tree, iterate over the nodes to print them out
// in increasing order
// Hint: The strategy is to recur left, print the node data, recur right
// Example: 1, 2, 3, 4, 5
int main(void) {
    // Create ze tree
    node *root = NULL;
    int input_array[] = {4, 2, 1, 3, 5};
    int input_array_len = sizeof(input_array) / sizeof(input_array[0]);
    for (int i = 0; i < input_array_len; i++) {
        root = insert_node(root, input_array[i]);
    }

    print_sorted_tree(root);


    // Personal challenge: assign to result to a new array
    // // Create and print the array of the sorted `int`s
    // int *sorted_tree = malloc(input_array_len * sizeof(int));
    // sorted_tree = sort_tree(root);
    // for (int i = 0; i < input_array_len; i++) {
    //     printf("%i ", sorted_tree[i]);
    // }

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

void print_sorted_tree(node *tree) {
    if (tree == NULL) {
        return;
    }

    // Recurse left and print
    printf("Left value = %i\n", tree->data);
    print_sorted_tree(tree->left);
    print_sorted_tree(tree->right);
}

// int *sort_tree(node *root) {

// }

void free_tree(node *tree) {
    if (tree != NULL) {
        free_tree(tree->left);
        free_tree(tree->right);
        free(tree);
    }
}
