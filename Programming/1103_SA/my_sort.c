#include <stdio.h>

// --- 排序函式原型 ---
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int n);

// --- 輔助函式原型 ---
void swap(int *a, int *b);
void print_arr(int arr[], int n);

// ================================================================
//               mySort 函式 (接收函式指標)
// ================================================================
/**
 * @brief 通用排序函式，接收一個 "排序演算法" 作為參數
 * @param arr 要排序的陣列
 * @param n   陣列大小
 * @param sort_func 一個函式指標，指向要使用的排序演算法
 */
void mySort(int *arr, int n, void (*sort_func)(int[], int)) {
    sort_func(arr, n);
}

// ================================================================
//                        Main 函式
// ================================================================
int main() {
    int n;
    printf("輸入資料個數 n (1 <= n <= 100): ");
    scanf("%d", &n);

    int arr[n];
    printf("輸入 %d 個整數: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int mode;
    printf("輸入排序功能代碼 (1-3):\n");
    printf(" 1. 氣泡排序 (Bubble Sort)\n");
    printf(" 2. 選擇排序 (Selection Sort)\n");
    printf(" 3. 插入排序 (Insertion Sort)\n");
    printf("請輸入: ");
    scanf("%d", &mode);


    // 根據 mode，"傳遞" 不同的函式給 mySort
    if (mode == 1) {
        mySort(arr, n, bubbleSort);
    } else if (mode == 2) {
        mySort(arr, n, selectionSort);
    } else if (mode == 3) {
        mySort(arr, n, insertionSort);
    } else if (mode == 4) {
        mySort(arr, n, mergeSort);
    } else {
        printf("錯誤的代碼。\n");
        return 1; // 錯誤退出
    }

    // 排序後輸出
    printf("排序後的陣列: ");
    print_arr(arr, n);

    return 0;
}

// ================================================================
//                      函式實作
// ================================================================

// --- 輔助函式 ---
void print_arr(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}
    

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

// --- 排序法實作 ---

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

void selectionSort(int arr[], int n) {
    /* 每次選出最小值放到前面 */
    int *min_ptr;
    for(int i = 0; i < n; i++) {
        min_ptr = &arr[i];
        for(int j = i; j < n; j++) {
            if (arr[j] < *min_ptr) {
                min_ptr = &arr[j];
            }
        }
        swap(min_ptr, arr + i);
    } 
}


void insertionSort(int arr[], int n) {  
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void mergeSort(int arr[], int n) {
    // TODO
    int L[n / 2 + 1], R[n / 2 + 1];
    int i;
    for(i = 0; i < n / 2; i++) {
        // 搬前半
        L[i] = arr[i];
    }
    if (n % 2 == 1) {
        // 奇數長度多加中間一位到前半
        L[i] = arr[i];
        i++;
    }
    print_arr(L, n/2+1);
    for(; i < n; i++) {
        // 後半
        R[i - n / 2 - (n % 2)] = arr[i];
    } 
    print_arr(R, n/2+1);
}