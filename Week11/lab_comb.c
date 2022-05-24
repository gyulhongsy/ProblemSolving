#include <stdio.h>

int comb(int n, int r) {
    printf("comb(%d,%d)\n", n, r);
    if (r == 0 || r == n) return 1;
    else {
        return comb(n-1, r-1) + comb(n-1, r);
    }
}

int main() {
    int c;

    c = comb(10, 4);
    printf("%d\n", c);

    return 0;
}