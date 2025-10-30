/*Date: 2025/10/08
Author: 黃鈺翔
Description: print calendar of the month
Using github copilot to write comments
*/
#include <stdio.h>

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
    w = (w + 6) % 7; // 轉成以週日為0的格式
    return w;    
}

void printWeek(unsigned int week[7]) {
    // 傳入一週日期的陣列，印出該週文字
    for(int i=0; i<7; i++) {
        if (week[i] == -1) {
            printf("    "); // 如果-1代表空白，印空格
            continue;
        } 
        if(week[i] == -2) {
            printf("\n"); // 如果-2代表結束，印換行並跳出迴圈
            break;
        }
        if (week[i] < 10) {
            printf("%d  ", week[i]); // 一位數的日期空格
        } else {            
            printf("%d ", week[i]); // 二位數的日期空格
        }
        if (i == 6) {
            printf("\n"); // 週末換行
            continue;
        }
        printf(" ");
    }
    
}

void printCalendar(unsigned int start_weekday, unsigned int day_count) {
    unsigned int week[7], cnt, pointer;
    // Print header
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    
    // 第一週不完整的空格補-1
    pointer = 0;
    while(start_weekday) {
        week[pointer] = -1;
        pointer++;
        start_weekday--;
    }    
    // 中間週
    for(cnt = 1; cnt <= day_count; cnt++) {
        week[pointer] = cnt;
        if (pointer == 6) {
            printWeek(week);
            pointer = -1;
        }        
        pointer++;
    }
    // 最後一週還沒完整印出來的情況
    if (pointer != 0) {
        week[pointer] = -2;
        printWeek(week);
    }
    
}

int main() {
    unsigned int year, month;
    scanf("%d %d", &year, &month);
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            // 2月閏年
            printCalendar(zeller(year, month, 1), 29);
        } else {
            // 2月沒閏年
            printCalendar(zeller(year, month, 1), 28);
        }
    } else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        // 31天
        printCalendar(zeller(year, month, 1), 31);
    } else {
        // 30天
        printCalendar(zeller(year, month, 1), 30);
    }
    return 0;
}