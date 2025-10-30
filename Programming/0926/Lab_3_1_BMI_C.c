/*Date: 2025/9/21
  Author: 黃鈺翔
  Description: user input BMI and response the health status*/

#include <stdio.h>

// 判斷BMI並輸出對應的健康狀態的函式
void judgeWeight(double bmi) {
    if (bmi < 18.5) {
        printf("體重過輕\n");
    } else if (bmi < 25) {
        printf("健康的體重\n");
    } else {
        printf("體重過重\n");
    }
    return;
}

int main() {
    double bmi; // 宣告用來存放BMI的變數
    scanf("%lf", &bmi); // 讀取使用者輸入的BMI值
    judgeWeight(bmi); // 呼叫函式來判斷並輸出健康狀態
    return 0;
}
