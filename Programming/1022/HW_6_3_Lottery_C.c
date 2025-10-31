/*Date: 2025/10/31
Author: 黃鈺翔
Description: simulate lottery drawing 
and calculate percentage of tickets matching a certain suffix count.
Using github copilot to write comments
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PLAY_TIMES 1000000

int ticket[6]; // 樂透號碼


int getNumberSuffixCount() {
    // 回傳尾數個數
    int status[10] = {0}; // 紀錄0~9尾數是否出現過
    int suffix, cnt = 0;
    for(int i = 0; i < 6; i++) {
        // 測試每個樂透數字的尾數
        suffix = ticket[i] % 10; // 取得尾數
        if (status[suffix] == 0) {
            status[suffix] = 1; // 標記尾數出現過
        }
    }

    for(int i = 0; i < 10; i++) {
        if(status[i] != 0) {
            cnt++; // 計算不同出現尾數的數量
        }
    }
    return cnt;
}

void lottery() {
    // 抽樂透號碼
    int used[50] = {0}; // 標記1~49號碼是否已被使用
    int num;
    for(int i = 0; i < 6; i++) {
        num = (rand() % 49) + 1; // 產生1~49的隨機數
        while(used[num] != 0) {
            // 如果遇到重複的數字，就重抽
            num = (rand() % 49) + 1;
        }
        used[num] = 1;
        ticket[i] = num;
    }
    return;
}

int main() {
    int times; // 使用者輸入的尾數個數
    int countdown = PLAY_TIMES; // 最前面define的抽獎次數
    int match_count = 0; // 符合input的次數的計數器
    double percent; // 最後計算答案的百分比
    srand(1000);
    scanf("%d", &times);
    while(countdown--) {
        // 抽指定次數的樂透
        lottery(); // 抽樂透
        if (getNumberSuffixCount() == times) {
            // 判斷是否符合使用者輸入的尾數個數
            match_count++;
        }
    }
    // 抽完了，計算百分比並輸出
    percent = (double)match_count/PLAY_TIMES * 100; // double轉形，避免整數除法截斷
    printf("%.1f%%\n", percent);
    return 0;
}