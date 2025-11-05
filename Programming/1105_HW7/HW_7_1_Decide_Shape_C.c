/*Date: 2025/11/05
Author: 黃鈺翔
Description: Decide four input number can build a square, rectangle, quadrilateral or neither.
*/

#include<stdio.h>

void swap(int *a, int *b) {
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

int decideShape(unsigned int w, unsigned int x, unsigned int y, unsigned int z) {
    // 正方形
    if (w == x && w == y && w == z) { // 四邊相等
        return 3;
    }
    
    // 排序
    int arr[4] = {w, x, y, z};
    bubbleSort(arr, 4);
    
    // 長方形
    // 排序後應該是n0=n1, n2=n3
    if (arr[0] == arr[1] && arr[2] == arr[3]) {
        return 2;
    }
    
    // 四邊形
    // 判斷n0+n1+n2>n3，則可以形成四邊形
    if (arr[0] + arr[1] + arr[2] > arr[3]) {
        return 1;
    }

    // 都不成立，無法形成四邊形
    return 0;
}

int main() {
    int w, x, y, z;
    scanf("%d %d %d %d", &w, &x, &y, &z);
    printf("%d", decideShape(w, x, y, z));
    return 0;
}