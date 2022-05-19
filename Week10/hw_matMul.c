#include <stdio.h>
#include <stdlib.h>

void readMatrix(int **a, int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    return;
}

void printMatrix(int **a, int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
    return;
}

void matrixMul(int **a, int **b, int m, int n, int p) {
    int i, j, k, sum = 0;
    int **x;

    x = (int**)malloc(sizeof(int*)*m);
    for (i = 0; i < m; i++)
        x[i] = (int*)malloc(sizeof(int)*p);

    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            for (k = 0; k < n; k++) 
                sum += a[i][k]+b[k][j];
            x[i][j] = sum;
        }
    }
    printMatrix(x, m, p);
    return;   
}

int main() {
    int **a, **b, **c;
    int m, n, p;
    int i, j;

    printf("Enter 행렬 A의 행과 열의 개수: ");
    scanf("%d %d", &m, &n);
    printf("Enter 행렬 c의 행과 열의 개수(C의 행은 A의 열과 같아야): ");
    scanf("%d %d", &n, &p);

    a = (int**)malloc(sizeof(int*)*m);
    b = (int**)malloc(sizeof(int*)*n);
    c = (int**)malloc(sizeof(int*)*n);

    for (i = 0; i < m; i++)
        a[i] = (int*)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++) {
        b[i] = (int*)malloc(sizeof(int)*m);
        c[i] = (int*)malloc(sizeof(int)*p);
    }

    printf("\n%d X %d 행렬 A 입력:\n", m, n);
    readMatrix(a, m, n);
    printf("\n%d X %d 행렬 C 입력:\n", n, p);
    readMatrix(c, n, p);

    printf("\n행렬곱:\n");
    matrixMul(a, c, m, n, p);

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            b[i][j] = a[j][i];
    printf("\n전치행렬: \n");
    printMatrix(b, n, m);

    for (i = 0; i < m; i++)
        free(a[i]);
    for (i = 0; i < n; i++) {
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);

    return 0;
}