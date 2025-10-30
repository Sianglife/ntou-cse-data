/*Date: 2025/10/13
Author: 黃鈺翔
Description: build a program to print the corresponding season of the month
Using github copilot to help writing comments
*/

#include <stdio.h>

void printCorrespondingSeason(int month) {
    if (month > 12 || month < 1) {
        // 如果輸入不在1~12之間，印錯誤訊息並結束
        printf("輸入錯誤");
        return;
    }

    switch (month) {
        // 每個月的case對應到不同的季節
        case 1:
        case 2:
        case 3:
            printf("Spring");
            break;
        case 4:
        case 5:
        case 6:
            printf("Summer");
            break;
        case 7:
        case 8:
        case 9:
            printf("Fall");
            break;
        case 10:
        case 11:
        case 12:
            printf("Winter");
            break;
    }
    return;
}

int main() {
    int month;
    scanf("%d", &month);
    printCorrespondingSeason(month);
    return 0;
}