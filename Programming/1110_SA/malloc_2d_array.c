#include<stdio.h>
#include<stdlib.h>

int main() {
    int row, col;
    scanf("%d %d", &row, &col);

    int **arr = malloc(row * sizeof(int*));
    for(int i = 0; i < row; i++) {
        arr[i] = malloc(col * sizeof(int));
    }

    int sum = 0;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
            sum += arr[i][j];
        }
    }

    for(int i = 0; i < row; i++) {
        free(arr[i]);
    }
    free(arr);
    printf("Sum: %d\n", sum);
}