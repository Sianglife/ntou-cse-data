/*Date: 2025/11/05
Author: 黃鈺翔
Description: 印出輸入數字K的KKK乘法表
*/

#include<stdio.h>

/*
@ 定義變數名稱
B-Base
C-Column(col)
R-Row
N-Number
[ B]|    C    2    3    4    5    6    7    8    N
----+---------------------------------------------
   R|    1
   2|    2    4
   3|    3    6    9
*/

// 印出每組的第1、2排header
void print_head(int number, int base) {
    // 第一排
    printf("[%2d]|", base);

    // 數字
    for(int i = 1; i <= number; i++) {
        printf("%5d", i);
    }
    
    // 分隔線的左邊
    printf("\n----+");

    // 分隔線右側
    for(int i = 1; i <= number; i++) {
        printf("-----");
    }
    printf("\n");
}

// 印出中間的行數
void print_line(int number, int base, int row) {
    printf("%4d|", row); // 左邊的數字
    for(int col = 1; col <= row; col++) {
        printf("%5d", base * col * row); // 有數字的
    }
    for(int col = 0; col < number - row; col++) {
        printf("    -"); // 後面槓掉的
    }
    printf("\n");
}

void print_base(int number, int base) {
    // 印出每一組
    print_head(number, base);
    for(int row = 1; row <= number; row++) {
        print_line(number, base, row);
    }
    printf("\n");
}

int main() {
    int number;
    scanf("%d", &number);

    // 印n組乘法表
    for(int base = 1; base <= number; base++) {
        print_base(number, base);
    }

    return 0;

}