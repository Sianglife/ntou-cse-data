/*Date: 2025/10/22
Author: 黃鈺翔
Description: calculating M raised to the power of N.
Using github copilot to write comments
*/

#include<stdio.h>

double cnt; // 計算乘法積的全域變數

double myPower(double M, int N) {
    if (N == 1) {
        return cnt; // 算到1次方，回傳cnt結果（可能是一開始就1次，或遞迴到終點）
    }

    if (N > 1) {
        // 如果次方為正數，則將 cnt 乘上 M，並將 N 減 1 後繼續遞迴
        cnt *= M;
        return myPower(M, --N);
    } else {
        // 如果次方為負數，則將 cnt 除以 M，並將 N 加 1 後繼續遞迴
        cnt /= M;
        return myPower(M, ++N);
    }
}


int main() {
    double m;
    int n;
    scanf("%lf %d", &m, &n);
    cnt = m; // 在開始計算前先將 cnt 設為 M
    printf("%lf", myPower(m, n));
    return 0;
}