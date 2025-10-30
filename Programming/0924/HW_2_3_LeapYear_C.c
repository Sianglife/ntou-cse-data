/*Date: 2025/9/24
  Author: 黃鈺翔
  Description: Determine if the input year is a leap year.
  */

#include<stdio.h>

int isLeapYear(int year) {
    if (year % 4 != 0) { // 當除4的餘數等於0，代表整除
        // 無法被4整除
        return 0;
    }
    // 可被4整除，額外判斷能被100整除卻不能被400整除
    if ((year % 100) == 0 && (year % 400) != 0) {
        return 0;
    }
    return 1;
}

int main() {
    int year;
    scanf("%d", &year);
    
    // 把讀入的數量傳入函式並輸出結果
    printf("%d", isLeapYear(year)); 

    return 0;
}