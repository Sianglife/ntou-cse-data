/*Date: 2025/12/05
Author: 黃鈺翔
Description: Find the first unique character in a string
Using github copilot to write comments
*/
#include<stdio.h>

int used[27] = {0}; // 用來記錄每個字母出現的次數，預設都是0

int checkUnique(const char *string) {
    // 檢查字串中每個字母出現的次數的函式
    int n = 0; // 用來遍歷字串的索引
    while(string[n] != '\0') { // 當碰到字串結尾時停止
        used[string[n] - 'a']++; // 將對應字母的計數器加1
        n++; // 移動到下一個字母
    }
} 

int firstUniqueCharacter(const char * string) {
    checkUnique(string); // 先把used陣列填好
    // 接下來檢查字串中第一個只出現過一次的字母
    int n = 0; // 用來遍歷字串的索引
    while(string[n] != '\0') {
        if(used[string[n] - 'a'] == 1) {
            // 找到第一個只出現過一次的字母，回傳它的索引
            return n;
        }
        n++;
    }
    return -1;    // 如果都沒有找到，回傳-1
}

int main() {
    char string[100];
    scanf("%s", string);
    printf("%d", firstUniqueCharacter(string));
    return 0;
}