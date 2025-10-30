/*Date: 2025/9/19
  Author: 黃鈺翔
  Description: user input the radius and calculate the circumference*/

#include <stdio.h>
#define pi 3.1415
// 上述 define 讓編譯器自動帶入pi的值，方便調整

int main() {
    int r; // 半徑
    double l; // 圓周長
    scanf("%d", &r);  // 讀取使用者輸入半徑

    l = 2 * pi * r; // 計算圓周長
    printf("%.2f", l); // 印出答案
    return 0;
}