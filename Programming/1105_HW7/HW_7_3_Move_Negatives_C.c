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

int main() {
    // n: 輸入總數, tmp: 輸入陣列用暫存、is_first: 是否為第一個數字
    int n, tmp, is_first=1;
    scanf("%d", &n);
    int positive[n], negative[n];
    int cnt_positive = 0, cnt_negative = 0; // 正、負數的個數計數

    for(int i = 0; i < n; i++) {
        // 輸入陣列
        scanf("%d", &tmp);
        if(tmp >= 0) {
            positive[cnt_positive++] = tmp; // 正數放進正數陣列
        } else {
            negative[cnt_negative++] = tmp; // 負數放進負數陣列
        }
    }

    // 輸出
    printf("{"); 
    for(int i = 0; i < cnt_positive;i++) {
        // 印正數
        if(is_first == 0) {
            printf(", "); // 如果不是第一個，就印前綴的空格
        }
        printf("%d", positive[i]);
        is_first = 0; // 輸出過改變狀態
    }
    
    for(int i = 0; i < cnt_negative;i++) {
        // 印負數
        if(is_first == 0) {
            printf(", "); // 如果不是第一個，就印前綴的空格
        }
        printf("%d", negative[i]);
        is_first = 0; // 輸出過改變狀態
    }
    
    printf("}\n");
    return 0;
}