#include <stdio.h>
#include <stdlib.h>

int flag = 0, last = 0;

void testPirint(int *a, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void pick(int n, int* b, int bSize, int toPick, int *a, int *c) {
    int i, j, lastIndex, smallest;

    if (toPick == 0) {
        for (i = 0; i < bSize; i++) {
            if (flag == 1 && last == 0) {
                testPirint(b, bSize);
                last = 1;
                return;
            }
            if (b[i] != a[i] && flag == 0)
                return;
        }
        if (i == bSize) {
            flag = 1;
            return;
        }
    }

    lastIndex = bSize - toPick - 1;

    if (bSize == toPick) smallest = 0;
    else smallest = b[lastIndex] + 1;

    for (i = smallest; i < n; i++) {
        b[lastIndex+1] = i;
        pick(n, b, bSize, toPick-1, a, c);
    }
}

int main() {
    int n, m;
    int *a, *b, *c;
    int i, j, k = -1;

    scanf("%d %d", &n, &m);
    a = (int*)malloc(sizeof(int)*m);
    b = (int*)malloc(sizeof(int)*m);
    c = (int*)malloc(sizeof(int)*m);

    for (i = 0; i < m; i++)
        scanf("%d", &a[i]);

    if (a[0] == n - m + 1) {
            printf("-1\n");
            return 0;
        }
    pick(n, b, m, m, a, c);

    free(a);
    free(b);
    free(c);
    return 0;
}