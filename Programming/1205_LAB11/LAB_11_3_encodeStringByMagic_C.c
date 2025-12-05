/*Date: 2025/12/05
Author: 黃鈺翔
Description: Encode a string by adding a magic number to each character up to a specified end pointer
Using github copilot to write comments
*/
#include<stdio.h>

void encodeStringByMagic(char * string, char const * endPtr, int magicNumber) {
    char *now_ptr = string; // 指向目前正在處理的字元
    while(now_ptr <= endPtr) {
        // 只要目前指標沒有超過結束指標，就繼續處理字元
        *now_ptr += magicNumber; // 將目前字元加上魔法數字(位移)
        now_ptr++; // 移動到下一個字元
    }
}

int main() {
    char string[100];
    int endIndex, magic;
    scanf("%s", string);
    scanf("%d %d", &endIndex, &magic);
    encodeStringByMagic(string, string + endIndex, magic);
    printf("%s", string);
    return 0;
}