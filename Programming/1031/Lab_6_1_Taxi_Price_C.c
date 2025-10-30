/*Date: 2025/10/19
Author: 黃鈺翔
Description: calculating taxi fare based on distance traveled.
Using github copilot to write comments
*/

#include<stdio.h>

int taxiPrice(int distance) {
    // 計算計程車費用
    int price = 70; // 起跳價70元

    if (distance <= 1500) {
        return price; // 1500公尺內只收起跳價
    }

    distance -= 1500; // 扣除起跳距離
    while (distance > 0) {
        if (distance >= 500) {
            price += 5; // 每500公尺加收5元
            distance -= 500;
        } else {
            price += 5; // 不足500公尺也算一個500公尺
            distance = 0;
        }
    }
    return price;
}


int main () {
    unsigned int mystry;
    while (scanf("%u", &mystry) == 1) {
        // 持續讀取直到EOF
        printf("%d\n", taxiPrice(mystry));
    }
    return 0;
}