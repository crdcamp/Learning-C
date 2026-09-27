#include <stdio.h>

int sum_digits_loop(int integer);
int sum_digits_recursion(int integer);

// Write a program in C to find the sum of digits of a number using recursion.
int main(void) {
    int integer = 25;

    printf("Loop result:\n");
    int digit_sum_loop = sum_digits_loop(integer);

    printf("Recursion result:\n");
    int digit_sum_recursion = sum_digits_recursion(integer);

    return 0;
}

int sum_digits_loop(int integer) {
    printf("Original integer: %i\n", integer);
    int digit;
    int sum = 0;
    do {
        digit = integer % 10;
        sum += digit;
        printf("Digit: %i\n", digit);
        integer /= 10;
    }
    while (integer != 0);

    printf("Sum of digits: %i\n", sum);
    return sum;
}

int sum_digits_recursion(int integer) {

}
