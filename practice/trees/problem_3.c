#include <stdio.h>
#include <stdlib.h>
typedef struct node {

    struct node *left;
    int data;
    struct node *right;
} node;

node *new_node(int data);
node *insert_node(node *new_node, int data);
int max_depth(node *tree_node);
void print_tree(node *root, int level);
void free_tree(node *root);

// Given a binary tree, compute its "max depth" - the number of nodes
// along the longest path from the root node down to the farthest leaf
// node.
int main(void) {
    // Create the tree
    node *root = NULL;
    int input_array[] = {4, 2, 1, 3, 5, 6, 7, 8, 9};
    int input_array_len = sizeof(input_array) / sizeof(input_array[0]);
    for (int i = 0; i < input_array_len; i++) {
        root = insert_node(root, input_array[i]);
        // Still using insufficient error handling for tree creation
        // We'll work on that after we've completed all problems
        if (root == NULL) {
            printf("Error allocating memory\n");
            return 0;
        }
    }

    print_tree(root, 4);

    int depth = max_depth(root);
    printf("Max depth = %i\n", depth);

    free_tree(root);

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

void print_tree(node *root, int level) {
        if (root == NULL)
                return;
        for (int i = 0; i < level; i++)
                printf(i == level - 1 ? "|-" : "  ");
        printf("%d\n", root->data);
        print_tree(root->left, level + 1);
        print_tree(root->right, level + 1);
}

int max_depth(node *tree_node) {
    if (tree_node == NULL) {
        return 0;
    }

    // This time you need to initialize variables
    // You initially thought these would get overwritten, but they don't!
    int max_left = max_depth(tree_node->left);
    int max_right = max_depth(tree_node->right);

    if (max_left > max_right) {
        return max_left + 1;
    }
    else {
        return max_right + 1;
    }
}

void free_tree(node *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}
