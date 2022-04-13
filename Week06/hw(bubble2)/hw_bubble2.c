#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student {
    int id;
    int korean, english, math;
};

void bubble_sort (struct Student *std, int n, int c) {
    int i, j;
    struct Student temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            switch (c) {
            case 1:
                if (std[j].korean < std[j+1].korean) {
                    temp = std[j+1];
                    std[j+1] = std[j];
                    std[j] = temp;
                }
                break;
            case 2:
                if (std[j].math < std[j+1].math) {
                    temp = std[j+1];
                    std[j+1] = std[j];
                    std[j] = temp;
                }
                break;
            case 3:
                if (std[j].english < std[j+1].english) {
                    temp = std[j+1];
                    std[j+1] = std[j];
                    std[j] = temp;
                }
                break;
            case 4:
                if (std[j].id > std[j+1].id) {
                    temp = std[j+1];
                    std[j+1] = std[j];
                    std[j] = temp;
                }
            default:
                break;
            }
        }
    }
}

int main() {
    int n, i, choice;
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
    
    printf("\n���� ���� ���� (1: ����, 2: ����, 3: ����, 4: id(��������), 0: ������): ");
    scanf("%d", &choice);
    while (1) {
        if (choice == 0) break;

        bubble_sort(std, n, choice);
        for (i = 0; i < n; i++) {
            printf("�й�: %3d\t����: %3d\t����: %3d\t����: %3d\n", std[i].id, std[i].korean, std[i].math, std[i].english);
        }

        printf("\n���� ���� ���� (1: ����, 2: ����, 3: ����, 4: id(��������), 0: ������): ");
        scanf("%d", &choice);
    }
    
    free(std);
}
