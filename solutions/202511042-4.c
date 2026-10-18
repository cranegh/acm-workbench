#include <stdio.h>

int main() {
    int a[8] = {64, 34, 25, 12, 22, 11, 90, 88};
    int i, j, temp;
    
    printf("原始数组:\n");
    for (i = 0; i < 8; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    
    printf("\n排序后的数组:\n");
    for (i = 0; i < 8; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}