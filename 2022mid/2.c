#include <stdio.h>

void jinbub(int n, int k, int num[], int* len) {
    if (n == 0) return;
    else {
        jinbub(n / k, k, num, len);
        num[*len] = n % k;
        (*len)++;
    }
}

int main() {
    int n, k;
    int i, len = 0;
    int num[999];
    int flag = 1;

    scanf("%d %d", &n, &k);

    jinbub(n, k, num, &len);

    for (i = 0; i < len / 2; i++) {
        if (num[i] != num[len - i - 1]) {
            flag = 0;
            break;
        }
    }
    printf("%d\n", flag);

    return 0;
}