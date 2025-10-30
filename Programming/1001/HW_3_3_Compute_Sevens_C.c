/*Date: 2025/10/1
Author: 黃鈺翔
Description: calculate the number of 7 in the user given number
*/

#include<stdio.h>

int computeSevens(int n, int cnt) { // n=輸入的整數，cnt=上次計算的7counter
    int tmp; // 暫存餘數(個位數)的變數
    tmp = n % 10; // 留個位數
    if (tmp == 7 || tmp == -7) {
        // 如果餘數是正負7就 counter +1
        cnt ++;
    }
    n /= 10; // 去掉個位數，留下其他位數生成新數
    if (n == 0) {
        // 如果新數是0就結束遞迴，代表算完了
        return cnt;
    }    
    return computeSevens(n, cnt); // 沒有結束就繼續遞迴呼叫自己，把生成的新數與目前的counter帶入下一次呼叫
    
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", computeSevens(n, 0)); // 將使用者輸入的數字傳給函式並印出結果，且設定7counter初始值為0
    return 0;
}