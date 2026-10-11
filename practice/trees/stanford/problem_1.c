#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *new_node(int data);
node *insert_node(node *tree, int data);

// Write code that builds a binary tree with the values 1, 2, and 3
// Write the code in three different ways:
// by calling new_node three times, and using three pointer variables
// by calling new_node three times, and using only one pointer variable
// by calling insert three times passing it the root pointer to build the tree
int main(void) {
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


}
