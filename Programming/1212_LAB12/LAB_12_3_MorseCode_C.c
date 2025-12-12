/*Date: 2025/12/12
Author: 黃鈺翔
Description: Decoding Morse Code to Plaintext
Using github copilot to write comments
*/
#include<stdio.h>
#include<string.h>

char morse_code[26][5] = {
    ".-",   "-...", "-.-.", "-..",  ".",
    "..-.", "--.",  "....", "..",   ".---",
    "-.-",  ".-..", "--",   "-.",   "---",
    ".--.", "--.-", ".-.",  "...",  "-",
    "..-",  "...-", ".--",  "-..-", "-.--",
    "--.."
}; 

char morse2char(char *code) {
    // printf("Decoding Morse Code: %s\n", code);
    // 遍歷morse_code陣列，尋找與輸入code相符的摩斯密碼
    for(int index = 0; index < 26; index++) {
        if (strcmp(morse_code[index], code) == 0) {
            return index + 'A';
        }
    }
    return '?'; // 如果找不到相符的摩斯密碼，回傳問號表示未知字元
}

char *decodeMorsePlaintext(char *cPtr) {
    static char decoded[100];
    int out_cnt = 0;
    int index = 0; // 用來追蹤目前解析到的字元位置
    while(index < strlen(cPtr)) {
        int next_space = strcspn(cPtr + index, " ") + index; // 找到下一個空格的位置
        char code[100]; // 用來存放目前的摩斯密碼
        // printf("Now decoding from index %d to %d\n", index, next_space);
        strncpy(code, cPtr + index, next_space - index); // 複製摩斯密碼到code陣列
        code[next_space - index] = '\0'; // 在code陣列末尾加上字串結束符號
        char tmp = morse2char(code);
        if (tmp == '?') {
            // 如果遇到未知的摩斯密碼，跳過這個字元
            printf("Warning: Incorrect input!\n");
            return NULL;
        }
        decoded[out_cnt++] = morse2char(code); // 將轉換後的字元存入decoded陣列
        index = next_space + 1; // 移動到下一個摩斯密碼的起始位置
    }
    decoded[out_cnt] = '\0'; // 在decoded陣列末尾加上字串結束符號
    printf("%s\n", decoded); // 輸出解碼後的明文
    return decoded;
}


int main() {
    char string[1000];
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = 0; // 移除換行符號
    decodeMorsePlaintext(string); // 
    return 0;
}