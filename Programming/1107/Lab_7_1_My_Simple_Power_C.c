/*Date: 2025/11/2
Author: 黃鈺翔
Description: calculate x to the power of y using recursion
Using github copilot to write comments
*/
#include <stdio.h>

unsigned long long int mySimplePower(int x, int y) {
    if (y == 0) {
        return 1;
    }
    return x * mySimplePower(x, y - 1);
}

int main() {
    unsigned long long int x, y;
    scanf("%llu %llu", &x, &y);
    printf("%llu\n", mySimplePower(x, y));
    return 0;
}