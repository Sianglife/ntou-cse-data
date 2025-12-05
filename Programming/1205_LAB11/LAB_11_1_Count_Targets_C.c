/*Date: 2025/11/30
Author: 黃鈺翔
Description: Counting occurrences of a target character in a string
Using github copilot to write comments
*/
#include<stdio.h>

int countTargets(const char *string, char target) {
    int count = 0; // 初始化計數器
    int i = 0; // 初始化索引
    // 遍歷字串直到遇到結束符號
    while(string[i] != '\0') {
        if(string[i] == target) {
            // 如果當前字元等於目標字元，計數器加一
            count++;
        }
        // 繼續檢查下一個字元
        i++;
    }
    return count;
}

int main() {
    char str[9999]; // 宣告字串陣列
    scanf("%s", str); // 讀取輸入字串
    char target; // 宣告目標字元
    scanf(" %c", &target); // 讀取目標字元
    printf("%d\n", countTargets(str, target)); // 輸出目標字元出現次數
    return 0;
}