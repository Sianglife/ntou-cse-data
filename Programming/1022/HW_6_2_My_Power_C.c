/*Date: 2025/10/22
Author: 黃鈺翔
Description: calculating M raised to the power of N.
Using github copilot to write comments
*/

#include<stdio.h>

double cnt;

double myPower(double M, int N) {
    printf("M: %lf, N: %d\n", M, N);
    if (N == 1) {
        return cnt;
    }

    if (N > 1) {
        cnt *= M;
        return myPower(M, --N);
    } else {
        cnt /= M;
        return myPower(M, ++N);
    }
}


int main() {
    double m;
    int n;
    scanf("%lf %d", &m, &n);
    cnt = m;
    printf("%lf", myPower(m, n));
    return 0;
}