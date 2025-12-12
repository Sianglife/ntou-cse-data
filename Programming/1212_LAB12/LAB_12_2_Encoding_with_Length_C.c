/*Date: 2025/12/12
Author: 黃鈺翔
Description: Encoding a string with character lengths
Using github copilot to write comments
*/
#include<stdio.h>
#include<string.h>

// 定義一個結構來存放字元及其連續出現的長度
struct Sequence {
    char c;
    int length;
};
typedef struct Sequence Sequence;

// 緩衝區用來存放輸入的字串
char str_buffer[100];
int done = 0; // 用來標記是否已經處理完字串

// 函式用來尋找下一個字元序列及其長度
Sequence findNextSeq(int *index) {
    int cnt = 1;
    char tmp = str_buffer[*index]; // 取得尚未處理過的最前面的字元
    for(int i = *index + 1; ; i++) {
        if (str_buffer[i] == '\0') {
            // 到達字串結尾，標記完成並更新index
            done = 1;
            *index = i;
            break;
        }
        if (tmp == str_buffer[i]) {
            // 如果當前字元與tmp相同，增加計數器
            cnt++;
        } else {
            // 遇到不同字元，更新index並跳出迴圈
            *index = i;
            break;
        }
    }
    Sequence seq = {tmp, cnt}; // 建立並回傳字元及其長度的結構
    return seq; 
}

int main() {
    int index = 0; // 用來追蹤目前處理到字串的哪個位置
    fgets(str_buffer, sizeof(str_buffer), stdin); // 讀取輸入字串
    str_buffer[strcspn(str_buffer, "\n")] = '\0'; // 移除結尾的換行字元

    while(done == 0) {
        // 呼叫函式尋找下一個字元序列
        Sequence seq = findNextSeq(&index);
        printf("%c%d", seq.c, seq.length); // 輸出字元及其長度
    }
    return 0;
}

