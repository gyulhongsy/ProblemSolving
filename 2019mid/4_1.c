#include <stdio.h>
#include <stdlib.h>

char opr[2] = "+-";
int flag = 0;

void pick(int n, int* picked, int pickedSize, int toPick, int key) {
    int i, j, index, lastIndex, oprIndex, sum = 0;

    if (toPick == 0) {
        i = 0; j = 1; index = 0;
        while (j <= pickedSize) {
            if (i % 2 == 0) {
                oprIndex = picked[index];
                index++;

                if (opr[oprIndex] == '+')
                    sum += j;
                else sum -= j;
            }
            else j++;
            i++;
        }
        if (key == sum) flag = 1;
        return;
    }

    lastIndex = pickedSize - toPick - 1;

    for (i = 0; i < n; i++) {
        picked[lastIndex + 1] = i;
        pick(n, picked, pickedSize, toPick - 1, key);
    }
}

int main() {
    int n = 2, m, key;
    int* picked;

    scanf("%d %d", &m, &key);
    picked = (int*)malloc(sizeof(int) * m);

    pick(n, picked, m, m, key);
    if (flag == 1) printf("1\n");
    else printf("0\n");

    free(picked);
}