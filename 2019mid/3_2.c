#include <stdio.h>

int solution(int n) {
    int i, cnt = 0;
    for (i = n; i > 0; i /= 10) cnt++;
    return cnt;
}

int main() {
    int n, jarisu, i = 0, j, k = 1;
    int num, N = 0, div;

    scanf("%d", &n);

    while (i < n) {
        num = 3 * k;
        jarisu = solution(num);

        if (jarisu > 1) {
            div = 1;
            for (j = 0; j < jarisu - 1; j++) div *= 10;

            for (j = 0; j < jarisu; j++) {
                N = num / div;
                num %= div;
                div /= 10;
                i++;
                if (i == n) break;
            }
        }
        else {
            N = num;
            i++;
        }
        k++;
    }

    printf("%d\n", N);
}

// 자리수 리턴받은 만큼 for문 돌면서 앞에서부터 한자리씩 출력
// 전체적으로는 입력받은 수만큼 for문을 돈다
// 출력하지 않고 수를 저장. 마지막에 출력