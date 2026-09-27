#include <stdio.h>

int find_largest_element(int array[], int element, int length);

// Write a program in C to get the largest element of an array using recursion.
int main(void) {
    int array[] = {5, 10, 15, 20, 25};
    int length = sizeof(array) / sizeof(array[0]);
    int largest_element = find_largest_element(array, 0, length);
    printf("Largest element: %i\n", largest_element);
    return 0;
}

int find_largest_element(int array[], int element, int length) {
    int largest_element = array[0];
    if (element >= length) {
        return largest_element;
    }
    return find_largest_element(array[element] > )
}
