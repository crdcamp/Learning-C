#include <stdio.h>

int sum_numbers(int n);

// Write a program in C to calculate the sum of numbers from 1 to n using recursion.
int main(void) {
    sum_numbers(5);
    return 0;
}

int sum_numbers(int n) {
    int result;
    // Define base case
    if (n == 1) {
        return 1;
    }
    else {
        result = n + sum_numbers(n - 1);
    }
    return result;
}
