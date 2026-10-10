#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// A binary search tree or ordered binary tree is a type of binary
// tree where the nodes are arranged in order.

// For each node, all elements in its left subtree are less-or-equal
// to the node, and all the elements in its right subtree are
// greater than the node.

// Typical binary tree code in C
// We begin with a basic tree struct followed by a lookup and insert
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

static int lookup(struct node *node, int target);
struct node *NewNode(int data);
node *insert(node *tree, int data);

// Search a binary tree to see if it contains the target value
// Deal with the base case where the tree is empty
// Deal with the current node
// Use recursion to deal with the subtrees
// We use static because we want the variable to be the same between recursive calls
static int lookup(struct node *node, int target) {
    // Base case == empty tree
    // In that case, the target isn't found to return false
    if (node == NULL) {
        return(false);
    }
    if (target == node->data) {
        return (true);
    }
    else if (target < node->data) {
        return lookup(node->left, target);
    }
    else return lookup(node->right, target);
}

// POINTER CHANGING CODE
// What if a function needs to change one of the pointer parameters
// passed to it? For example, an `insert()` function may want to
// We can use pointers to pointers (aka "reference parameters")
// But, we're gonna use a simpler technique that a function that
// wishes to change a pointer passed to it will return the new value
// of the pointer to the caller. The caller is responsible for using
// the new value

// Suppose we have  a `change()` function that may change the
// root, then a call to `change()` will look like this:
// root = change(root);

// We take the value returned by `change()` and use it a the new
// value for root.

// INSERT
// `insert()` returns the new tree pointer to use to its caller
struct node *NewNode(int data) {
    node *new_node = malloc(sizeof(node));

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// Now we can create the insert function
node *insert(node *tree, int data) {
    // If the tree is empty, return a new, single node
    if (tree == NULL) {
        return NewNode(data);
    }

    // Otherwise, recur down the tree (this allows for duplicates)
    if (data <= tree->data) {
        tree->left = insert(tree->left, data);
    }
    else if (data >= tree->data) {
        tree->right = insert(tree->right, data);
    }

    return tree;
}
