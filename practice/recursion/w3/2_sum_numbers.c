#include <stdio.h>

int sum_all_numbers(int start, int end);

// Write a program in C to calculate the sum of numbers from 1 to n using recursion.
int main(void) {
    int sum = sum_all_numbers(1, 5);
    printf("%i", sum);
    return 0;
}

int sum_all_numbers(int start, int end) {
    if (start > end) {
        return 0;
    }
    return start + sum_all_numbers(start + 1, end);
}
