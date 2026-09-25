#include <stdio.h>
#include <stdlib.h>

// Write a program in C to insert a node in the middle of a Singly Linked List.

typedef struct node {
    int integer;
    struct node *next_node;
} node;

node *create_list(int length);
void print_list(char *message, node *list);
node *sort_list(node *list);
int get_list_length(node *list);
void insert_middle(node *list);
void free_list(node *list);

int main(void) {
    // Now we're gonna work with multiple lengths just to
    // be absolutely certain we're doing this right
    int list_lengths[] = {5, 7, 10};
    int list_lengths_length = sizeof(list_lengths) / sizeof(list_lengths[0]);
    node *lists[list_lengths_length] = {};

    // Populate three different linked lists with different amounts of data
    for (int i = 0; i < list_lengths_length; i++) {
        lists[i] = create_list(list_lengths[i]);
        printf("List %i: ", i + 1);
        print_list("", lists[i]);
    }

    for (int i = 0; i < list_lengths_length; i++) {
        printf("List %i ", i + 1);
        insert_middle(lists[i]);
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

void insert_middle(node *list) {
    int list_length = get_list_length(list);
    int middle_index = list_length / 2;
    printf("middle index: %i\n", middle_index);
}
