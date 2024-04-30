// Date 24/4/2024
// condition 1. Multiply 2. Addition 3. Transpose 4. Exit
// using switch case
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int pom()
{
    int a[3][3], b[3][3], d[3][3] = {0};
    int i, j, k, m, n, p, q;
    printf("Enter no. of rows and columns for matrix 1: ");
    scanf("%d%d", &m, &n);
    printf("Enter no. of rows and columns for matrix 2: ");
    scanf("%d%d", &p, &q);
    if (n != p)
    {
        printf("Invalid dimensions for matrix multiplication.\n");
        return 1;
    }
    printf("Enter elements of matrix 1:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of matrix 2:\n");
    for (i = 0; i < p; i++)
        for (j = 0; j < q; j++)
            scanf("%d", &b[i][j]);

    for (i = 0; i < m; i++)
        for (j = 0; j < q; j++)
            for (k = 0; k < p; k++)
                d[i][j] += a[i][k] * b[k][j];

    printf("\nResult of Matrix Multiplication:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < q; j++)
        {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }

    return 0;
}
// ---------------------------------------------------------------------------------------------------
int add()
{
    int a[3][3], b[3][3], c[3][3] = {0}, d[3][3] = {0};
    int i, j, k, m, n, p, q;
    printf("Enter no. of rows and columns 1 ");
    scanf("%d%d", &m, &n);
    printf("Enter no. of rows and columns 2 ");
    scanf("%d%d", &p, &q);

    if (m != p || n != q)
    {
        printf("Matrix Addition is not possible");
        exit;
    }
    printf("Enter elements of matrix A: ");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    printf("Enter elements of matrix B: ");
    for (i = 0; i < p; i++)
        for (j = 0; j < q; j++)
            scanf("%d", &b[i][j]);
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            c[i][j] = a[i][j] + b[i][j];
    printf("Result \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
}
// -------------------------------------------------------------------------------------
int transpose()
{
    int m, n;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    int arr[10][10];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int brr[10][10];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            brr[j][i] = arr[i][j];
        }
    }
    printf("The transposed matrix is: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", brr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int main()
{
    int pom();
    int add();
    int transpose();
    while (1)
    {
        int opt;
        printf("1. Matrix Multiplication\n");
        printf("2. Addition of two matrix\n");
        printf("3. Transpose of matrix\n");
        printf("4.Exit..\n");

        printf("Enter any number 1-4 :");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            pom();
            break;
        case 2:
            add();
        case 3:
            transpose();
            break;
        case 4:
            exit(1);
        default:
        {
            printf("You enter wrong input");
        }
        }
    }
}