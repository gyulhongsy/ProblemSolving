#include <stdio.h>
#include <stdlib.h>

char opr[2] = "+-";

void pick(int *item, int n, int* picked, int pickedSize, int toPick) {
    int i, lastIndex, sum = 0;

    if (toPick == 0) {
        int picked_index, sum = 0;
        for (i = 0; i < pickedSize; i++) {
            picked_index = picked[i];
            if (item[picked_index] == 1)
                printf("+%d", i+1);
            else if (item[picked_index] == -1)
                printf("-%d", i+1);
            sum += item[picked_index] * (i+1);
        }
        printf("=%d\n", sum);
        return;
    }

    lastIndex = pickedSize - toPick - 1;

    for (i = 0; i < n; i++) {
        picked[lastIndex + 1] = i;
        pick(item, n, picked, pickedSize, toPick - 1);
    }
}

int main() {
    int item[2] = {1, -1}; //1 = +, -1 = -;
    int n = 2, m;
    int* picked;

    scanf("%d", &m);
    picked = (int*)malloc(sizeof(int) * m);

    pick(item, n, picked, m, m);

    free(picked);
}