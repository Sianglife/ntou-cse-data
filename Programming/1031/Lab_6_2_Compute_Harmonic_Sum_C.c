/*Date: 2025/10/31
Author: 黃鈺翔
Description: computing the harmonic sum up to a given integer.
Using github copilot to write comments
*/

#include <stdio.h>

double computeHarmonicSum(unsigned int max) {
    unsigned int i; 
    double sum = 0.0; // 調和數總和
    for (i = 1; i <= max; i++) {
        sum += 1.0 / (i); // 從1~max累加調和數
    }
    return sum;
}

int main() {
    unsigned int n;
    scanf("%u", &n);
    printf("%.6f\n", computeHarmonicSum(n));
    return 0;
}