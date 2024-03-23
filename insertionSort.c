#include <stdio.h>
#include <time.h>

int main() {
    int arr[] = {9, 5, 1, 3, 2, 4, 6, 0, 7, 8};
    int i, j, key, swap;
    struct timespec start, end;

    printf("Displaying Unsorted String: - \n");
        for(i = 0; i < 10; i++) 
            printf("%d ", arr[i]);
    printf("\n\n");


    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    for(i = 1; i < 10; i++) {
        key = arr[i];
        for(j = i - 1; j >= 0; j--) {
            if(key < arr[j]) {
                arr[j + 1] = arr[j];
                arr[j] = key;
            }
        }
    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    int delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;

    printf("Displaying Sorted String: - \n");
    for(i = 0; i < 10; i++) 
        printf("%d ", arr[i]);
    printf("\n");
    printf("\nComputational Time in µs: %d\n\n", delta_us);

    return 0;
}