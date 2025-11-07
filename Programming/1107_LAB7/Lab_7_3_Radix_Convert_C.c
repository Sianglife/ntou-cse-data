#include<stdio.h>
#include<math.h>

void radixConversion(int number, int radix) {
    int quotient, ri; // 商數、次方數
    int digits = 1 + (int)(log(number) / log(radix)); // 計算位數
    
    for(int i = digits - 1; i >= 0; i--) {
        ri = pow(radix, i); // 次方數計算
        quotient = number / ri; // 商數計算
        if (quotient < 10) {
            // 阿拉伯數字輸出
            printf("%d", quotient);
        } else {
            // >10的記號輸出
            printf("%c", 'A' + quotient - 10); // 用ASCII累加，65'A'對應到商數=10
        }
        number = number - quotient * ri; // 更新number
    }
    printf("\n"); // 最後的換行
}

int main() {
    int n, r;
    scanf("%d %d", &n, &r);
    radixConversion(n, r);
    return 0;
}