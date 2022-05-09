#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int *A, int p, int r) {
    int i, j, t;

    j = p; i = p-1;
    for ( ; j < r; j++) {
        if (A[j] < A[r]) {
            i++;
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }

    i++;
    t = A[i];
    A[i] = A[r];
    A[r]= t;

    return i;
}

void quickSort(int *A, int p, int r) {
    int q;
    if (p < r) {
        q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
    return;
}

int main() {
    int *A;
    int n, i;

    scanf("%d", &n);
    A = (int*)malloc(sizeof(int)*n);

    srand(time(NULL));
    for (i = 0; i < n; i++)
        A[i] = rand() % 1000;

    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    quickSort(A, 0, n-1);

    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    free(A);
    return 0;
}