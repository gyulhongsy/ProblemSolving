#include <stdio.h>
#include <stdlib.h>

int main() {
    char num[50];

    scanf("%s", num);

    if (atoi(num) % 2 != 0)
        printf("0\n");
    else printf("1\n");
}