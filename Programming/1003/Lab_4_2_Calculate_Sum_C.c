/*Date: 2025/10/03
Author: 黃鈺翔
Description: compute the sum of all numbers from 0 to max that leave a remainder of 2 when divided by 3 and a remainder of 6 when divided by 8.
Using github copilot to write comments
*/

#include <stdio.h>

int computeSum(int max) {
    int cnt = 0; // 計數器
    for(int i=0; i<=max; i++) {
        if (i % 3 == 2 && i % 8 == 6) {
            // 符合條件的數字
            cnt += i; // 計數器加上
        }
    }
    return cnt;
}

int main() {
    int max;
    scanf("%d", &max);
    printf("%d", computeSum(max));
    return 0;
}