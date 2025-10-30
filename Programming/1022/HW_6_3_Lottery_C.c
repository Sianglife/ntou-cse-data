#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PLAY_TIMES 1000000

int ticket[6];

int status[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int getNumberSuffixCount() {
    int suffix, cnt = 0;
    for(int i = 0; i < 6; i++) {
        suffix = ticket[i] % 10;
        if (status[suffix] == 0) {
            status[suffix] = 1;
        }
    }

    for(int i = 0; i < 10; i++) {
        // printf("%d ", status[i]);
        if(status[i] != 0) {
            cnt++;
        }
    }
    // printf("\n");

    return cnt;
}

void lottery() {
    for(int i = 0; i < 6; i++) {
        ticket[i] = (rand() % 49) + 1;
        // printf("%d ", ticket[i]);
    }
    // printf("\n");
    return;
}

int main() {
    int times;
    // int countdown = 1;
    int countdown = PLAY_TIMES;
    int match_count = 0;
    // init
    srand(1000);
    scanf("%d", &times);
    while(countdown--) {
        printf("countdown: %d\n", countdown);
        lottery();
        printf("times: %d\n", getNumberSuffixCount());
        if (getNumberSuffixCount() == times) {
            match_count++;
        }
    }
    printf(" match: %d\n", match_count);

    return 0;
}