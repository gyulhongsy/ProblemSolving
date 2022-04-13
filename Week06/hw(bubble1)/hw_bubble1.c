#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student {
    int id;
    int korean, english, math;
};

void bubbleSortDescendingByKorean (struct Student *std, int n) {
    int i, j;
    struct Student temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (std[j].korean < std[j+1].korean) {
                temp = std[j+1];
                std[j+1] = std[j];
                std[j] = temp;
            }
        }
    }
}

void bubbleSortAscendingById (struct Student *std, int n) {
    int i, j;
    struct Student temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (std[j].id > std[j+1].id) {
                temp = std[j+1];
                std[j+1] = std[j];
                std[j] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    struct Student *std;
    srand(time(NULL));

    printf("학생 수를 입력하세요: ");
    scanf("%d", &n);
    std = (struct Student*)malloc(sizeof(struct Student)*n);

    for (i = 0; i < n; i++) {
        std[i].id = i+1;
        std[i].korean = rand() % 100 + 1;
        std[i].english = rand() % 100 + 1;
        std[i].math = rand() % 100 + 1;
    }
    for (i = 0; i < n; i++) {
        printf("학번: %3d\t국어: %3d\t수학: %3d\t영어: %3d\n", std[i].id, std[i].korean, std[i].math, std[i].english);
    }
    
    bubbleSortDescendingByKorean(std, n);
    printf("\n<국어 성적 기준으로 내림차순 정렬>\n");
    for (i = 0; i < n; i++) {
        printf("학번: %3d\t국어: %3d\t수학: %3d\t영어: %3d\n", std[i].id, std[i].korean, std[i].math, std[i].english);
    }

    bubbleSortAscendingById(std, n);
    printf("\n<학번 순으로 오름차순 정렬>\n");
    for (i = 0; i < n; i++) {
        printf("학번: %3d\t국어: %3d\t수학: %3d\t영어: %3d\n", std[i].id, std[i].korean, std[i].math, std[i].english);
    }

    free(std);
}
