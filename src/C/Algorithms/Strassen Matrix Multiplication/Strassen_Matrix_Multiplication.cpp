#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

// Function to add two matrices
Matrix add(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Function to subtract two matrices
Matrix subtract(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Strassen's multiplication algorithm
Matrix strassen(const Matrix &A, const Matrix &B) {
    int n = A.size();
    
    // Base case: 1x1 matrix
    if (n == 1) return {{A[0][0] * B[0][0]}};

    // Splitting the matrices into 4 submatrices
    int newSize = n / 2;
    Matrix A11(newSize, vector<int>(newSize)), A12(newSize, vector<int>(newSize)),
           A21(newSize, vector<int>(newSize)), A22(newSize, vector<int>(newSize)),
           B11(newSize, vector<int>(newSize)), B12(newSize, vector<int>(newSize)),
           B21(newSize, vector<int>(newSize)), B22(newSize, vector<int>(newSize));

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Strassen's 7 multiplication steps
    Matrix M1 = strassen(add(A11, A22), add(B11, B22));
    Matrix M2 = strassen(add(A21, A22), B11);
    Matrix M3 = strassen(A11, subtract(B12, B22));
    Matrix M4 = strassen(A22, subtract(B21, B11));
    Matrix M5 = strassen(add(A11, A12), B22);
    Matrix M6 = strassen(subtract(A21, A11), add(B11, B12));
    Matrix M7 = strassen(subtract(A12, A22), add(B21, B22));

    // Constructing the result matrix
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C[i][j + newSize] = M3[i][j] + M5[i][j];
            C[i + newSize][j] = M2[i][j] + M4[i][j];
            C[i + newSize][j + newSize] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }

    return C;
}

// Function to print a matrix
void printMatrix(const Matrix &M) {
    for (const auto &row : M) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter matrix size (power of 2): ";
    cin >> n;

    Matrix A(n, vector<int>(n)), B(n, vector<int>(n));
    cout << "Enter matrix A:\n";
    for (auto &row : A)
        for (int &val : row)
            cin >> val;

    cout << "Enter matrix B:\n";
    for (auto &row : B)
        for (int &val : row)
            cin >> val;

    cout << "Result of A x B using Strassen's Algorithm:\n";
    Matrix C = strassen(A, B);
    printMatrix(C);

    return 0;
}