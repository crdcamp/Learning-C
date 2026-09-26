#include <stdio.h>

void print_natural(int start, int end);

// Write a program in C to print the first 50 natural numbers using recursion.
int main(void) {
    print_natural(1, 50);
    return 0;
}

void print_natural(int start, int end) {
    if (start <= end) {
        printf(" %i", start);
        print_natural(start + 1, end);
    }
}
