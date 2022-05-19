#include <stdio.h>
#include <stdlib.h>

void testPirint(int *a, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void selectionSortNew(int A[], int n, int start) {
    int i, j, k, max, max_idx, temp;
    for (i = start, k = 0; i < n - 1; i++, k++) {
        max = A[start]; max_idx = start;
        for (j = start; j < n - k; j++) {
            if (A[j] > max) {
                max = A[j];
                max_idx = j;
            }
        }
        temp = A[n - k - 1];
        A[n - k - 1] = A[max_idx];
        A[max_idx] = temp;
    }

    return;
}

int main() {
    int n, start, pivot;
    int *a;
    int i, flag = 0;

    scanf("%d", &n);
    a = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    for (i = n-1; i > 0; i--) {
        if (a[i] > a[i-1]) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("-1\n");
        return 0;
    }
    else {
        pivot = i-1;

        int min = 999, min_idx = 0;
        for (; i < n; i++) {
            if (a[i] > a[pivot] && a[i] < min) {
                min = a[i];
                min_idx = i;
            }
        }
        int temp;
        temp = a[pivot];
        a[pivot] = a[min_idx];
        a[min_idx] = temp;

        start = pivot+1;
    }
    
    selectionSortNew(a, n, start);
    testPirint(a, n);

    free(a);
    return 0;
}