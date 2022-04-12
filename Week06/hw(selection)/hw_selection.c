#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student {
    int id;
    int korean, english, math;
};

void selection_sort(struct Student *std, int n) {
    int i, j, min, min_idx;
    struct Student temp;

    for (i = 0; i < n-1; i++) {
        min = std[0].korean; min_idx = 0;
        for (j = 0; j < n-i; j++) {
            if (std[j].korean < min) {
                min = std[j].korean;
                min_idx = j;
            }
        }
        temp = std[n-i-1];
        std[n-i-1] = std[min_idx];
        std[min_idx] = temp;
    }
    return;
}

int main() {
    int n, i;
    struct Student *std;
    srand(time(NULL));

    printf("�л� ���� �Է��ϼ���: ");
    scanf("%d", &n);
    std = (struct Student*)malloc(sizeof(struct Student)*n);

    for (i = 0; i < n; i++) {
        std[i].id = i+1;
        std[i].korean = rand() % 100 + 1;
        std[i].english = rand() % 100 + 1;
        std[i].math = rand() % 100 + 1;
    }

    for (i = 0; i < n; i++) {
        printf("�й�: %3d\t����: %3d\t����: %3d\t����: %3d\n", std[i].id, std[i].korean, std[i].math, std[i].english);
    }
    
    selection_sort(std, n);
    printf("\n<���� ���� �������� �������� ����>\n");
    for (i = 0; i < n; i++) {
        printf("�й�: %3d\t����: %3d\t����: %3d\t����: %3d\n", std[i].id, std[i].korean, std[i].math, std[i].english);
    }

    free(std);
}
