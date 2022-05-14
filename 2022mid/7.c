#include <stdio.h>
#include <stdlib.h>

int isSequence(int a[], int size) {
    int i, sub;

    sub = a[1] - a[0];
    for (i = 1; i < size - 1; i++) {
        if (a[i + 1] - a[i] != sub) return 0;
    }
    return 1;
}

void pick(int* item, int* a, int n, int* bucket, int bucketSize, int toPick, int* min, int *flag) {
    int i, lastIndex;

    if (toPick == 0) {
        int item_index, cnt = 0;
        int newA[999];
        for (i = 0; i < bucketSize; i++) newA[i] = a[i];
        for (i = 0; i < bucketSize; i++) {
            item_index = bucket[i];
            newA[i] = a[i] + item[item_index];
            if (item[item_index] != 0) cnt++;
        }
        if (isSequence(newA, bucketSize)) {
            *flag = 1;
            if (cnt <= *min) *min = cnt;
        }
        return;
    }

    lastIndex = bucketSize - toPick - 1;

    for (i = 0; i < n; i++) {
        bucket[lastIndex + 1] = i;
        pick(item, a, n, bucket, bucketSize, toPick - 1, min, flag);
    }
}

int main() {
    int item[] = { -1, 0, 1 };
    int n, i, cnt = 0;
    int flag = 0, min = 999;
    int* a;
    int* buket;

    scanf("%d", &n);
    a = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    buket = (int*)malloc(sizeof(int) * n);

    pick(item, a, 3, buket, n, n, &min, &flag);

    if (flag == 1)
        printf("%d\n", min);
    else printf("-1\n");

    free(buket);
    return 0;
}