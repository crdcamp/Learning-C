#include <stdio.h>

int sum_digits_loop(int integer);
int sum_digits_recursion(int integer);

// Write a program in C to find the sum of digits of a number using recursion.
int main(void) {
    int integer = 25;
    printf("Original integer: %i\n", integer);

    int digit_sum_loop = sum_digits_loop(integer);
    printf("Loop result: %i\n", digit_sum_loop);

    int digit_sum_recursion = sum_digits_recursion(integer);
    printf("Recursion result: %i\n", digit_sum_recursion);

    return 0;
}

int sum_digits_loop(int integer) {
    int digit;
    int sum = 0;
    do {
        digit = integer % 10;
        sum += digit;
        integer /= 10;
    }
    while (integer != 0);
    return sum;
}

int sum_digits_recursion(int integer) {
    if (integer != 0) {
        return integer;
    }

    return integer + sum_digits_recursion(integer % 10);
}
