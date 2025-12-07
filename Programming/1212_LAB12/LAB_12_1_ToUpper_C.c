/*Date: 2025/12/12
Author: 黃鈺翔
Description: Converting a string to uppercase
Using github copilot to write comments
*/
#include<stdio.h>
#include<string.h>

char *toMyUpper(const char *string) {
    static char result[100]; // result陣列用來存放轉換後的字串，用static確保其在函式return後仍然存在
    for(int i = 0; i < strlen(string); i++) {
        if(string[i] >= 'a' && string[i] <= 'z') {
            // 如果字元是小寫字母，轉換為大寫字母
            result[i] = string[i] - ('a' - 'A');
        } else {
            // 否則保持原字元不變
            result[i] = string[i];
        }
    }
    return result;
}

int main() {
    char string[100];
    scanf("%s", string);
    printf("%s", toMyUpper(string));
    return 0;
}