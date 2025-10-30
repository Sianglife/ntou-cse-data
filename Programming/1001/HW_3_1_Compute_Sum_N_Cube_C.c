/*Date: 2025/10/1
Author: 黃鈺翔
Description: calculate the sum of third power to the user given number
Using github copilot to write comments
*/
#include <stdio.h>

int computeSumNCube(int n) {
     int sum = 0; // 累加用的變數
    if (n <= 0) {
        return -1;
    }
    for (int i=1; i<=n; i++) {
        if (i == 1) {
            // 如果是1次方，三次方也是1，直接加
            sum += 1;
            continue; // 跳過後續1不用的計算
        }
        sum += i * i * i; // 三次方
    }
    return sum; // 累加完畢回傳結果
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", computeSumNCube(n)); // 將使用者輸入的數字傳給函式並印出結果
    return 0;
}