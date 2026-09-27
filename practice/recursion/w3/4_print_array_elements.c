#include <stdio.h>

void print_array_elements(int array[], int length);

// Write a program in C to print the array elements using recursion.
int main(void) {
    int array[] = {2, 4, 6, 8, 10, 12};
    int length = sizeof(array) / sizeof(array[0]);
    print_array_elements(array, length);
    return 0;
}

void print_array_elements(int array[], int length) {

}
