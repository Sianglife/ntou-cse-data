/*Date: 2025/12/07
Author: 黃鈺翔
Description: Generate number chain until repetition
Using github copilot to write comments
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 給qsort用的比較函式，將字元由大到小排序
int cmpCharLower(const void *c1, const void *c2) {
    const char *c1_ptr = c1;
    const char *c2_ptr = c2;
    return *c2_ptr - *c1_ptr;
}

// 給qsort用的比較函式，將字元由小到大排序
int cmpCharUpper(const void *c1, const void *c2) {
    const char *c1_ptr = c1;
    const char *c2_ptr = c2;
    return *c1_ptr - *c2_ptr;
}

// 將整數的字元由大到小排列後回傳新的整數
int lower(int a) {
    char str[200]; // 暫存整數的字串
    int result; // 排序後的結果
    sprintf(str, "%d", a); // 將整數轉成字串，方便每個字元的排序
    qsort(str, strlen(str)+1, sizeof(char), cmpCharLower); // 使用qsort讓字串排序
    sscanf(str, "%d", &result); // 將排序後的字串轉回整數
    return result;
}

// 將整數的字元由小到大排列後回傳新的整數
int upper(int a) {
    // 與lower()同理
    char str[200];
    int result;
    sprintf(str, "%d", a);
    qsort(str, strlen(str), sizeof(char), cmpCharUpper);
    sscanf(str, "%d", &result);
    return result;
}

int main() {
    int n, low, up;
    int tmp, last, len;
    printf("Sample Output "); // 輸出最前面神奇標題
    while(scanf("%d", &n) && n) { // 輸入整數直到輸入0結束
        len = 1; // 數字鏈長度初始值為1
        printf("Original number was %d\n", n); // 輸出原始數字
        last = -1; // 上一個數字鏈的值，初始為-1，輸入為正數不可能相等
        tmp = n; // 目前數字鏈的值
        while(1) {
            // 計算下一個數字鏈的值
            low = lower(tmp); // 將目前數字鏈的值字元由大到小排列後回傳新的整數
            up = upper(tmp); // 將目前數字鏈的值字元由小到大排列後回傳新的整數
            tmp = low - up; // 下一個數字鏈的值為兩者相減
            printf("%d - %d = %d\n", low, up, tmp); // 輸出目前的數字鏈計算過程
            if(tmp == last) {
                // 如果目前的數字鏈值與上一個相同，表示開始重複，結束迴圈
                break;
            }
            last = tmp; // 如果沒有重複，更新上一個數字鏈的值
            len++; // 數字鏈長度加1
        }
        printf("Chain length %d\n", len); // 輸出數字鏈長度
    }
    return 0;
}