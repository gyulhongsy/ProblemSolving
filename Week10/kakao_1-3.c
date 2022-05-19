#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    char std[1000];
    char cut[1000];
    int sLen, len, cnt = 1;
    int i, j, k, idx, min = 999;

    scanf("%s", s);
    sLen = strlen(s);

    for (i = 1; i <= sLen / 2; i++) {
        strncpy(std, s, i);
        std[i] = '\0';

        len = 0;
        for (j = i; j < sLen; j += i) {
            idx = 0;
            while (idx < i)
                cut[idx++] = s[j+idx];
            cut[idx] = '\0';

            if (strcmp(std, cut) == 0)
                cnt++;
            else {
                if (cnt > 1) {
                    for (k = cnt; k > 0; k /= 10)
                        len++;
                }
                len += i;
                cnt = 1;

                strncpy(std, s+j, i);
                std[i] = '\0';
            }
        }
        if (cnt > 1) {
            for (k = cnt; k > 0; k /= 10)
                len++; 
        }
        if (sLen%i != 0) {
            for (k = j-i; s[k] != '\0'; k++)
                len++;
        } else {
            len += i; 
            cnt = 1;
        }

        if (len < min)
            min = len;
    }
    printf("%d\n", min);

    return 0;
}