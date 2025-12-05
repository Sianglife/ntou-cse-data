/*Date: 2025/12/05
Author: 黃鈺翔
Description: Count occurrences of countries from input
Using github copilot to write comments
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Country structure
typedef struct country country;
struct country {
    char name[80];
    int cnt;
};

country country_list[80]; // 儲存國家資料的陣列

int size = 0; // 目前國家數量

// 從輸入的字串中取得國家名稱
char country_buffer[80]; // 用來暫存國家名稱的buffer
char* get_country(char *full_string) {
    int index = 0;
    while(full_string[index] != ' ') {
        // 把第一個空格前的字元都存到country_buffer中
        country_buffer[index] = full_string[index];
        index++;
    }
    country_buffer[index] = '\0'; // 擷取完成，補上結束字串
    return country_buffer;
}

// 尋找國家在country_list中的索引
int findIndexByCountry(char *country) {    
    for(int i = 0; i < size; i++) {
        if(strcmp(country_list[i].name, country) == 0) {
            // 字串相同，回傳索引
            return i;
        }
    }
    return -1; // 沒有找到，回傳-1
}

// 處理輸入的字串，更新country_list
void input(char *string) {
    char *country = get_country(string); // 取得國家名稱
    int index = findIndexByCountry(country); // 找到國家在陣列中的索引
    if(index == -1) {
        // 不存在於陣列中，新增一筆資料 
        strcpy(country_list[size].name, country); // 複製國家名稱
        country_list[size].cnt = 1; // 計數器設為1
        size++; // 國家數量加1
    } else {
        // 已存在於陣列中，計數器加1
        country_list[index].cnt++;
    }    
}

void output() {
    // 輸出國家及其計數
    for(int i = 0; i < size; i++) {
        printf("%s %d\n", country_list[i].name, country_list[i].cnt);
    }
}

int compareCountry(const void *c1, const void *c2) {
    // 用來比較兩個country結構的函式，給qsort使用
    country* c1_ptr = (country*) c1;
    country* c2_ptr = (country*) c2;
    return strcmp(c1_ptr->name, c2_ptr->name);
}

void sortCountry() {
    // 使用qsort對country_list進行排序
    qsort(country_list, size, sizeof(country), compareCountry);
}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // 吃掉換行符號
    char string[82];
    while(n--) {
        // 讀取每一行輸入
        fgets(string, sizeof(string), stdin);        
        input(string); // 加入country_list
    }
    sortCountry(); // 排序國家
    output(); // 輸出
    return 0;
}