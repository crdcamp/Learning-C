#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *new_node(int data);
node *custom_tree();

int main(void) {
    node *root = custom_tree();



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
