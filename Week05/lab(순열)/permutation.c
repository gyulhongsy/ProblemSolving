#include <stdio.h>

void pick(int n, int* bucket, int bucketSize, int k) {
    int i, lastIndex, smallest, item;

    if (k == 0) {
        for (i = 0; i < bucketSize; i++)
            printf("%d ", bucket[i]);
        printf("\n");
        return; 
    }

    lastIndex = bucketSize - k - 1; //가장 최근에 뽑힌 수가 저장된 위치 index
    smallest = 0;

    for (item = smallest; item < n; item++) {
        int flag = 0;
        for (i = 0; i <lastIndex+1; i++)
            if (item == bucket[i]) flag = 1;
        
        if (flag == 1) continue;

        bucket[lastIndex+1] = item;
        pick(n, bucket, bucketSize, k-1);
    }
}

int main() {
    int n = 5; //0~(n-1) item
    int bucket[3]; //몇개를 뽑아 담을 수 있는 공간

    pick(n, bucket, 3, 3); //item정보, 담을 곳과 크기, 뽑는 갯수
}