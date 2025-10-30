#include<stdio.h>

int fibonacci_recursive(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    }
}

int fibonacci_iterate(int n) {
    int tmp1=0, tmp2=1, tmp3;
    for(int i=0; i<n; i++) {
        // 產生新值
        tmp3 = tmp1 + tmp2;
        // printf("%d\n", tmp3);

        // 位移
        tmp1 = tmp2;
        tmp2 = tmp3;
    }
}   

int main() {
    int n;
    scanf("%d", &n);
    fibonacci_iterate(n);
}
