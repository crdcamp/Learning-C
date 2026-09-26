#include <stdio.h>

int fibonacci(int n);

// Write a program in C to print the Fibonacci Series using recursion.
int main(void){
    int result = fibonacci(10);
    printf("Result: %i\n", result);
    return 0;
}

int fibonacci(int n) {
    int i = 1;
    int result;

    // Fibonacci has multiple base cases. Let's define them
    if (n == 0) {
        i = 0;
    }
    if (n == 1) {
        i = 1;
    }
    if (i <= n) {
        int i = fibonacci(i + (i - 2) + (i - 1));
    }

    return i;
}
