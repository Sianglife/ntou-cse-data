/*Date: 2025/9/24
  Author: 黃鈺翔
  Description: calculate total price of 3 items
  使用 Github Copilot VScode Extension 輔助完成註解，不包含程式部分。
  */

#include<stdio.h>

// 計算總金額
int calculateExpenses(int tea, int coffee, int bag) {
    if (tea < 0 || coffee < 0 || bag < 0) {
        // 如果包含負數，回傳-1
        return -1;
    }
    return 50 * tea + 45 * coffee + bag;
}

int main() {
    int tea, coffee, bag;
    scanf("%d", &tea);
    scanf("%d", &coffee);
    scanf("%d", &bag);

    // 把讀入的數量傳入函式並輸出結果
    printf("%d元", calculateExpenses(tea, coffee, bag));

    return 0;
}