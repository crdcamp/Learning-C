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
void free_tree(node *root);
void print_all_sections(char section);

// Write code that builds a binary tree with the values 1, 2, and 3
// Write the code in three different ways:
// a) by calling new_node three times using three pointer variables
// b) by calling new_node three times using only one pointer variable
// c) by calling insert three times passing it the root pointer to build the tree
int main(void) {
    // Create the root
    node *root = NULL;

    // Input array for section C
    int tree_data[] = {2, 1, 3};
    int tree_data_len = sizeof(tree_data) / sizeof(tree_data[0]);

    // a) Call new_node three times using three pointer variables
    node *node1 = new_node(1);
    node *node2 = new_node(2);
    node *node3 = new_node(3);

    free(node1);
    free(node2);
    free(node3);

    // b) Call new_node three times using only one pointer variable
    for (int i = 0; i < tree_data_len; i++) {
        node *single_pointer = new_node(tree_data[i]);
        free(single_pointer);
    }

    // c) Call insert three times passing it the root pointer to build the tree
    for (int i = 0; i < tree_data_len; i++) {
        root = insert_node(root, tree_data[i]);
    }
    print_tree(root, 4);
    free_tree(root);
    root = NULL;

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

void free_tree(node *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}
