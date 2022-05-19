#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *input;
    int i, j, sum, max = -1;

    scanf("%d", &n);
    input = (int*)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++)
        scanf("%d", &input[i]);

    for (i = 0; i < n; i++) {
        sum = 0;
        sum += input[i]+1;
        for (j = 0; j < n; j++) {
            if (j == i) continue;
            sum *= input[j];
        }
        if (sum > max)
            max = sum;
    }
    printf("%d\n", max);

    free(input);
    return 0;
}