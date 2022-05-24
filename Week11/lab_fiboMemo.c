#include <stdio.h>
#include <stdlib.h>

int fib(int n, int *F) {
    if (n == 1 || n == 2) return 1;
    if (F[n-1] == 0)
        F[n-1] = fib(n-1, F);

    if (F[n-2] == 0)
        F[n-2] = fib(n-2, F);

    return F[n-1] + F[n-2];
}

int main() {
    int n, i;
    int *F;

    printf("몇 번째까지의 피보나치 수열: ");
    scanf("%d", &n);

    F = (int*)malloc(sizeof(int)*(n+1));
    for (i = 1; i <= n; i++)
        F[i] = 0;

    for (i = 1; i <= n; i++)
        printf("%d ", fib(i, F));
    printf("\n");
    
    free(F);
    return 0;
}