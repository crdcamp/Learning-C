#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int integer;
    struct node *next_node;
} node;

node *create_list(int length);
void print_list(char *message, node *list);
node *sort_list(node *list);
int get_list_length(node *list);
node *insert_middle(node *list, int value_to_insert);
void free_list(node *list);

// Write a program in C to insert a node in the middle of a Singly Linked List.
int main(void) {
    // Now we're gonna work with multiple lengths just to
    // be absolutely certain we're doing this right
    int list_lengths[] = {5, 7, 10};
    int list_lengths_length = sizeof(list_lengths) / sizeof(list_lengths[0]);
    node *lists[list_lengths_length] = {};

    // Populate three different linked lists with different amounts of data
    printf("BEFORE INSERTING MIDDLE VALUE:\n");
    for (int i = 0; i < list_lengths_length; i++) {
        lists[i] = create_list(list_lengths[i]);
        printf("List %i: ", i + 1);
        print_list("", lists[i]);
    }

    printf("AFTER INSERTING MIDDLE VALUE:\n");
    for (int i = 0; i < list_lengths_length; i++) {
        printf("List %i: ", i + 1);
        node *list = insert_middle(lists[i], 676967);
        if (list == NULL) {
            return 1;
        }
        print_list("", lists[i]);
    }

    return 0;
}

node *create_list(int length) {
    node *list = NULL;
    for (int i = 0; i < length; i++) {
        node *n = malloc(sizeof(node));

        if (n == NULL) {
            printf("Error allocating memory when creating list\n");
            while (list != NULL) {
                node *tmp = list;
                list = n->next_node;
                free(tmp);
            }
            return NULL;
        }

        n->integer = i + 1;
        n->next_node = list;
        list = n;
    }
    return list;
}

void print_list(char *message, node *list) {
    printf("%s", message);
    node *ptr = list;
    while(ptr != 0) {
        printf("%i ", ptr->integer);
        node *next_node = ptr->next_node;
        ptr = next_node;
    }
    printf("\n");
}

// Completely unnecessary, as the list length is already defined in
// `lists[]`, but this is something I'd need to do if the list lengths
// were never defined, which is going to almost always be the case
int get_list_length(node *list) {
    int list_length = 0;
    node *ptr = list;
    while (ptr != NULL) {
        list_length++;
        node *next_node = ptr->next_node;
        ptr = next_node;
    }

    return list_length;
}

node *insert_middle(node *list, int value_to_insert) {
    // Get the length of the list
    int list_length = get_list_length(list);
    // Find the middle index
    int middle_index = list_length / 2;

    // No need for a `while` loop here. Just iterate with a `for` loop
    // until you reach the middle index
    node *current_node = list;
    for (int i = 0; i < middle_index - 1; i++) {
        // Iterate until you reach the middle
        current_node = current_node->next_node;
    }
    // Allocate memory for `value_to_insert`
    node *middle_node = malloc(sizeof(node));
    if (middle_node == NULL) {
        printf("Error when assigning memory for middle index\n");
        return NULL;
    }

    // Insert `value_to_insert` into `middle_node`
    middle_node->integer = value_to_insert;
    // Tie `middle_node` to the next node
    middle_node->next_node = current_node->next_node;
    // Tie previous node to middle node
    current_node->next_node = middle_node;

    return list;
}
