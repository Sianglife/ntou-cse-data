/*Date: 2025/10/17
Author: 黃鈺翔
Description: print the day of the week
Using github copilot to write comments
*/
#include<stdio.h>

int last_2_digit(unsigned int number) {
    int tmp;
    tmp = number % 100; // 取百位以下的數字
    return tmp;
}

int first_2_digit(unsigned int number) {
    int tmp;
    tmp = number / 100; // 除100，用int捨去小數點，即為前兩位數
    return tmp;
}

int zeller(unsigned int year, unsigned int month, unsigned int day) {
    // 判斷星期的公式
    unsigned int yy, y, c, m, w, d;
    d = day;
    // Set yy, m
    if (month == 1 || month == 2) {
        yy = year - 1;
        m = month + 12;
    } else {
        yy = year;
        m = month;
    }
    // Finish YY, m
    
    // SET y, c
    y = last_2_digit(yy);
    c = first_2_digit(yy);
    // Finish y, c    
    
    // Calc w
    w = (d + (13 * (m + 1) / 5) + y + (y / 4) + (c / 4) - (2 * c)) % 7;
    w = (w + 7) % 7; // 轉成以週日為1的格式
    return w;    
}

int main() {
    unsigned int year, month, day;
    scanf("%u %u %u", &year, &month, &day);
    printf("%d\n", zeller(year, month, day));
    return 0;
}