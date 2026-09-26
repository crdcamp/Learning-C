#include <stdio.h>

void numPrint(int n);

// Write a program in C to print the first 50 natural numbers using recursion.
int main(void) {
    numPrint(1);
    return 0;
}

void numPrint(int n) {
    if(n<=50)
    {
         printf(" %d ",n);
         numPrint(n+1);
    }
}
