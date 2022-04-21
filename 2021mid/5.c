#include <stdio.h>
#include <stdlib.h>

void pick(int* num, int numSize, int* picked, int pickedSize, int toPick, int* cnt) {
    int i, j, lastIndex;

    if (toPick == 0) {
        int num_index, key_index = 0, sum = 0;
        for (i = 0; i < numSize; i++) {
            for (j = 0; j < pickedSize; j++) {
                num_index = picked[j];
                if (num[num_index] == num[i]) break;
            }

            if (j == pickedSize) {
                key_index = i;
                break;
            }
        }
        for (i = 0; i < pickedSize; i++) {
            num_index = picked[i];
            sum = (sum * 10) + num[num_index];
        }

        if (sum % num[key_index] == 0) (*cnt)++;
        return;
    }

    lastIndex = pickedSize - toPick - 1;

    for (i = 0; i < numSize; i++) {
        int flag = 0;
        for (j = 0; j < lastIndex + 1; j++)
            if (i == picked[j]) flag = 1;
        if (flag == 1) continue;

        picked[lastIndex + 1] = i;
        pick(num, numSize, picked, pickedSize, toPick - 1, cnt);
    }
}

int main() {
    int* num;
    int* picked;
    int n, cnt = 0;

    scanf("%d", &n);

    picked = (int*)malloc(sizeof(int) * n);
    num = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    pick(num, n, picked, n - 1, n - 1, &cnt);
    printf("%d\n", cnt);

    free(num);
    free(picked);
    return 0;
}