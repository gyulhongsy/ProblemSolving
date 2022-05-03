#include <stdio.h>

int left_max_sum(int A[], int left, int right) {
    int i, sum = 0;
    int sum_max = A[right];

    for (i = right; i >= left; i--) {
        sum += A[i];

        if (sum > sum_max) {
            sum_max = sum;
        }
    }
    return sum_max;
}

int main() {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int max = left_max_sum(A, 4, 7);

    printf("max value = %d\n", max);

    return 0;
}