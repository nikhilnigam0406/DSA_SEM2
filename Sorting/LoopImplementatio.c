#include <stdio.h>

// Function prototypes
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    int choice, n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (choice != 4) {
        printf("\nSorting Options:\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Array before sorting: ");
                printArray(arr, n);
                bubbleSort(arr, n);
                printf("Array after Bubble Sort: ");
                printArray(arr, n);
                break;
            case 2:
                printf("Array before sorting: ");
                printArray(arr, n);
                selectionSort(arr, n);
                printf("Array after Selection Sort: ");
                printArray(arr, n);
                break;
            case 3:
                printf("Array before sorting: ");
                printArray(arr, n);
                insertionSort(arr, n);
                printf("Array after Insertion Sort: ");
                printArray(arr, n);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } 

    return 0;
}

// Bubble Sort algorithm
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort algorithm
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap elements
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Insertion Sort algorithm
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
