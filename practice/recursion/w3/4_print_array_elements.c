#include <stdio.h>

void print_array_elements(int array[], int element, int length);

// Write a program in C to print the array elements using recursion.
int main(void) {
    int array[] = {2, 4, 6, 8, 10, 12};
    int length = sizeof(array) / sizeof(array[0]);
    print_array_elements(array, 0, length);
    return 0;
}

void print_array_elements(int array[], int element, int length) {

    if (element > length) {
        return;
    }

    printf("Element %i = %i\n", element, array[element]);
    print_array_elements(&array[element], element + 1, length);
}
