#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int* arr, int n) {
    int i, j, k;
    int temp, flag;
    for (i = 0; i < n-1; i++) {
        flag = 0;
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                flag = 1;
            }
        }
        if (flag == 0) return;
        printf("i =%2d:\t", i);
        for (k = 0; k < n; k++) printf("%d ", arr[k]);
        printf("\n");
    }
}

int main() {
    int n, i;
    int *arr;
    //srand(time(NULL));

    printf("Enter a number: ");
    scanf("%d", &n);

    arr = (int*)malloc(sizeof(int)*n);

    printf("초기 : ");
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%3d", arr[i]);
    }
    printf("\n");
    
    bubble_sort(arr, n);
    printf("정렬 :");
    for (i = 0; i < n; i++)
        printf("%3d", arr[i]);
    printf("\n");

    free(arr);
}