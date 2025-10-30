/*Date: 2025/10/17
Author: 黃鈺翔
Description: Determine if a three-digit number is an Armstrong number
Using github copilot to help writing comments
*/

#include<stdio.h>
#include<math.h>

void printArmstrong(int number) {
    int a, b, c; // a: 百位, b: 十位, c: 個位

    if(number > 999 || number < 100) {
        // 排除不是三位的正整數
        printf("%d 不是具三位數的正整數", number);
        return;
    }

    // 計算個別位數
    c = number % 10;
    b = number % 100 / 10;
    a = number / 100;

    if (number == pow(c, 3) + pow(b, 3) + pow(a, 3)) {
        // 個別3次方等於該數
        printf("%d 是一個阿姆斯壯數值", number);
    } else {
        printf("%d 不是一個阿姆斯壯數值", number);
    }
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    printArmstrong(n);
    return 0;
}