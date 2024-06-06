#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void countingSort(int *arr, int n) {
    int i, max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int *count = (int *)calloc(max + 1, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--) {
        output[--count[arr[i]]] = arr[i];
    }
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}

int main() {
    int arr[] = {3, 6, 4, 1, 3, 4, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    countingSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
