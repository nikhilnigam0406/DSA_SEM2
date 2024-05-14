#include <stdio.h>

// Function prototypes
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nSorting Options:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nOriginal array: ");
            printArray(arr, n);
            bubbleSort(arr, n);
            printf("Array after Bubble Sort: ");
            printArray(arr, n);
            break;
        case 2:
            printf("\nOriginal array: ");
            printArray(arr, n);
            selectionSort(arr, n);
            printf("Array after Selection Sort: ");
            printArray(arr, n);
            break;
        case 3:
            printf("\nOriginal array: ");
            printArray(arr, n);
            insertionSort(arr, n);
            printf("Array after Insertion Sort: ");
            printArray(arr, n);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
void bubbleSort(int arr[], int n) {
    // Base case
    if (n == 1)
        return;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) 
        {
            swap(&arr[i], &arr[i + 1]);
        }
    }
    bubbleSort(arr, n - 1);
}

void selectionSort(int arr[], int n) {
    // Base case
    if (n <= 1)
        return;
  
    int max_index = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[max_index]) {
            max_index = i;
        }
    }
    swap(&arr[max_index], &arr[n - 1]);
    selectionSort(arr, n - 1);
}

void insertionSort(int arr[], int n) {
    // Base case
    if (n <= 1)
        return;
    insertionSort(arr, n - 1);
  
    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}
