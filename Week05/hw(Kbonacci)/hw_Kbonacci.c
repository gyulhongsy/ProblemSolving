#include <stdio.h>

int k_bonacci(int k, int n) {
    int i, result = 0;
    if (n >= 1 && n <= k) return 1;

    for (i = 1; i <= k; i++)
        result += k_bonacci(k, n-i);
        
    return result;
}

int main() {
    int k, n;

    scanf("%d %d", &k, &n);
    printf("%d\n", k_bonacci(k, n));
}