#include <stdio.h>

int search_binary(int list[5], int key, int low, int high) {
    int middle;
    
    if (low <= high) {
        middle = (low+high) / 2;
        if (key == list[middle])
            return middle;
        else if (key < list[middle])
            return search_binary(list, key, low, middle-1);
        else return search_binary(list, key, middle+1, high);
    }
    return -1;
}

int main(void) {
    int arr[5] = {1, 2, 3, 4, 5};
    int key, index;
    
    scanf("%d", &key);
    index = search_binary(arr, key, 0, 5);

    if (index == -1)
        printf("Not in list\n");
    else
        printf("%d\n", index);
    
    return 0;
}