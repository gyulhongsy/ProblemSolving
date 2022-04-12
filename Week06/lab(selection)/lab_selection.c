#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int *arr, int n) {
    int i, j, max, max_idx, temp;
    for (i = 0; i < n-1; i++) {
        max = arr[0]; max_idx = 0;
        for (j = 0; j < n-i; j++) {
            if (arr[j] > max) {
                max = arr[j];
                max_idx = j;
            }
        }
        temp = arr[n-i-1];
        arr[n-i-1] = arr[max_idx];
        arr[max_idx] = temp;
    }
}

int main() {
    int n, i;
    int *arr;
    srand(time(NULL));

    printf("Enter a number: ");
    scanf("%d", &n);

    arr = (int*)malloc(sizeof(int)*n);

    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    selection_sort(arr, n);
    printf("정렬된 후:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
}