/*Date: 2025/9/26
  Author: 黃鈺翔
  Description: print big number
  using Github Copilot to create big digit pattern*/

#include<stdio.h>

void printBigDigit(int digit) {
    // 用switch判斷輸入數字是多少，輸出對應的pattern並且break以免繼續往下執行列印
    switch (digit) {
        case 0:
            printf("*****\n*   *\n*   *\n*   *\n*****\n");
            break;
        case 1:
            printf("    *\n    *\n    *\n    *\n    *\n");
            break;
        case 2:
            printf("*****\n    *\n*****\n*    \n*****\n");
            break;
        case 3:
            printf("*****\n    *\n*****\n    *\n*****\n");
            break;
        case 4:
            printf("*   *\n*   *\n*****\n    *\n    *\n");
            break;
        case 5:
            printf("*****\n*    \n*****\n    *\n*****\n");
            break;
        case 6:
            printf("*****\n*    \n*****\n*   *\n*****\n");
            break;
        case 7:
            printf("*****\n    *\n    *\n    *\n    *\n");
            break;
        case 8:
            printf("*****\n*   *\n*****\n*   *\n*****\n");
            break;
        case 9:
            printf("*****\n*   *\n*****\n    *\n*****\n");
            break;
    }
}

int main() {
    int n, r1, r2, r3; // r1, r2, r3分別為個十百位，n為使用者輸入的整數
    scanf("%d", &n);
    
    r1 = n % 10; // 計算個位
    if (n < 10) {
        // 補0補滿3位數
        r2 = r3 = 0;
    }

    // 2-3位數 START

    // 處理十位
    r2 = n % 100; // 取得後兩位
    r2 -= r1; // 去掉個位尾數
    r2 /= 10; // 只留下十位數

    if (n < 100) {
        // 補0補滿3位數
        r3 = 0;
    }

    // 3位數 START

    //處理百位
    r3 = n % 1000; // 取得後三位
    r3 -= r1; // 去掉個位尾數
    r3 -= r2 * 10; // 去掉十位尾數
    r3 /= 100; // 只留下百位數

    
    printBigDigit(r3); 
    printBigDigit(r2); 
    printBigDigit(r1);
    return 0;   
}