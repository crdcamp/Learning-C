#include <stdio.h>

int find_largest_index(int array[], int index, int length);

// Write a program in C to get the largest index of an array using recursion.
int main(void) {
    int array[] = {5, 10, 15, 20, 25};
    int length = sizeof(array) / sizeof(array[0]);
    find_largest_index(array, 0, length);
}

int find_largest_index(int array[], int index, int length) {
    if (index == length) {
        return 0;
    }
    else {}

    return find_largest_index(array, index < index + 1, length);
}
