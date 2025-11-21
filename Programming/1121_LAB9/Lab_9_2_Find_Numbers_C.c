/*Date: 2025/11/21
Author: 黃鈺翔
Description: Finding missing numbers from 1 to n in an array
Using github copilot to write comments
*/
#include<stdio.h>
#include<stdlib.h>

void findNumbers(int intArray[], int arraySize) {
    // 開一個陣列標記出現過的數字
    int *used = calloc(arraySize+2, sizeof(int)); 
    for(int i = 0; i < arraySize; i++) {
        used[intArray[i]] = 1; // 標記出現過的數字
    }
    // 用來控制輸出空格，儲存是否為第一個輸出
    int isFirst = 1; 
    for(int i = 1; i <= arraySize; i++) {
        if (!isFirst && !used[i]) {
            printf(" "); // 不是第一個輸出時，先輸出空格
        }
        if (!used[i]) {
            printf("%d", i);
            // 輸出後將isFirst設為已輸出狀態
            isFirst = 0; 
        }
    }
    free(used); // 釋放used的記憶體
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    findNumbers(arr, n);
    return 0;
}