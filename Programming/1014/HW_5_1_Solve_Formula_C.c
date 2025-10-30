/*Date: 2025/10/15
Author: 黃鈺翔
Description: build a program to solve the formula
Using github copilot to write comments
*/

#include<stdio.h>
#include<math.h>

void solveFormula(double a, double b, double c) {
    double D, x1, x2, tmp; // x1, x2:解, D:判別式, tmp:交換用暫存變數
    // 判別式
    D = (b * b) - 4 * a * c; // 算出判別式
    if (D < 0) {
        printf("無實數解\n");
        return;
    }

    // 計算解
    x1 = (-b - sqrt(D)) / (2 * a);
    x2 = (-b + sqrt(D)) / (2 * a);

    // X1要較小
    if(x1 > x2) {
        // 如果x1較大就交換
        tmp = x1;
        x1 = x2;
        x2 = tmp;
    }

    // 輸出解
    printf("x = %.1lf, ", x1);
    printf("%.1lf\n", x2);
    return;
}

int main() {
    int n;
    double a, b, c;
    scanf("%d", &n); // 輸入測試次數
    while(n--) {
        // 處理每次的解
        scanf("%lf %lf %lf", &a, &b, &c);
        solveFormula(a, b, c);
    }
    return 0;
}