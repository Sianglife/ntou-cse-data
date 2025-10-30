/*Date: 2025/10/03
Author: 黃鈺翔
Description: build a number pyramid
Using github copilot to write comments
*/

#include <stdio.h>

int output(int n, int type) {
    // type=1: space, type=2: digit
    for (int i=1; i<=n; i++) {
        if (type == 1) {
            printf(" ");
        } else if (type == 2) {
            if (i > 9) {
                printf("%d", i % 10); // 如果數字超過一位數，則只印出個位數
            } else {
                printf("%d", i);
            }
        }
    }
}

void printPyramid(int total) {
    int full_digit = (2 * total) - 1;  // 最後一位的數字長度，一定是奇數

    for(int digit=1; digit<=full_digit; digit+=2) {
        int space = (full_digit - digit) / 2; // 該行一邊的空格數
        output(space, 1); // 印前面的空格
        output(digit, 2); // 印數字
        printf("\n"); 
    }

}

int main() {
    int total; // digit: 目前行的數字長度, space: 該行一邊的空格數, full_digit: 最後一行的數字長度
    scanf("%d", &total); 
    printPyramid(total);
    return 0;
}