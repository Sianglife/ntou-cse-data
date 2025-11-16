#include<stdio.h>
#include<ctype.h>

int main() {
    char str[100];
    int digit, alpha, space;
    digit = alpha = space = 0; 

    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) digit++;
        else if (isalpha(str[i])) alpha++;
        else if (isspace) space++;
    }

    printf("¦r¥À=%d ¼Æ¦r=%d ªÅ¥Õ=%d", alpha, digit, space);
}