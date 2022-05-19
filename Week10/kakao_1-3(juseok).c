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
        strncpy(std, s, i); //복사하여 기준 문자열 만들기
        std[i] = '\0';

        len = 0;
        for (j = i; j < sLen; j += i) {
            idx = 0;
            while (idx < i) //cut에는 자를 문자열의 길이만큼 기존 문자열에서 떼와서 저장
                cut[idx++] = s[j+idx];
            cut[idx] = '\0';

            if (strcmp(std, cut) == 0)
                cnt++; //기준과 자른 문자열이 같으면 cnt올려줌
            else { //다르면 cnt를 1로 초기화시켜주고 새로운 기준 문자열 만들어주기
                if (cnt > 1) {
                    for (k = cnt; k > 0; k /= 10)
                        len++; //cnt가 1보다 크면 cnt자리수만큼 길이 차지
                }
                len += i; //자른 문자열의 길이만큼 len증가
                cnt = 1;

                strncpy(std, s+j, i);
                std[i] = '\0';
            }
        }
        if (cnt > 1) { //뒷부분 이어서 해주기
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