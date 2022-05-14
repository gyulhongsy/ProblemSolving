#include <stdio.h>

void jinbub(int n, int k) {
    if (n == 0) return;
    else {
        jinbub(n / k, k);
        printf("%d ", n % k);
    }
}

int main() {
    int n, k;
    int i, len = 0;

    scanf("%d %d", &n, &k);

    jinbub(n, k);

    return 0;
}