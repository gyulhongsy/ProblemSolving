#include <stdio.h>
#include <stdlib.h>

char opr[2] = "+-";

void pick(int n, int* picked, int pickedSize, int toPick) {
    int i, j, index, lastIndex, oprIndex, sum = 0;

    if (toPick == 0) {
        i = 0; j = 1; index = 0;
        while (j <= pickedSize) {
            if (i % 2 == 0) {
                oprIndex = picked[index];
                printf("%c", opr[oprIndex]);
                index++;

                if (opr[oprIndex] == '+')
                    sum += j;
                else sum -= j;
            }
            else {
                printf("%d", j);
                j++;
            }
            i++;
        }
        printf(" = %d\n", sum);
        return;
    }

    lastIndex = pickedSize - toPick - 1;

    for (i = 0; i < n; i++) {
        picked[lastIndex + 1] = i;
        pick(n, picked, pickedSize, toPick - 1);
    }
}

int main() {
    int n = 2, m;
    int* picked;

    scanf("%d", &m);
    picked = (int*)malloc(sizeof(int) * m);

    pick(n, picked, m, m);

    free(picked);
}