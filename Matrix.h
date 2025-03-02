#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

// Function declarations
std::vector<std::vector<int>> generateRandomMatrix(int size);
void printMatrix(const std::vector<std::vector<int>>& matrix);
std::vector<std::vector<int>> matrixMultiply(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B);
std::vector<std::vector<int>> strassenMultiply(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B);

#endif
