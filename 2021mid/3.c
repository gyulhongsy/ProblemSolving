#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, start, i, j;
    char ladder[999][999];

    scanf("%d %d", &n, &m);
    scanf("%d", &start);

    for (i = 0; i < m; i++) {
        scanf("%s", ladder[i]);
    }

    i = 0; j = start;
    while (i < m) {
        if (ladder[i][j] == '1') j++;
        else if (j != 0 && ladder[i][j - 1] == '1') j--;
        i++;
    }

    printf("%d\n", j);

    return 0;
}