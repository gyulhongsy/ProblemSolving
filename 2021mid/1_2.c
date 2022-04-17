#include <stdio.h>
#include <string.h>

void reverse(char src_s[], char s[]) {
    int i, len;

    len = strlen(src_s);
    for (i = 0; i < len; i++)
        s[i] = src_s[len - i - 1];
    s[len] = '\0';
}

int main() {
    char n1[101], n2[101];
    char s1[101], s2[101];
    int len, s1Len, s2Len, i;
    int sum, carry = 0, cnt = 0;

    scanf("%s", n1);
    reverse(n1, s1);
    s1Len = strlen(s1);

    scanf("%s", n2);
    reverse(n2, s2);
    s2Len = strlen(s2);

    if (s1Len >= s2Len) len = s1Len;
    else len = s2Len;

    for (i = 0; i < len; i++) {
        sum = 0;
        if (s1Len <= i)
            sum = carry + (int)(s2[i] - 48);
        else if (s2Len <= i)
            sum = carry + (int)(s1[i] - 48);
        else
            sum = carry + (int)(s1[i] - 48) + (int)(s2[i] - 48);

        if (sum >= 10) {
            carry = 1;
            cnt++;
        }
        else carry = 0;
    }

    printf("%d\n", cnt);
}