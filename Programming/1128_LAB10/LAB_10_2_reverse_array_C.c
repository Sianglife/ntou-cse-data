/*Date: 2025/11/28
Author: 黃鈺翔
Description: reverse array
Using github copilot to write comments
*/
#include<stdio.h>

void swap(int *a, int *b) {
    // Swap the values at the two given pointers
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void reverse_array(int *intArray, int arraySize) {
    int mid = arraySize / 2; // Calculate the midpoint of the array
    for(int i = 0; i < mid; i++) {
        // Swap until the midpoint is reached
        swap(intArray + i, intArray + arraySize - i - 1);
    }
}

void print_array(int *intArray, int arraySize) {
    // Print the elements of the array
    for(int i = 0; i < arraySize; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", *(intArray + i));
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n]; // Declare an array of size n
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    reverse_array(arr, n); // Call the reverse function
    print_array(arr, n); // Call the print function
    return 0;
}