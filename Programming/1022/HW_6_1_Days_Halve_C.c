/*Date: 2025/10/22
Author: 黃鈺翔
Description: Calculate the number of days until the length is less than 5 by halving each day.
Using github copilot to write comments
*/

#include<stdio.h>

int times;

int daysHalve(double length) {
    if (length / 2 < 5) {
        // Base case，回傳最終的次數
        return times;
    }

    // Recursive case，長度減半並增加次數
    times++; 
    return daysHalve(length / 2);
}

int main() {
    int length;
    scanf("%d", &length);

    if(length <= 0) {
        // 輸入非正整數
        printf("%d", 0);
        return 0;
    }

    // 正確輸入，開始處理
    times = 1;
    printf("%d", daysHalve(length));
    return 0;
}