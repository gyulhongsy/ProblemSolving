#include <stdio.h>

void pick(int n, int* bucket, int bucketSize, int k) {
    int i, lastIndex, smallest, item;

    if (k == 0) {
        for (i = 0; i < bucketSize; i++)
            printf("%d ", bucket[i]);
        printf("\n");
        return;
    }

    lastIndex = bucketSize - k - 1; //�??�� 최근?�� 뽑힌 ?���? ????��?�� ?���? index

    smallest = 0;

    for (item = smallest; item < n; item++) {
        bucket[lastIndex + 1] = item;
        pick(n, bucket, bucketSize, k - 1);
    }
}

int main() {
    int n = 5; //0~(n-1) item
    int bucket[3]; //몇개�? 뽑아 ?��?�� ?�� ?��?�� 공간

    pick(n, bucket, 3, 3); //item?���?, ?��?�� 곳과 ?���?, 뽑는 �??��
}