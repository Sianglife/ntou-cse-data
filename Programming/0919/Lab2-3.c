#include <stdio.h>

void ly1(int times, int type) { // 第一段類似 你看那裡有隻OO喲，反覆用，以type換內容
    int n = times;
    while(n--) { // 以 n 計數，可重複輸出
        if (type == 1) {
            printf("你看那裡有隻小雞喲\n");
        } else if (type == 2) {
            printf("你看那裡有隻母雞喲\n");
        } else if (type == 3) {
            printf("你看那裡有隻公雞喲\n");
        } else if (type == 4) {
            printf("你看那裡有隻火雞喲\n");
        } else if (type == 5) {
            printf("你看那裡有隻鴿子喲\n");
        }
    }
}

void ly2(int times, int type) { // 第二段類似 OOXX喲，反覆用，以type換內容
    int n = times;
    while(n--) {  // 以 n 計數，可重複輸出
        if (type == 0) {
            printf("小雞嗶嗶喲\n");
        } else if (type == 1) {
            printf("小雞嗶嗶喲\n");
        } else if (type == 2) {
            printf("母雞咯咯咯\n");
        } else if (type == 3) {
            printf("公雞喔喔喔\n母雞咯咯咯\n");
        } else if (type == 4) {
            printf("火雞嘟嘟嘟\n公雞喔喔喔\n母雞咯咯咯\n");
        } else if (type == 5) {
            printf("鴿子嚕嚕嚕\n火雞嘟嘟嘟\n公雞喔喔喔\n母雞咯咯咯\n");
        }
    }
    return;
}

int main() {
    for (int n=1; n<=5; n++) { // 共五段，自動帶入type，換主角
        ly1(2, n);  // 第一段
        ly2(1, n);  // 第二段
        ly2(4, 0);  // 四次小雞嗶嗶喲不變
        printf("小雞嗶嗶嗶嗶喲\n\n"); // 最後一句
    }
    return 0;
}