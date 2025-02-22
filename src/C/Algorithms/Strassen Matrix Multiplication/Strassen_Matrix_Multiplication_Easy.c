#include <stdio.h>

// #define SIZE 2 // Matrix size (must be power of 2 for Strassen's method)
int SIZE;

void addMatrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            result[i][j] = a[i][j] + b[i][j];
}

void subMatrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            result[i][j] = a[i][j] - b[i][j];
}

void strassen(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE])
{
    int P = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    int Q = (A[1][0] + A[1][1]) * B[0][0];
    int R = A[0][0] * (B[0][1] - B[1][1]);
    int S = A[1][1] * (B[1][0] - B[0][0]);
    int T = (A[0][0] + A[0][1]) * B[1][1];
    int U = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    int V = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    C[0][0] = P + S - T + V;
    C[0][1] = R + T;
    C[1][0] = Q + S;
    C[1][1] = P + R - Q + U;
}

void printMatrix(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    scanf("%d", &SIZE);
    if (SIZE % 2 == 0)
    {
        int A[SIZE][SIZE];
        for(int i = 0;i<SIZE ;i++)
        {
            for(int j = 0;j<SIZE;j++)
            {
                scanf("%d",&A[i][j]);
            }
        }
        int B[SIZE][SIZE];
        for(int i = 0;i<SIZE ;i++)
        {
            for(int j = 0;j<SIZE;j++)
            {
                scanf("%d",&B[i][j]);
            }
        }
        int C[SIZE][SIZE];
        strassen(A, B, C);

        printf("Resultant Matrix:\n");
        printMatrix(C);
    }
    else
    {
        printf("Matrix size must be a power of 2.\n");
    }

    return 0;
}
