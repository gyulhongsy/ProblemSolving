#include <stdio.h>
#include <stdlib.h>

void pick(int *item, int n, int* picked, int pickedSize, int toPick, int* std, int* cnt) {
    int i, lastIndex;

    if (toPick == 0) {
        int item_index, sum = 0;
        for (i = 0; i < pickedSize; i++) {
            item_index = picked[i];
            sum += item[item_index] * std[i];
        }
        if (sum == 0) (*cnt)++;

        return;
    }

    lastIndex = pickedSize - toPick - 1;

    for (i = 0; i < n; i++) {
        picked[lastIndex + 1] = i;
        pick(item, n, picked, pickedSize, toPick - 1, std, cnt);
    }
}

int main() {
    int item[] = { -1, 0, 1 };
    int n, i;
    int* picked;
    int* std;
    int cnt = 0;

    scanf("%d", &n);

    picked = (int*)malloc(sizeof(int) * n);
    std = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        scanf("%d", &std[i]);

    pick(item, 3, picked, n, n, std, &cnt);

    printf("%d\n", cnt);

    free(picked);
    free(std);
    return 0;
}