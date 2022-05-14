#include <stdio.h>
#include <stdlib.h>

int isSequence(int a[], int size) {
    int i, sub;

    sub = a[1] - a[0];
    for (i = 1; i < size-1; i++) {
        if (a[i+1] - a[i] != sub) return 0;
    }
    return 1;
}

int main() {
    int n, i;
    int *a;

    scanf("%d", &n);
    a = (int*)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("%d\n", isSequence(a, n));

    free(a);
    return 0;
}