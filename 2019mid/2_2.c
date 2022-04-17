#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char num[50];
    int len, n, i;
    int mul[4] = { 0, 0, 0, 0 };

    scanf("%s", num);
    len = strlen(num);

    if (atoi(num) == 0) {
        for (i = 0; i < 4; i++)
            printf("%d", mul[i]);
        printf("\n");
        return 0;
    }

    n = (int)(num[len - 1] - 48);
    if (n % 2 == 0) mul[0] = 1;
    if (n == 0 || n == 5) mul[3] = 1;

    n = 0;
    for (i = 0; i < len; i++)
        n += (int)(num[i] - 48);
    if (n % 3 == 0) mul[1] = 1;

    n = (int)(num[len - 2] - 48) * 10 + (int)(num[len - 1] - 48);
    if (n % 4 == 0) mul[2] = 1;

    for (i = 0; i < 4; i++)
        printf("%d", mul[i]);
    printf("\n");
}