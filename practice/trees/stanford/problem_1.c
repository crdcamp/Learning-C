#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *new_node(int data);
node *insert_node(node *tree, int data);
void print_tree(node *root, int level);

// Write code that builds a binary tree with the values 1, 2, and 3
// Write the code in three different ways:
// a) by calling new_node three times, and using three pointer variables
// b) by calling new_node three times, and using only one pointer variable
// c) by calling insert three times passing it the root pointer to build the tree
int main(void) {
    // Create the root
    node *root = NULL;

    // a) Call new_node three times, and using three pointer variables

    // b) Call new_node three times, and using only one pointer variable

    // c) Call insert three times passing it the root pointer to build the tree
    int tree_data[] = {1, 2, 3};
    int tree_data_len = sizeof(tree_data) / sizeof(tree_data[0]);

    for (int i = 0; i < tree_data_len; i++) {
        root = insert_node(root, tree_data[i]);
    }

    print_tree(root, 4);

    return 0;
}

// We first need to make a `create_node` function
node *new_node(int data) {
    // First, we need to allocate memory for the new node
    node *new_node = malloc(sizeof(node));

    // Now, we need to populate new_node with the data and
    // fill left and right with NULL
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// Now we need a function to insert the new node into the tree
node *insert_node(node *tree, int data) {
    // If the tree is empty, return a new node
    if (tree == NULL) {
        return new_node(data);
    }

    // Less-than case
    if (data <= tree->data) tree->left = insert_node(tree->left, data);
    // More-than case
    else if (data >= tree->data) tree->right = insert_node(tree->right, data);

    return tree;
}

void print_tree(node *root, int level)
{
        if (root == NULL)
                return;
        for (int i = 0; i < level; i++)
                printf(i == level - 1 ? "|-" : "  ");
        printf("%d\n", root->data);
        print_tree(root->left, level + 1);
        print_tree(root->right, level + 1);
}
