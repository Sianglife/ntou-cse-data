/*Date: 2025/10/11
Author: 黃鈺翔
Description: solve N such that input = N + M, where M is N without its last digit
Using github copilot to write comments
*/

#include<stdio.h>
#define INT_MAX 2147483647

int N2M(int n) {
    // 去尾數
    n = n / 10;
    return n;
}

int genUpper10(int n, int base) {
    // 產生比n大，且除了第一位都是0的數字
    int tmp;

    if ((n - (n % base)) == 0) {
        // 如果已經到達最高位數就回傳
        return n;
    }

    
    if (n % base == 0) {
        // 如果尾數已是0就直接繼續下一位數
        return genUpper10(n, base * 10);
    }

    // 一般情況下，將尾數歸0並進位
    tmp = n / base;
    tmp = (tmp + 1) * base; 
    return genUpper10(tmp, base * 10);
}

void solveN(unsigned int mystry) {
    int n, m, is_first = 1; // is_first用來判斷是否為第一個輸出，避免多空格
    for(n = 10; n < mystry * 10; n++) { // n從10開始，跑到mystry*10已足夠找解
        m = N2M(n);
        if (n == mystry + m) {
            // 如果n = M + mystry代表條件已到，輸出n
            if (is_first) {
                printf("%d", n); // 第一次不加空格
                is_first = 0; // 第一次輸出後將is_first設為0
            } else {
                printf(" %d", n);
            }
        }
    }
}

int main () {
    unsigned int mystry;
    while (scanf("%u", &mystry) == 1) {
        // 持續讀取直到EOF
        solveN(mystry);
        printf("\n"); // 每組輸出後換行 
    }
    return 0;
}