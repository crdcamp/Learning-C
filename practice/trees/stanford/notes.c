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
