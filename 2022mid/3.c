#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char src_s[], char s[]) {
    int i, len;

    len = strlen(src_s);
    for (i = 0; i < len; i++)
        s[i] = src_s[len - i - 1];
    s[len] = '\0';
}

int main() {
    char n1[10], n2[10];
    char s1[10], s2[10];
    int len1, len2;
    int i, minusCarry = 0;

    scanf("%s %s", n1, n2);
    for (len1 = 0; n1[len1] != '\0'; len1++);
    for (len2 = 0; n2[len2] != '\0'; len2++);
    reverse(n1, s1);
    reverse(n2, s2);

    for (i = 0; i < len1; i++) {
        if (i < len2 && s1[i] == 47) {
            s1[i] = '9';
            s1[i + 1]--;
        }

        if (i >= len2 && s1[i] == 47) {
            s1[i + 1]--;
            minusCarry++;
        }

        if (((int)s1[i] - 48) - ((int)s2[i] - 48) < 0) {
            s1[i + 1]--;
            minusCarry++;
        }
        else continue;
    }

    printf("%d\n", minusCarry);

    return 0;
}