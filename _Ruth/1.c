#include<stdio.h>   
#include<stdlib.h>
#include<time.h> 

int main() {
    char target, input;
    srand(time(NULL));

    // Capital Alphabet: 65-90
    target = rand() % 26 + 65;

    // Guess
    printf("Enter your guess: ");
    while(scanf("%c", &input) == 1) {
        if (input == '\n') continue; // 忽略換行
        if(input == target) {
            printf("Correct! The secret letter was '%c'\nThanks for playing!", target);
            return 0;
        }
        printf("Wrong guess! Try again.\n");

        printf("Enter your guess: ");
    }

    printf("End by User(EOF)\n");
    return 0;
}