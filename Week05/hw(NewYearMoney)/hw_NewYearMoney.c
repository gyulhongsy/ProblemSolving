#include <stdio.h>
#include <stdlib.h>

int bill[3] = { 1000, 5000, 10000 };

void pick(int n, int* picked, int pickedSize, int toPick, int money, int total, int len) {
    int i, lastIndex, smallest, bill_index;

    if (total == money) {
        for (i = len - 1; i >= 0; i--) {
            bill_index = picked[i];
            printf("%d ", bill[bill_index]);
        }
        printf("\n");
        return;
    }

    lastIndex = pickedSize - toPick - 1;

    if (pickedSize == toPick) smallest = 0;
    else smallest = picked[lastIndex];

    if (money - total >= 10000) n = 3;
    else if (money - total >= 5000) n = 2;
    else if (money - total >= 1000) n = 1;

    for (i = smallest; i < n; i++) {
        picked[lastIndex+1] = i;
        bill_index = picked[lastIndex+1];
        pick(n, picked, pickedSize, toPick - 1, money, total+bill[bill_index], len+1);
    }
}

int main() {
    int n = 3;
    int money, m;
    int* picked;

    scanf("%d", &money);
    m = money / 1000;
    picked = (int*)malloc(sizeof(int) * m);

    pick(n, picked, m, m, money, 0, 0);
}