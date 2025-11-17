/*Date: 2025/11/14
Author: 黃鈺翔
Description: 
Using github copilot to write comments
*/
#include<stdio.h>

void swap(int *a, int *b) {
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void sortFruits(int arr[], size_t size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int n = 0;
    int arr[1000];
    while(scanf("%d", &arr[n]) == 1) {
        n++;
    }
    sortFruits(arr, n);

    printf("[");
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            printf("%d ", arr[i]);
        } else {
            printf("%d", arr[i]);
        }
    }
    printf("]");

    return 0;
}