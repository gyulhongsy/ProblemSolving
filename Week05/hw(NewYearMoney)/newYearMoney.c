#include <stdio.h>
#include <stdlib.h>

void pick(int *bill, int n, int* picked, int pickedSize, int toPick, int money, int current_money) {
    int i, lastIndex, smallest;
    int picked_index;

    lastIndex = pickedSize - toPick - 1;

    if (current_money == money) {
        for (i = 0; i <= lastIndex; i++) {
            picked_index = picked[i];
            if (bill[picked_index] != 0)
                printf("%d ", bill[picked_index]);
            current_money += bill[picked_index];
        }
        printf("\n");
    }

    if (current_money > money || toPick == 0) return;

    if (pickedSize == toPick) smallest = 0;
    else smallest = picked[lastIndex];

    for (i = smallest; i < n; i++) {
        picked[lastIndex+1] = i;
        pick(bill, n, picked, pickedSize, toPick - 1, money, current_money+bill[i]);
    }
}

int main() {
    int bill[3] = { 1000, 5000, 10000};
    int money, n;
    int* picked;

    scanf("%d", &money);

    n = money / bill[0];
    picked = (int*)malloc(sizeof(int) * n);

    pick(bill, 3, picked, n, n, money, 0);

    free(picked);
    return 0;
}