/*Date: 2025/10/16
Author: 黃鈺翔
Description: Find the copy times to get at least n lines 
Using github copilot to write comments
*/

#include<stdio.h>
#include<math.h>

int calculatePasting(int lines) {
    // 找出大於等於 n 的最小 2 次方
    int e;
    for(e = 0; pow(2, e) < lines; e++);
    return e;
}


int main() {
    int target; // 輸入的數字
    int cnt = 1; // Case N的計數
    while(scanf("%d", &target)) {
        // 處理每次輸入
        if (target < 0) {
            // 輸入負數則結束
            break;
        }
        printf("Case %d: %d\n", cnt, calculatePasting(target)); // 輸出每個Case
        cnt++;
    }
    return 0;
}