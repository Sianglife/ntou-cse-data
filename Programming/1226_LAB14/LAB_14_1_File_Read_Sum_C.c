/*Date: 2025/12/21
Author: 黃鈺翔
Description: Find the maximum number in a file
Using github copilot to write comments
*/

#include<stdio.h>

int getMaximum(char *fName) {
    FILE *fptr;
    fptr = fopen(fName, "r"); // 僅讀取

    int n, max = 0;
    while(fscanf(fptr, "%d", &n) == 1) {
        // 讀取每個數字，轉成int
        if (n > max) {
            max = n;
        }
    }
    return max;    
}

int main() {
    char fName[100];
    scanf("%s", fName);
    printf("%d", getMaximum(fName));
    return 0;
}