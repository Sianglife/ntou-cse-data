/*Date: 2025/11/14
Author: 黃鈺翔
Description: score analytics: rank distribution, average, median
Using github copilot to write comments
*/

#include<stdio.h>

void swap(int *a, int *b) {
    // 交換兩指標的值
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int arr[], int n) {
    /* 兩兩比較、較大的往後移或較小
    的往前移，像氣泡一樣浮上去。 */
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int getMedian(int sortedArr[], int arraySize) {
    // 輸入已排序的陣列，回傳中位數
    if (arraySize % 2 == 1) {
        return sortedArr[arraySize / 2];
    } else {
        return (sortedArr[arraySize / 2] + sortedArr[arraySize / 2 - 1]) / 2;
    }
}

double getAverage(int arr[], int size) {
    // 輸入陣列及大小，回傳平均值
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

void getRank(int result[11], int score[], int score_size) {
    // 統計各分數區間人數，並放到指定的result[11]陣列中
    // result的n項代表分數區間n0~n9，result[10]代表100分
    // 例如: result[0]代表0~9分人數，result[1]代表10~19分人數，以此類推
    for(int i = 0; i < score_size; i++) {
        if (score[i] == 100) {
            result[10] += 1;
        } else if (score[i] >= 90) {
            result[9] += 1;
        } else if (score[i] >= 80) {
            result[8] += 1;
        } else if (score[i] >= 70) {
            result[7] += 1;
        } else if (score[i] >= 60) {
            result[6] += 1;
        } else if (score[i] >= 50) {
            result[5] += 1;
        } else if (score[i] >= 40) {
            result[4] += 1;
        } else if (score[i] >= 30) {
            result[3] += 1;
        } else if (score[i] >= 20) {
            result[2] += 1;
        } else if (score[i] >= 10) {
            result[1] += 1;
        } else {
            result[0] += 1;
        }
    }
}

void printRank(int rank[11]) {
    // 輸出分數分佈長條圖
    for(int i = 10; i >= 0; i--) {
        if(i == 10) {
            printf("100:");
        } else if (i == 0) {
            printf("0-9:");
        } else {
            printf("%d0-%d9:", i, i); // 其餘分數區間的輸出，舉例: i = 2, 輸出20-29
        }
        while(rank[i]--) {
            printf("="); // 有幾個人就印幾個等號
        }
        printf("\n");
    }
}

int main() {    
    int score[100]; // 放學生成績
    int n; // 學生人數

    // 輸入
    scanf("%d", &n);    
    for (int i = 0; i < n; i++) {
        scanf("%d", &score[i]);
    }

    // 處理並輸出結果
    int rank[11] = {0}; // 放各分數區間人數的陣列，初始值皆為0
    getRank(rank, score, n);
    printRank(rank);

    printf("Average:%.1lf\n", getAverage(score, n));
    bubbleSort(score, n); // 中位數函式設計須傳入已排序陣列
    printf("Median:%d\n\n", getMedian(score, n));

    return 0;
}