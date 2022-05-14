#include <stdio.h>

int minusCarry(int n1, int n2) {
    int carry_count = 0;
    int carry;

    while (n2 != 0) {
        int t1 = n1 % 10;
        int t2 = n2 % 10;

        if (t1-t2 < 0) {
            if (t1 == 0) {
                int temp = n1;
                while (temp % 10 == 0) {
                    carry_count++;
                    temp /= 10;
                }
            }
            else {
                carry_count++;
                n1 -= 10;
            }
        }
        n1 /= 10;
        n2 /= 10;
    }
    return carry_count;
}

int main() {
    int n1, n2;
        
    scanf("%d %d", &n1, &n2);
    printf("%d\n", minusCarry(n1, n2));

    return 0;
}