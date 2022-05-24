#include <stdio.h>
#include <stdlib.h>

int matrixPath(int **m, int r, int c, int i, int j) {
    if (i == 0 && j == 0) return m[i][j];
    else if (i == 0)
        return matrixPath(m, r, c, 0, j-1) + m[i][j];
    else if (j == 0)
        return matrixPath(m, r, c, i-1, 0) + m[i][j];
    else {
        int a, b;
        a = matrixPath(m, r, c, i-1, j);
        b = matrixPath(m, r, c, i, j-1);
        return ((a < b) ? a : b) + m[i][j];
    }
}

int main() {
    int **m;
    int i, j, r, c;
    
    scanf("%d %d", &r, &c);
    m = (int**)malloc(sizeof(int*)*r);
    for (i = 0; i < r; i++)
        m[i] = (int*)malloc(sizeof(int)*c);

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &m[i][j]);

    printf("%d\n", matrixPath(m, r, c, r-1, c-1));

    for (i = 0; i < r; i++)
        free(m[i]);
    free(m);

    return 0;
}