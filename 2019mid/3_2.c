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

// �ڸ��� ���Ϲ��� ��ŭ for�� ���鼭 �տ������� ���ڸ��� ���
// ��ü�����δ� �Է¹��� ����ŭ for���� ����
// ������� �ʰ� ���� ����. �������� ���