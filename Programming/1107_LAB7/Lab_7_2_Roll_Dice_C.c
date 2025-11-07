/*Date: 2025/11/7
Author: 黃鈺翔
Description: Roll five dice one million times to compare the winning chances of two given sums
Using github copilot to write comments
*/
#include<stdio.h>
#include<stdlib.h>
#define times 1000000

int rollFiveDice(void) {
    // 骰五次，並回傳總和
    int cnt = 0;
    for(int i = 0; i < 6; i++) {
        cnt += rand() % 6 + 1; // 每次骰介於1到6之間的數字
    }
    return cnt;
}

int betterWinningChance(int N, int M) {
    int n_times = 0, m_times = 0; // 儲存N和M出現的次數
    int tmp; // 儲存每次骰五顆骰子的和
    for(int i = 0; i < times; i++) {
        tmp = rollFiveDice();
        if (tmp == N) {
            n_times++;
        }
        if (tmp == M) {
            m_times++;
        }
    }

    if(n_times > m_times) {
        // 如果N出現次數較多，回傳1
        return 1;    
    }
    return 0; // 否則回傳0
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d", betterWinningChance(n, m));
    return 0;
}