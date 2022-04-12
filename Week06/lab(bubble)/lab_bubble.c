#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bubble_sort(int* arr, int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;

            }
        }
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
    
    bubble_sort(arr, n);
    printf("정렬된 후:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
}