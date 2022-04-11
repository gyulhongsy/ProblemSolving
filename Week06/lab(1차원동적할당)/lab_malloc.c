#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i;
    int *arr;

    srand(time(NULL));

    printf("Enter a number: ");
    scanf("%d", &n);

    arr = (int*)malloc(sizeof(int)*n);

    for (i = 0; i < n; i++) 
        arr[i] = rand() % 1000;

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
}