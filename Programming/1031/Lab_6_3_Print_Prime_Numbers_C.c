/*Date: 2025/10/31
Author: 黃鈺翔
Description: print prime numbers between given range
Using github copilot to write comments
*/

#include <stdio.h>

int isPrimeNumber(unsigned int x) {
    int divisor = x-1; //除數
    // 如果 x 等於 1，回傳 0
    if(x == 1)
        return 0;
    // 檢查 x-1 至 2 有無整數 可整除 x
    while(divisor > 1) {
        if (x % divisor == 0) {
            return 0;
        }
        divisor -= 1;
    }
    return 1;
}

void printPrimeNumbers(unsigned int min, unsigned int max) {
    unsigned int i;
    int cnt = 0; // 算到的質數數量
    for (i = min; i <= max; i++) {
        // 從min到max檢查質數
        if (isPrimeNumber(i)) { // 符合質數條件
            if(cnt % 5 == 0 && cnt != 0) {
                printf("\n"); // 每行第五個字後的換行
            } else if (cnt != 0) {                
                printf(" "); // 每行字之間的空格
            }
            cnt++; 
            printf("%u", i);
        }
    }
    printf("\nPrime Number Total: %d\n", cnt);
}

int main() {
    unsigned int min, max;
    scanf("%u %u", &min, &max);
    printPrimeNumbers(min, max);
    return 0;
}