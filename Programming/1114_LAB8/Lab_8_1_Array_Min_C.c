/*Date: 2025/11/9
Author: 黃鈺翔
Description: find minimum value in an array
Using github copilot to write comments
*/

#include<stdio.h>

int arrayMin(const int intArray[], int arraySize) {
    int min = __INT_MAX__; // 初始化為整數最大值
    for(int i = 0; i < arraySize; i++) {
        if(intArray[i] < min) {
            min = intArray[i]; // 如果當前元素小於min，更新min
        }
    }
    return min; // 回傳最小值
}

int main() {
    int n;
    scanf("%d", &n); // 輸入陣列大小
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // 輸入陣列元素
    }
    printf("%d", arrayMin(arr, n)); // 輸出最小值
    return 0;
}