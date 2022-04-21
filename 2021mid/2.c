#include <stdio.h>

int main() {
    int n, mul;
    int i, jarisu = 0, div = 1;

    scanf("%d", &n);
    mul = n * 9;

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    for (i = mul; i > 0; i /= 10) jarisu++;
    for (i = 0; i < jarisu-1; i++) div *= 10;

    for (i = 0; i < jarisu; i++) {
        printf("%d ", mul / div);
        mul %= div;
        div /= 10;
    }
    printf("\n");

    return 0;
}