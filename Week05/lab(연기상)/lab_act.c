#include <stdio.h>

void pick(char *itmes[], int n, int picked[], int m, int toPick) {
    int i, lastIndex, picked_index;

    if (toPick == 0) {
        for (i = 0; i < m; i++) {
            picked_index = picked[i];
            printf("%s ", itmes[picked_index]);
        }
        printf("\n");
        return;
    }

    lastIndex = m - toPick - 1;

    for (i = 0; i < n; i++) {
        int j, flag = 0;
        for (j = 0; j <= lastIndex; j++) 
            if (picked[j] == i) flag = 1;

        if (flag == 1) continue;

        picked[lastIndex+1] = i;
        pick(itmes, n, picked, m, toPick-1);
    }
}

int main() {
    char *items[] = {"공유", "김수현", "송중기", "지성", "현빈"};
    int n = 5;
    int picked[2];

    pick(items, n, picked, 2, 2);
}