#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *A, int p, int q, int r, int *B) {
    int i, j, t;

    i = p; j = q + 1;
    t = 0;

    while (i <= q && j <= r) {
        if (A[i] < A[j]) {
            B[t] = A[i];
            i++;
        }
        else {
            B[t] = A[j];
            j++;
        }
        t++;
    }
    if (i > q) {
        for ( ; j <= r; j++, t++) 
            B[t] = A[j];
    }
    else if (j > r) {
        for (; i <= q; i++, t++)
            B[t] = A[i];
    }

    for (i = p, t = 0; i <= r; i++, t++) 
        A[i] = B[t];

    return;
}

void mergeSort(int *A, int p, int r, int *B) {
    int q;

    if (p < r) {
        q = (p+r) / 2;
        mergeSort(A, p, q, B);
        mergeSort(A, q+1, r, B);
        merge(A, p, q, r, B);
    }
    return;
}

int main() {
    int *A, *B;
    int n, i;

    scanf("%d", &n);
    A = (int*)malloc(sizeof(int)*n);
    B = (int*)malloc(sizeof(int)*n);

    srand(time(NULL));
    for (i = 0; i < n; i++)
        A[i] = rand() % 1000;

    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    mergeSort(A, 0, n-1, B);

    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    free(A);
    return 0;
}