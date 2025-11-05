#include <stdio.h>
#include <stdlib.h> // ???F qsort()

/**
 * @brief qsort ?????u????æÌ?v (??p??j)
 * ?????????O?G int (const void *, const void *)
 */
int cmp_int_ascending(const void *a, const void *b) {
    int *ptr_a = a, *ptr_b = b; 
    if (*ptr_a > *ptr_b) {
        return 1;
    } else if (*ptr_a == *ptr_b) {
        return 0;
    } else {
        return -1;
    }
}

/**
 * @brief ?m??G??j??p???
 */
int cmp_int_descending(const void *a, const void *b) {
    int *ptr_a = a, *ptr_b = b; 
    if (*ptr_a > *ptr_b) {
        return -1;
    } else if (*ptr_a == *ptr_b) {
        return 0;
    } else {
        return 1;
    }
}


int main() {
    int arr[] = {10, 5, 100, 30, 50, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("??l?}?C: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    // --- ?I?s qsort ---
    // 1. base: arr (?}?C)
    // 2. nitems: n (???)
    // 3. size: sizeof(int) (?@?? int ???j?p)
    // 4. compar: cmp_int_ascending (?????æÌ???ÈFI)
    qsort(arr, n, sizeof(int), cmp_int_ascending);

    printf("??p??j: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    // --- ?A???I?s qsort ---
    qsort(arr, n, sizeof(int), cmp_int_descending);
    
    printf("??j??p: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}