/*Date: 2025/9/12
  Author: 黃鈺翔
  Description: print a horse*/

#include<stdio.h>

int main() {
    printf("    ()\n");   //在stdout印出一行的圖案
    printf("  / \\\\\\\\\\\n");  // \n換行、\\印出反斜線，一個\是跳脫字元
    printf(" / ^ \\\\\\\\\\\\\n");
    printf("/   /\\\\\\\\\\\\\\\\\n");
    printf("\\/_/  \\ \\\\\\\\\\\\\n");
    printf("       \\     \\__________//\\\\\n");
    printf("       |                \\\\\\\\\\\n");
    printf("       |                 \\\\\\\\\\\n");
    printf("       |                 | \\\\\\\n");
    printf("      / .________________/  \\\\\n");
    printf("     / / | |      / / | |    \\\n");
    printf("    / /  | |     / /  | |\n");
    printf("   | |   | |    | |   | |\n");
    printf("    \\_\\  |_|     \\_\\  |_|\n");
    printf("     \\#\\ |#|      \\#\\ |#|\n");
    return 0;
}