#include <stdio.h>
#include <stdlib.h>

int matrixPath_memo(int **m, int **M1, int **M2, int i, int j) {
    if (M2[i][j] == 1) return M1[i][j];
    if (i == 0 && j == 0) return m[i][j];
    else if (i == 0) {
        M1[i][j] = matrixPath_memo(m, M1, M2, i, j-1) + m[i][j];
        M2[i][j] = 1;
    }
    else if (j == 0) {
        M1[i][j] = matrixPath_memo(m, M1, M2, i-1, j) + m[i][j];
        M2[i][j] = 1;
    }
    else {
        int a, b;
        a = matrixPath_memo(m, M1, M2, i-1, j);
        b = matrixPath_memo(m, M1, M2, i, j-1);

        M1[i][j] = ((a < b) ? a : b) + m[i][j];
        M2[i][j] = 1;
    }
    return M1[i][j];
}

int main() {
    int **m, **M1, **M2;
    int i, j, r, c;

    scanf("%d %d", &r, &c);
    m = (int**)malloc(sizeof(int*)*r);
    M1 = (int**)malloc(sizeof(int*)*r);
    M2 = (int**)malloc(sizeof(int*)*r);
    for (i = 0; i < r; i++) {
        m[i] = (int*)malloc(sizeof(int)*c);
        M1[i] = (int*)malloc(sizeof(int)*c);
        M2[i] = (int*)malloc(sizeof(int)*c);
    }

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            scanf("%d", &m[i][j]);
            M1[i][j] = 0;
            M2[i][j] = 0; //계산 안되어있으면 0, 되어있으면 1;
        }
    printf("%d\n", matrixPath_memo(m, M1, M2, r-1, c-1));

    for (i = 0; i < r; i++) {
        free(m[i]);
        free(M1[i]);
        free(M2[i]);
    }
    free(m);
    free(M1);
    free(M2);

    return 0;
}