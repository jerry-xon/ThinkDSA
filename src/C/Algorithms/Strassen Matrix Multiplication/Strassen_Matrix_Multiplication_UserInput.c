#include <stdio.h>
#include <stdlib.h>

int SIZE;

void addMatrix(int **a, int **b, int **result) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    } 
}

void subMatrix(int **a, int **b, int **result) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void strassen(int **A, int **B, int **C) {
    if (SIZE == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    
    int half = SIZE / 2;
    int **A11 = malloc(half * sizeof(int*));
    int **A12 = malloc(half * sizeof(int*));
    int **A21 = malloc(half * sizeof(int*));
    int **A22 = malloc(half * sizeof(int*));
    int **B11 = malloc(half * sizeof(int*));
    int **B12 = malloc(half * sizeof(int*));
    int **B21 = malloc(half * sizeof(int*));
    int **B22 = malloc(half * sizeof(int*));
    int **C11 = malloc(half * sizeof(int*));
    int **C12 = malloc(half * sizeof(int*));
    int **C21 = malloc(half * sizeof(int*));
    int **C22 = malloc(half * sizeof(int*));
    int **P = malloc(half * sizeof(int*));
    int **Q = malloc(half * sizeof(int*));
    int **R = malloc(half * sizeof(int*));
    int **S = malloc(half * sizeof(int*));
    int **T = malloc(half * sizeof(int*));
    int **U = malloc(half * sizeof(int*));
    int **V = malloc(half * sizeof(int*));
    int **temp1 = malloc(half * sizeof(int*));
    int **temp2 = malloc(half * sizeof(int*));
    
    for (int i = 0; i < half; i++) {
        A11[i] = A[i];
        A12[i] = A[i] + half;
        A21[i] = A[i + half];
        A22[i] = A[i + half] + half;
        B11[i] = B[i];
        B12[i] = B[i] + half;
        B21[i] = B[i + half];
        B22[i] = B[i + half] + half;
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

void printMatrix(int **matrix) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void inputMatrix(int **matrix, char name) {
    printf("Enter elements of matrix %c:\n", name);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main() {
    do {
        printf("Enter matrix size (power of 2): ");
        scanf("%d", &SIZE);
    } while ((SIZE & (SIZE - 1)) != 0);
    
    int **A = malloc(SIZE * sizeof(int*));
    int **B = malloc(SIZE * sizeof(int*));
    int **C = malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; i++) {
        A[i] = malloc(SIZE * sizeof(int));
        B[i] = malloc(SIZE * sizeof(int));
        C[i] = malloc(SIZE * sizeof(int));
    }
    
    inputMatrix(A, 'A');
    inputMatrix(B, 'B');
    
    strassen(A, B, C);
    
    printf("Resultant Matrix: \n");
    printMatrix(C);
    
    return 0;
}
