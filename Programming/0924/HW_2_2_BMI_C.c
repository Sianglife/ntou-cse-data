/*Date: 2025/9/24
  Author: 黃鈺翔
  Description: user input Height and weight, calculate BMI.
  使用 Github Copilot VScode Extension 輔助完成註解，不包含程式部分。
  */

#include<stdio.h>

// 計算BMI
double calculateBMI(double height, double weight) {
    return weight / (height * height);
}

int main() {
    double height, weight;
    scanf("%lf", &height);
    scanf("%lf", &weight);
    height /= 100; // 將身高從公分轉成公尺

    // 把讀入的數量傳入函式並輸出結果
    printf("BMI = %f", calculateBMI(height, weight));

    return 0;
}