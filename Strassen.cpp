#include "Matrix.h"
#include <iostream>
#include <vector>

std::vector<std::vector<int>> addMatrix(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();
    std::vector<std::vector<int>> result(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

std::vector<std::vector<int>> subtractMatrix(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();
    std::vector<std::vector<int>> result(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

// Strassen's matrix multiplication
std::vector<std::vector<int>> strassenMultiply(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();

    // Base case for recursion (when the matrix size is 1x1)
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int mid = n / 2;

    // Split A and B into 4 submatrices
    std::vector<std::vector<int>> A11(mid, std::vector<int>(mid));
    std::vector<std::vector<int>> A12(mid, std::vector<int>(mid));
    std::vector<std::vector<int>> A21(mid, std::vector<int>(mid));
    std::vector<std::vector<int>> A22(mid, std::vector<int>(mid));

    std::vector<std::vector<int>> B11(mid, std::vector<int>(mid));
    std::vector<std::vector<int>> B12(mid, std::vector<int>(mid));
    std::vector<std::vector<int>> B21(mid, std::vector<int>(mid));
    std::vector<std::vector<int>> B22(mid, std::vector<int>(mid));

    // Fill submatrices A11, A12, A21, A22 from matrix A
    for (int i = 0; i < mid; ++i) {
        for (int j = 0; j < mid; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];
        }
    }

    // Fill submatrices B11, B12, B21, B22 from matrix B
    for (int i = 0; i < mid; ++i) {
        for (int j = 0; j < mid; ++j) {
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // Calculating P1 to P7 using Strassen's formulas
    std::vector<std::vector<int>> P1 = strassenMultiply(A11, subtractMatrix(B12, B22));
    std::vector<std::vector<int>> P2 = strassenMultiply(addMatrix(A11, A12), B22);
    std::vector<std::vector<int>> P3 = strassenMultiply(addMatrix(A21, A22), B11);
    std::vector<std::vector<int>> P4 = strassenMultiply(A22, subtractMatrix(B21, B11));
    std::vector<std::vector<int>> P5 = strassenMultiply(addMatrix(A11, A22), addMatrix(B11, B22));
    std::vector<std::vector<int>> P6 = strassenMultiply(subtractMatrix(A12, A22), addMatrix(B21, B22));
    std::vector<std::vector<int>> P7 = strassenMultiply(subtractMatrix(A11, A21), addMatrix(B11, B12));

    // Calculate C11, C12, C21, C22
    std::vector<std::vector<int>> C11 = addMatrix(subtractMatrix(addMatrix(P5, P4), P2), P6);
    std::vector<std::vector<int>> C12 = addMatrix(P1, P2);
    std::vector<std::vector<int>> C21 = addMatrix(P3, P4);
    std::vector<std::vector<int>> C22 = addMatrix(subtractMatrix(addMatrix(P5, P1), P3), P7);

    // Combine C11, C12, C21, C22 into the final result matrix
    std::vector<std::vector<int>> result(n, std::vector<int>(n));
    for (int i = 0; i < mid; ++i) {
        for (int j = 0; j < mid; ++j) {
            result[i][j] = C11[i][j];
            result[i][j + mid] = C12[i][j];
            result[i + mid][j] = C21[i][j];
            result[i + mid][j + mid] = C22[i][j];
        }
    }

    return result;
}
