/*Date: 2025/11/06
Author: 黃鈺翔
Description: 將負數移至到陣列最後面，但保留其他非負數元素相對順序
*/

#include<stdio.h>

void swap(int *a, int *b) {
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

void moveNegatives(int intArray[], int arraySize) {
    // tmp: 輸入陣列用暫存、is_first: 是否為第一個數字
    int tmp, is_first=1;
    int positive[arraySize], negative[arraySize];
    int cnt_positive = 0, cnt_negative = 0; // 正、負數的個數計數
    for(int i = 0; i < arraySize; i++) {
        // 轉換陣列，分為正負
        tmp = intArray[i];
        if(tmp >= 0) {
            positive[cnt_positive++] = tmp; // 正數放進正數陣列
        } else {
            negative[cnt_negative++] = tmp; // 負數放進負數陣列
        }
    }
    int i;
    for(i = 0; i < cnt_positive;i++) {
        // 重新置入正數
        intArray[i] = positive[i];
    }    
    for(i = 0; i < cnt_negative;i++) {
        // 重新置入負數
        intArray[i+cnt_positive] = negative[i];
    }
}

int main() {
    int n;
    // 讀入總數
    scanf("%d", &n);
    int arr[n];
    // 輸入陣列
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }     
    moveNegatives(arr, n); // 呼叫函式
    // 輸出
    printf("{");
    for(int i = 0; i < n; i++) {
        if (i != 0) {
            printf(", "); // 逗號
        }
        printf("%d", arr[i]);
    }
    printf("}");
    return 0;
}