#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i) {
    int big = i, left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && arr[left] > arr[big])
    {big = left;}
    if (right < n && arr[right] > arr[big])
    {big = right;}
    if (big != i) {
        swap(&arr[i], &arr[big]);
        heapify(arr, n, big);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) 
    heapify(arr, n, i);
}
void show(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    buildMaxHeap(arr, n);
    printf("Max-Heap array:\n");
    show(arr, n);

    return 0;
}
