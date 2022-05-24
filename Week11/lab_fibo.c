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
    int *F; //memo

    printf("입력: ");
    scanf("%d", &n); //fn

    //memo 초기화
    F = (int*)malloc(sizeof(int)*(n+1));
    for (i = 1; i <= n; i++)
        F[i] = 0;

    printf("%d\n", fib(n, F));
    
    free(F);
    return 0;
}