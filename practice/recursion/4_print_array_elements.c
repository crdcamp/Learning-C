#include <stdio.h>

void print_array(int array[], int length);

int main(void) {
    int array[] = {2, 4, 6, 8, 10, 12};
    int length = sizeof(array) / sizeof(array[0]);
    print_array(array, length);

    return 0;
}

void print_array(int array[], int length) {

}
