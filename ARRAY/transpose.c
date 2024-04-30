#include <stdio.h>

void transpose(int arr[10][10], int m, int n, int brr[10][10]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            brr[j][i] = arr[i][j];
        }
    }
}

int main() {
    int m, n;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int arr[10][10];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int brr[10][10];
    transpose(arr, m, n, brr);

    printf("The transposed matrix is: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", brr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
