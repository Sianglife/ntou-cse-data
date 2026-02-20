#include<stdio.h>

int GCD(int a, int b) {
    int l;
    l = a % b;
    if (l == 0) {
        return b;
    }
    return GCD(b, l);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if(a > b) {
        printf("%d", GCD(a, b));
    } else {
        printf("%d", GCD(b, a));
    }
}