#include <stdio.h>
#include <stdlib.h>

int main() {
    char s[999] = { 47 };
    char newS[999];
    char alp[2];
    int i, j = 0, cnt = 0, len = 0;

    scanf("%s", s);
    for (len = 0; s[len] != '\0'; len++);

    newS[0] = 47;
    alp[0] = s[0]; alp[1] = s[1];
    for (i = 1; s[i-1] != '\0'; i += 2) {
        if (alp[0] == s[i - 1] && alp[1] == s[i]) {
            cnt++;
            continue;
        }
        else {
            if (cnt > 1) {
                if (cnt > 9) {
                    newS[j++] = (cnt/10) + '0';
                    cnt %= 10;
                }
                newS[j++] = cnt + '0';
            }

            cnt = 1;
            newS[j++] = alp[0];
            newS[j++] = alp[1];
            alp[0] = s[i - 1]; alp[1] = s[i];
        }
    }
    if (newS[0] == 47) {
        if (cnt > 1) {
            if (cnt > 9) {
                newS[j++] = (cnt/10) + '0';
                cnt %= 10;
            }
            newS[j++] = cnt + '0';
        }

        cnt = 1;
        newS[j++] = alp[0];
        newS[j++] = alp[1];
        alp[0] = s[i - 1]; alp[1] = s[i];
    }
    if (len % 2 == 1) {
        newS[j++] = s[len - 1];
    }
    newS[j] = '\0';

    printf("%s\n", newS);
    printf("%d\n", j);

    return 0;
}