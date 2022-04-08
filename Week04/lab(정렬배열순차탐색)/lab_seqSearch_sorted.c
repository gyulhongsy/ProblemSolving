#include <stdio.h>

int sorted_seq_search(int list[], int key, int low, int high) {
    int i;
    for (i = low; i <= high; i++) {
        if (key < list[i])
            return -1;
        else if (key == list[i])
            return i;
    }
    if (key > list[high])
        return -1;
}

int main(void) {
    int list[5] = {1, 2, 3, 4, 5};
    int key, index;

    scanf("%d", &key);
    index = sorted_seq_search(list, key, 0, 5);

    if (index == -1)
        printf("Not in list\n");
    else
        printf("%d\n", index);
    
    return 0;
}