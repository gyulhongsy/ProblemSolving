#include <stdio.h>
#include <stdlib.h>

int pick(int *coin, int n, int* picked, int pickedSize, int toPick, int money, int current_money) {
    int i, lastIndex, smallest;
    int ret = 0;
    int picked_index;

    lastIndex = pickedSize - toPick - 1;

    if (money == current_money) return 1;
    if (toPick == 0 || current_money > money) return 0; 

    if (pickedSize == toPick) smallest = 0;
    else smallest = picked[lastIndex];

    for (i = smallest; i < n; i++) {
        picked[lastIndex+1] = i;
        ret += pick(coin, n, picked, pickedSize, toPick - 1, money, current_money+coin[i]);
    }

    return ret;
}

int main() {
    int coin[4] = {10, 50, 100, 500};
    int money, n;
    int* picked;
    int ret;

    scanf("%d", &money);

    n = money / coin[0];
    picked = (int*)malloc(sizeof(int) * n);

    ret = pick(coin, 4, picked, n, n, money, 0);
    printf("%d\n", ret);

    free(picked);
    return 0;
}