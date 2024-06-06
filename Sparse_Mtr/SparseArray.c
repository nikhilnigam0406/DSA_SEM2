#include<stdio.h>

int main()
{
    // Assume 3x3 sparse matrix
    int sparseMatrix[3][3] =
    {
        {0 , 0 , 3  },
        {0 , 0 , 5  },
        {0 , 7 , 0  }
        
    };

    int size = 0;
    // Calculate the number of non-zero elements
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (sparseMatrix[i][j] != 0)
                size++;

    // number of columns in compactMatrix (size) must be
    // equal to number of non-zero elements in
    // sparseMatrix
    int compactMatrix[3][size];

    // Making of new matrix
    int k = 0;
    for (int j = 0; j < 3; j++)
        for (int i = 0; i < 3; i++)
            if (sparseMatrix[i][j] != 0)
            {
                compactMatrix[0][k] = i;
                compactMatrix[1][k] = j;
                compactMatrix[2][k] = sparseMatrix[i][j];
                k++;
            }

    // Check if the matrix is sparse
    float threshold = 0.5; // You can adjust this threshold
    float sparsity = (float)size / (3 * 3);
    if (sparsity < threshold)
    {
        // Display compact matrix
        printf("Sparse Matrix:\n");
        printf("Row Column Value\n");
        for (int i = 0; i < size; i++)
            printf("%d   %d   %d\n", compactMatrix[0][i], compactMatrix[1][i], compactMatrix[2][i]);
    }
    else
    {
        printf("Not a sparse matrix.\n");
    }

    return 0;
}
