#include <stdio.h>
#include <stdlib.h>

void print(int *arr) {
    printf("%p\n", arr);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d\n", arr[i*2+j]);
        }
    }
}

int main() {
    // int arr[2][2] = {{1, 2}, {3, 4}};
    // int arr[2][2] = {1 ,2 ,3 ,4};
    int arr[2][2] = {4, 3, 2, 1};
    int* ptr = *arr;
    printf("%p\n%p\n%p\n", arr, &arr, ptr);
    print(ptr);
}