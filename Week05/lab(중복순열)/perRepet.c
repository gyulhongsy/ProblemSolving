#include <stdio.h>

void pick(int n, int* bucket, int bucketSize, int k) {
    int i, lastIndex, smallest, item;

    if (k == 0) {
        for (i = 0; i < bucketSize; i++)
            printf("%d ", bucket[i]);
        printf("\n");
        return;
    }

    lastIndex = bucketSize - k - 1; //ê°??ž¥ ìµœê·¼?— ë½‘ížŒ ?ˆ˜ê°? ????ž¥?œ ?œ„ì¹? index

    smallest = 0;

    for (item = smallest; item < n; item++) {
        bucket[lastIndex + 1] = item;
        pick(n, bucket, bucketSize, k - 1);
    }
}

int main() {
    int n = 5; //0~(n-1) item
    int bucket[3]; //ëª‡ê°œë¥? ë½‘ì•„ ?‹´?„ ?ˆ˜ ?žˆ?Š” ê³µê°„

    pick(n, bucket, 3, 3); //item? •ë³?, ?‹´?„ ê³³ê³¼ ?¬ê¸?, ë½‘ëŠ” ê°??ˆ˜
}