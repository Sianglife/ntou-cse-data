/*Date: 2025/11/28
Author: 黃鈺翔
Description: transform array
Using github copilot to write comments
*/
#include<stdio.h>

// Test Functions
int square(int x) {
    return x * x;
}

int double_value(int x) {
    return x * 2;
}

// Transform Function
void transform_array(int* intArray, int arraySize, int (*func)(int)) {
    for(int i = 0; i < arraySize; i++) {
        // Call the function pointer on each element
        intArray[i] = func(intArray[i]); 
    }
}

void print_array(int intArray[], int arraySize) {   
    // Print the elements of the array 
    for(int i = 0; i < arraySize; i++) {
        if (i > 0) {
            // Print space between elements
            printf(" ");
        }
        printf("%d", intArray[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
     // Declare two arrays of size n
    int arr1[n]; // For square
    int arr2[n]; // For double
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]); // Input elements for arr1
        arr2[i] = arr1[i]; // Copy elements to arr2
    }
    transform_array(arr1, n, square); // Call square via transform
    print_array(arr1, n); // Print squared array
    printf("\n");
    transform_array(arr2, n, double_value); // Call double via transform
    print_array(arr2, n); // Print doubled array
    return 0;
}