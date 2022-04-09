#include <stdio.h>
#include <stdlib.h>

void pick(int n, int *num, int numSize, int toPick) {
    int i, lastIndex;

    if (toPick == 0) {
        for (i = 0; i < numSize; i++)
            printf("%d", num[i]);
        printf("\n");
        return;
    }

    lastIndex = numSize - toPick - 1;

    for (i = 0; i < n; i++) {
        num[lastIndex+1] = i;
        pick(n, num, numSize, toPick-1);
    }
}

int main() {
    int n = 4, m;
    int *num;

    scanf("%d", &m);
    num = (int*)malloc(sizeof(int) * m);

    pick(n, num, m, m);

    free(num);
}