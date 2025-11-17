#include<stdio.h>
#include<string.h>

struct Book {
    char title[50];
    double price;
};

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    struct Book list[n];
    double max = 0;
    char max_title[50];
    for(int i = 0; i < n; i++) {
        fgets(list[i].title, sizeof(list[i].title), stdin);
        list[i].title[strcspn(list[i].title, "\r\n")] = '\0';

        scanf("%lf", &list[i].price);
        getchar();
        
        if(list[i].price > max) {
            max = list[i].price;
            strcpy(max_title, list[i].title);
        }
    }

    printf("%s\n%f", max_title, max);
    
    return 0;
}

