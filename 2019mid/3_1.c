#include <stdio.h>

int solution(int n) {
    int i, cnt = 0;
    for (i = n; i > 0; i /=10) cnt++;
    return cnt;
}

int main() {
    int n;

    scanf("%d", &n);

    printf("%d\n", solution(n));
}