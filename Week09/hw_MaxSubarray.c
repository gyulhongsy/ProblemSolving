#include <stdio.h>
#include <stdlib.h>

int right_max_sum(int *A, int left, int right) {
    int i, sum = 0;
    int sum_max = A[left];

    if (left >= right) return sum_max;

    for (i = left; i <= right; i++) {
        sum += A[i];

        if (sum > sum_max) {
            sum_max = sum;
        }
    }
    return sum_max;
}

int left_max_sum(int *A, int left, int right) {
    int i, sum = 0;
    int sum_max = A[right];

    if (left >= right) return sum_max;

    for (i = right; i >= left; i--) {
        sum += A[i];

        if (sum > sum_max) {
            sum_max = sum;
        }
    }
    return sum_max;
}

int max_subarray(int *A, int left, int right) {
    int v1, v2, v3;
    int mid = (left+right) / 2;

    if (left >= right) return A[mid];

    v1 = max_subarray(A, left, mid);
    v2 = max_subarray(A, mid+1, right);
    v3 = right_max_sum(A, mid+1, right) + left_max_sum(A, left, mid);

    if (v1 >= v2 && v1 >= v3) return v1;
    else if (v2 >= v3 && v2 >= v1) return v2;
    else if (v3 >= v1 && v3 >= v2) return v3;
}

int main() {
    int *A;
    int num, i, max;

    scanf("%d", &num);
    A = (int*)malloc(sizeof(int)*num);

    for (i = 0; i < num; i++)
        scanf("%d", &A[i]);

    max = max_subarray(A, 0, num-1);

    printf("%d\n", max);

    free(A);
    return 0;
}