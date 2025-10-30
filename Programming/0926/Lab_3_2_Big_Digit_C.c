/*Date: 2025/9/26
  Author: 黃鈺翔
  Description: print big digit
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
    // 最後再多兩行空行
    printf("\n\n");
}

int main() {
    int digit; // 使用者輸入的數字
    scanf("%d", &digit);
    printBigDigit(digit);
    return 0;    
}