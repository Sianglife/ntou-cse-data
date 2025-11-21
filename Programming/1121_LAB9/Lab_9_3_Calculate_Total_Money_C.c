/*Date: 2025/11/21
Author: 黃鈺翔
Description: Calculating total money based on lucky numbers and given arrays
Using github copilot to write comments
*/
#include<stdio.h>

int isInArray(int value, int arr[], int size) {
    // 如果存在陣列中回傳索引值，否則回傳-1
    for(int i = 0; i < size; i++) {
        if(arr[i] == value) {
            return i; // 存在陣列中，回傳索引值
        }
    }
    return -1; // 不存在陣列中
}

int calculateTotalMoney(int lucky[], int num[], int money[], int arraySize_1, int arraySize_2) {
    int total = 0;
    int tmp;
     // 檢查第一個幸運號碼是否在num陣列中
    tmp = isInArray(lucky[0], num, arraySize_2);
    if(tmp != -1) {
        // 存在則加上對應的money值
        total += money[tmp];
    }

    // 檢查第二個幸運號碼是否在num陣列中
    tmp = isInArray(lucky[1], num, arraySize_2); 
    if(tmp != -1) {
        // 存在則加上對應的money值
        total += money[tmp]; 

    }

    // 檢查第三個幸運號碼是否在num陣列中
    tmp = isInArray(lucky[2], num, arraySize_2);
    if(tmp != -1) {
        // 如果存在則扣除對應的money值
        total -= money[tmp]; 
    } else {
        // 如果不存在則將total加倍
        total *= 2;
    }
    if(total < 0) {
        // 如果total小於0則歸零
        total = 0;
    }
    return total;
}

int main() {
    int lucky[3];
    int num[5];
    int money[5];
    for(int i = 0; i < 3; i++) {
        scanf("%d", &lucky[i]);
    }
    getchar(); // 吃掉換行符號
    for(int i = 0; i < 5; i++) {
        scanf("%d", &num[i]);
    }
    getchar(); // 吃掉換行符號
    for(int i = 0; i < 5; i++) {
        scanf("%d", &money[i]);
    }
    printf("%d", calculateTotalMoney(lucky, num, money, 3, 5));
    return 0;
}