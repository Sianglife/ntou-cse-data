/* Date: 2025/9/17
   Author: 黃鈺翔
   Description: calculate the gross tonnage of ship x*/
#include<stdio.h>
#include<math.h>

int main() {
    double g;
    g = 400 + 40 * log10(2000); // 計算K = 2000 * (0.2 + 0.02 log10(V)) (V為船的體積)
    g = floor(g*1000000)/1000000; // 截斷到小數點後六位
    printf("%.6f", g); // 印出結果
    return 0;
}