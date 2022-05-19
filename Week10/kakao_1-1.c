#include <stdio.h>
#include <stdlib.h>

int main() {
    char s[999];
    char newS[999];
    char alp;
    int i, j = 0, cnt = 1;

    scanf("%s", s);

    alp = s[0];
    for (i = 1; s[i-1] != '\0'; i++) {
        if (alp == s[i]) {
            cnt++;
            continue;
        }
        else {
            if (cnt > 1)
                newS[j++] = cnt+'0';

            cnt = 1;
            newS[j++] = alp;
            alp = s[i];
        }
    }
    newS[j] = '\0';

    printf("%s\n", newS);
    printf("%d\n", j);

    return 0;
}