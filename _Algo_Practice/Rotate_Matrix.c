#include<stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_martix(int size, int martix[][size]) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%4d ", martix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void rotate_martix(int size, int martix[][size]) {
    // Transpose
    for(int i = 0; i < size; i++) {
        for(int j = i; j < size; j++) {
            swap(&martix[i][j], &martix[j][i]);
        }
    }

    // Reverse
    int mid = size / 2;
    for(int j = 0; j < size; j++) {
        for(int i = 0; i < mid; i++) {
            // printf("%d %d \n", i, j);
            // swap(&martix[i][j], &martix[size - i][j]);
        }
    }

}

int main() {
    int n;
    scanf("%d", &n);
    int martix[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            martix[i][j] = i;
        }
    }
    
    print_martix(n, martix);
    rotate_martix(n, martix);
    print_martix(n, martix);
    return 0;    
}