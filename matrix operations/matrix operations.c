#include <stdio.h>

// Function for Matrix Addition
void matrixAddition(int A[10][10], int B[10][10], int C[10][10],
                    int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function for Matrix Multiplication
void matrixMultiplication(int A[10][10], int B[10][10], int C[10][10],
                          int r1, int c1, int c2)
{
    int i, j, k;

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            C[i][j] = 0;

            for (k = 0; k < c1; k++)
            {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}

// Function for Matrix Transpose
void matrixTranspose(int A[10][10], int T[10][10],
                     int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            T[j][i] = A[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int A[10][10], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int A[10][10], B[10][10];
    int addition[10][10];
    int multiplication[10][10];
    int transpose[10][10];

    int r1, c1, r2, c2;
    int i, j;

    // Input size of first matrix
    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    // Input Matrix A
    printf("\nEnter elements of Matrix A:\n");

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    // Input size of second matrix
    printf("\nEnter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    // Input Matrix B
    printf("\nEnter elements of Matrix B:\n");

    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    // Display Matrix A
    printf("\nMatrix A:\n");
    displayMatrix(A, r1, c1);

    // Display Matrix B
    printf("\nMatrix B:\n");
    displayMatrix(B, r2, c2);

    // Matrix Addition
    if (r1 == r2 && c1 == c2)
    {
        matrixAddition(A, B, addition, r1, c1);

        printf("\nMatrix Addition (A + B):\n");
        displayMatrix(addition, r1, c1);
    }
    else
    {
        printf("\nMatrix Addition is not possible.");
        printf("\nBoth matrices must have the same size.\n");
    }

    // Matrix Multiplication
    if (c1 == r2)
    {
        matrixMultiplication(A, B, multiplication, r1, c1, c2);

        printf("\nMatrix Multiplication (A x B):\n");
        displayMatrix(multiplication, r1, c2);
    }
    else
    {
        printf("\nMatrix Multiplication is not possible.");
        printf("\nColumns of Matrix A must equal rows of Matrix B.\n");
    }

    // Transpose of Matrix A
    matrixTranspose(A, transpose, r1, c1);

    printf("\nTranspose of Matrix A:\n");
    displayMatrix(transpose, c1, r1);

    return 0;
}