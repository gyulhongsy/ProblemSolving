#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student {
    int id;
    int korean, english, math;
};

int partition(struct Student *std, int p, int r, int c) {
    int i, j;
    struct Student t;

    j = p; i = p-1;

    if (c == 1) {
        for ( ; j < r; j++) {
            if (std[j].korean > std[r].korean) {
                i++;
                t = std[i];
                std[i] = std[j];
                std[j] = t;
            }
        }
        i++;
        t = std[i];
        std[i] = std[r];
        std[r] = t;
    }
    else if (c == 2) {
        for ( ; j < r; j++) {
            if (std[j].math > std[r].math) {
                i++;
                t = std[i];
                std[i] = std[j];
                std[j] = t;
            }
        }
        i++;
        t = std[i];
        std[i] = std[r];
        std[r]= t;
    }
    else if (c == 3) {
        for ( ; j < r; j++) {
            if (std[j].english > std[r].english) {
                i++;
                t = std[i];
                std[i] = std[j];
                std[j] = t;
            }
        }
        i++;
        t = std[i];
        std[i] = std[r];
        std[r]= t;
    }
    else if (c == 4) {
        for ( ; j < r; j++) {
            if (std[j].id > std[r].id) {
                i++;
                t = std[i];
                std[i] = std[j];
                std[j] = t;
            }
        }
        i++;
        t = std[i];
        std[i] = std[r];
        std[r]= t;
    }
    return i;
}

void quickSort(struct Student *std, int p, int r, int c) {
    int q;
    if (p < r) {
        q = partition(std, p, r, c);
        quickSort(std, p, q-1, c);
        quickSort(std, q+1, r, c);
    }
    return;
}

void swap(struct Student *std, int n) {
    struct Student temp;
    for (int i = 0; i < n/2; i++) {
        temp = std[i];
        std[i] = std[n-i-1];
        std[n-i-1] = temp;
    }
    return;
}

int main() {
    int n, i, choice;
    struct Student *std;
    srand(time(NULL));

    printf("학생 수를 입력하세요: ");
    scanf("%d", &n);
    std = (struct Student*)malloc(sizeof(struct Student)*n);

    for (i = 0; i < n; i++) {
        std[i].id = i+1;
        std[i].korean = rand() % 101;
        std[i].english = rand() % 101;
        std[i].math = rand() % 101;
    }
    for (i = 0; i < n; i++) {
        printf("학번: %3d\t국어: %3d\t수학: %3d\t영어: %3d\n", std[i].id, std[i].korean, std[i].math, std[i].english);
    }
    
    printf("\n정렬 기준 선택 (1: 국어, 2: 수학, 3: 영어, 4: id(오름차순), 0: 끝내기): ");
    scanf("%d", &choice);
    while (1) {
        if (choice == 0) break;

        quickSort(std, 0, n-1, choice);
        if (choice == 4) swap(std, n);

        for (i = 0; i < n; i++) {
            printf("학번: %3d\t국어: %3d\t수학: %3d\t영어: %3d\n", std[i].id, std[i].korean, std[i].math, std[i].english);
        }

        printf("\n정렬 기준 선택 (1: 국어, 2: 수학, 3: 영어, 4: id(오름차순), 0: 끝내기): ");
        scanf("%d", &choice);
    }
    
    free(std);
    return 0;
}