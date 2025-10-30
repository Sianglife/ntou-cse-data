/*Date: 2025/10/15
Author: 黃鈺翔
Description: build a program to determine perfect number
Using github copilot to write comments
*/

#include<stdio.h>
#include<math.h>

int find_factor_sum(int n, int divider, int sum) {
    // 從2遞迴到小於根號n，如果能整除就累加
    if (divider >= sqrt(n)) {
        // 遞迴終止條件: 除數大於等於根號n
        return sum;
    }

    // 判斷是否整除
    if (n % divider == 0) {
        if (divider * divider == n) {
            // 如果是平方數，只加一次
            sum += divider;
            return find_factor_sum(n, divider+1, sum);
        }
        // 如果不是平方數，累加兩個因數
        sum += divider;
        sum += n / divider;
        return find_factor_sum(n, divider+1, sum); // 遞迴下一次
    }

    // 如果無法整除，直接下一次遞迴
    return find_factor_sum(n, divider+1, sum);  
}

int determinePerfectNumber(int n) {
    // 一組因數的和
    int sum;
    sum = find_factor_sum(n, 2, 0) + 1;
    if(n == sum) {
        return 1;
    } else if (n < sum) {
        return -1;
    } else if (n > sum) {
        return 0; 
    }
}

int main() {
    int n, cnt; // n: 輸入的數字, cnt: 測試組數
    scanf("%d", &cnt); // 輸入測試組數
    while(cnt--) {
        // 處理每一次輸入
        scanf("%d", &n);
        printf("%d\n", determinePerfectNumber(n));
    }
    return 0;
}

