#include <stdio.h>

int main() {
    int arr[] = {9, 5, 1, 3, 2, 4, 6, 0, 7, 8};
    int size = 10;
    int i, j, key;

    printf("Displaying Unsorted String: - \n");
        for(i = 0; i < size; i++) 
            printf("%d ", arr[i]);
    printf("\n\n");

    for(i = 1; i < size; i++) {
        key = arr[i];
        for(j = i - 1; (j >= 0) && (key < arr[j]); j--) {
            arr[j + 1] = arr[j];
        }
        arr[j+1] = key;
    }

    printf("Displaying Sorted String: - \n");
    for(i = 0; i < size; i++) 
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}