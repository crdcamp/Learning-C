#include <stdio.h>

void print_natural_numbers(int start, int end);

// Write a program in C to print the first 50 natural numbers using recursion.
int main(void) {
    print_natural_numbers(1, 50);
    printf("\n");
    return 0;
}

void print_natural_numbers(int start, int end) {
    if (start < end) {
        printf(" %i", start);
        print_natural_numbers(start + 1, end);
    }
}
