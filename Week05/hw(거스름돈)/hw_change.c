#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int coin[4] = { 10, 50, 100, 500 };
int cnt = 0;

void pick(int n, int* picked, int pickedSize, int toPick, int money, int total, int len) {
    int i, lastIndex, smallest, coin_index;

    if (total == money) {
        cnt++;
        return;
    }

    lastIndex = pickedSize - toPick - 1;

    if (pickedSize == toPick) smallest = 0;
    else smallest = picked[lastIndex];

    if (money - total >= 500) n = 4;
    else if (money - total >= 100) n = 3;
    else if (money - total >= 50) n = 2;
    else if (money - total >= 10) n = 1;

    for (i = smallest; i < n; i++) {
        picked[lastIndex + 1] = i;
        coin_index = picked[lastIndex + 1];
        pick(n, picked, pickedSize, toPick - 1, money, total + coin[coin_index], len + 1);
    }
}

int main() {
    int n = 4;
    int money, m;
    int* picked;

    scanf("%d", &money);
    if (money == 0 || money % 10 != 0) {
        printf("0\n");
        return 0;
    }
    m = money / 10;
    picked = (int*)malloc(sizeof(int) * m);

    pick(n, picked, m, m, money, 0, 0);
    printf("%d\n", cnt);
}