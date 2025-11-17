#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book {
    char title[50];
    double price;
};

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    struct Book *list = malloc(n * sizeof(struct Book));
    struct Book *max_book = list;
    char max_title[50];
    for(int i = 0; i < n; i++) {
        fgets(list[i].title, sizeof(list[i].title), stdin);
        list[i].title[strcspn(list[i].title, "\r\n")] = '\0';

        scanf("%lf", &list[i].price);
        getchar();
        
        if(list[i].price > max_book->price) {
            max_book = &list[i];
        }
    }

    printf("%s\n%f", max_book->title, max_book->price);
    
    return 0;
}

