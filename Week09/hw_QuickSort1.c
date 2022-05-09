#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student {
    int id;
    int korean, english, math;
};

int partition(struct Student *std, int p, int r) {
    int i, j, t;

    j = p; i = p-1;
    for ( ; j < r; j++) {
        if (std[j].korean > std[r].korean) {
            i++;
            t = std[i].korean;
            std[i].korean = std[j].korean;
            std[j].korean = t;
        }
    }

    i++;
    t = std[i].korean;
    std[i].korean = std[r].korean;
    std[r].korean= t;

    return i;
}

void quickSort(struct Student *std, int p, int r) {
    int q;
    if (p < r) {
        q = partition(std, p, r);
        quickSort(std, p, q-1);
        quickSort(std, q+1, r);
    }
    return;
}

int main() {
    int n, i;
    struct Student *std;

    scanf("%d", &n);
    std = (struct Student*)malloc(sizeof(struct Student)*n);
    
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        std[i].id = i+1;
        std[i].english = rand() % 101;
        std[i].korean = rand() % 101;
        std[i].math = rand() % 101;
    }

    for (i = 0; i < n; i++) {
        printf("학번: %3d\t국어: %3d\t수학: %3d\t영어: %3d\n", std[i].id, std[i].korean, std[i].math, std[i].english);
    }
    
    quickSort(std, 0, n-1);
    printf("\n<국어 성적 기준으로 오름차순 정렬>\n");
    for (i = 0; i < n; i++) {
        printf("학번: %3d\t국어: %3d\t수학: %3d\t영어: %3d\n", std[i].id, std[i].korean, std[i].math, std[i].english);
    }

    free(std);
    return 0;
}