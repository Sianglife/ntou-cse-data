#include<stdio.h>
#include<stdlib.h>

void swap(char *a, char *b) {
    char tmp = *b;
    *b = *a;
    *a = tmp;
}

int main() {
    int length;
    scanf("%d", &length);
    getchar(); // 吃掉上一行換行
    
    char *str = malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        str[i] = getchar();
    }

    int mid = length / 2;
    for(int i = 0; i < mid; i++) {
        swap(&str[i], &str[length - 1 - i]);
    }

    printf("%s", str);

    free(str);
    return 0;
}