#include <stdio.h>
#include <stdlib.h>

int comb(int n, int r, int **m) {
    printf("comb(%d,%d)\n", n, r);
    if (m[n][r] != -1)
        return m[n][r];
    else {
        if (r == 0 || r == n)
            m[n][r] = 1;
        else
            m[n][r] = comb(n-1, r-1, m) + comb(n-1, r, m);
        return m[n][r];
    }
}

int main() {
    int n, r;
    int c, i, j;
    int **m;

    scanf("%d %d", &n, &r);

    m = (int**)malloc(sizeof(int*)*(n+1));
    for (i = 0; i <= n; i++)
        m[i] = (int*)malloc(sizeof(int)*(r+1));
    for (i = 0; i <= n; i++)
        for (j = 0; j <= r; j++)
            m[i][j] = -1;

    c = comb(n, r, m);
    printf("%d\n", c);

    return 0;
}