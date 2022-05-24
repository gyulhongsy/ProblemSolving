#include <stdio.h>
#include <stdlib.h>

int matrixPath_memo(int **m, int **M, int i, int j) {
    if (M[i][j] != 0) return M[i][j];
    if (i == 0 && j == 0) return m[i][j];
    else if (i == 0)
        M[i][j] = matrixPath_memo(m, M, i, j-1) + m[i][j];
    else if (j == 0)
        M[i][j] = matrixPath_memo(m, M, i-1, j) + m[i][j];
    else {
        int a, b;
        a = matrixPath_memo(m, M, i-1, j);
        b = matrixPath_memo(m, M, i, j-1);

        M[i][j] = ((a < b) ? a : b) + m[i][j];
    }
    return M[i][j];
}

int main() {
    int **m, **M;
    int i, j, r, c;

    scanf("%d %d", &r, &c);
    m = (int**)malloc(sizeof(int*)*r);
    M = (int**)malloc(sizeof(int*)*r);
    for (i = 0; i < r; i++) {
        m[i] = (int*)malloc(sizeof(int)*c);
        M[i] = (int*)malloc(sizeof(int)*c);
    }

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            scanf("%d", &m[i][j]);
            M[i][j] = 0;
        }
    printf("%d\n", matrixPath_memo(m, M, r-1, c-1));

    for (i = 0; i < r; i++) {
        free(m[i]);
        free(M[i]);
    }
    free(m);
    free(M);

    return 0;
}