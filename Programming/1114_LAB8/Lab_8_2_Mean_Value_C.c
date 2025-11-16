/*Date: 2025/11/14
Author: 黃鈺翔
Description: mean value calculation
Using github copilot to write comments
*/

#include<stdio.h>

void swap(int *a, int *b) {
    // 交換兩指標的值
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int arr[], int n) {
    /* 兩兩比較、較大的往後移或較小
    的往前移，像氣泡一樣浮上去。 */
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int getMedian(int intArray[], int arraySize) {
    // 輸入已排序的陣列，回傳中位數
    if (arraySize % 2 == 1) {
        return intArray[arraySize / 2];
    } else {
        return (intArray[arraySize / 2] + intArray[arraySize / 2 - 1]) / 2;
    }
}

void printArray(int arr[], int size) {
    // 輸出陣列內容
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[200000]; // 最大輸入數量不超過200000
    int n; // 陣列大小

    // 輸入
    scanf("%d", &n);    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 輸出原始陣列
    printf("Before sorting:\n");
    printArray(arr, n);

    bubbleSort(arr, n);    // 對陣列進行排序
    // 輸出排序後陣列
    printf("After sorting:\n");    
    printArray(arr, n);
    
    // 輸出中位數
    printf("Median : ");
    printf("%d", getMedian(arr, n));
    return 0;
}