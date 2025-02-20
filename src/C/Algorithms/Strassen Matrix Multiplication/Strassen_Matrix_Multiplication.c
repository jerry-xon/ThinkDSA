#include <stdio.h>
#include <stdlib.h>

#define SIZE 2 // Define the matrix size (must be a power of 2 for Strassen's method)

void addMatrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    } 
}

void subMatrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void strassen(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
    if (SIZE == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    
    int half = SIZE / 2;
    int A11[half][half], A12[half][half], A21[half][half], A22[half][half];
    int B11[half][half], B12[half][half], B21[half][half], B22[half][half];
    int C11[half][half], C12[half][half], C21[half][half], C22[half][half];
    int P[half][half], Q[half][half], R[half][half], S[half][half], T[half][half], U[half][half], V[half][half];
    int temp1[half][half], temp2[half][half];
    
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }
    
    addMatrix(A11, A22, temp1);
    addMatrix(B11, B22, temp2);
    strassen(temp1, temp2, P);
    
    addMatrix(A21, A22, temp1);
    strassen(temp1, B11, Q);
    
    subMatrix(B12, B22, temp1);
    strassen(A11, temp1, R);
    
    subMatrix(B21, B11, temp1);
    strassen(A22, temp1, S);
    
    addMatrix(A11, A12, temp1);
    strassen(temp1, B22, T);
    
    subMatrix(A21, A11, temp1);
    addMatrix(B11, B12, temp2);
    strassen(temp1, temp2, U);
    
    subMatrix(A12, A22, temp1);
    addMatrix(B21, B22, temp2);
    strassen(temp1, temp2, V);
    
    addMatrix(P, S, temp1);
    subMatrix(temp1, T, temp2);
    addMatrix(temp2, V, C11);
    
    addMatrix(R, T, C12);
    
    addMatrix(Q, S, C21);
    
    addMatrix(P, R, temp1);
    subMatrix(temp1, Q, temp2);
    addMatrix(temp2, U, C22);
    
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }
}

void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[SIZE][SIZE] = {{1, 2}, {3, 4}};
    int B[SIZE][SIZE] = {{5, 6}, {7, 8}};
    int C[SIZE][SIZE];
    
    strassen(A, B, C);
    
    printf("Resultant Matrix: \n");
    printMatrix(C);
    
    return 0;
}
