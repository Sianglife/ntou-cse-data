/*Date: 2025/10/1
Author: 黃鈺翔
Description: Find nth answer of Sun-Tzu number
Using Chat-GPT to realize problem, Github Copilot to write comments
*/

#include<stdio.h>

int findSunTzu(int n) {
    int cnt = 0;
    while(n--) {
        // n個解的計數
        while (1) {
            cnt++;
            if (cnt % 3 == 2 && cnt % 5 == 3 && cnt % 7 == 2) break;  // 找到下一個符合條件的數字
        }
    }
    return cnt;  // 回傳第n個解
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", findSunTzu(n));  // 將使用者輸入的數字傳給函式並印出結果
}