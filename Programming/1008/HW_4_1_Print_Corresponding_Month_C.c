/*Date: 2025/10/08
Author: 黃鈺翔
Description: build a program to print the corresponding month
Using github copilot to write comments, create switch statement
*/

#include<stdio.h>

void printCorrespondingMonth(int month) {
    // Switch判斷月份並印出對應的英文月份名稱
    switch (month) {
    case 1:
        printf("January");
        break;    
    case 2:
        printf("February");
        break;
    case 3:
        printf("March");
        break;
    case 4:
        printf("April");
        break;
    case 5:
        printf("May");
        break;
    case 6:
        printf("June");
        break;
    case 7:
        printf("July");
        break;
    case 8:
        printf("August");
        break;
    case 9:
        printf("September");
        break;
    case 10:
        printf("October");
        break;
    case 11:
        printf("November");
        break;
    case 12:
        printf("December");
        break;
    default:
        // 如果輸入的月份不在1-12之間，印出錯誤訊息
        printf("輸入錯誤");
        break;
    }
    return;
}

int main() {
    int month;
    scanf("%d", &month);
    printCorrespondingMonth(month);
    return 0;
}


