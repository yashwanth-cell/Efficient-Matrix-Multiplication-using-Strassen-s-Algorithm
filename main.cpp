#include <iostream>
#include <vector>
#include <chrono>
#include "Matrix.h"

int main() {
    int size = 4; // Example: 4x4 matrices

    // Generate two random matrices of the specified size
    std::vector<std::vector<int>> A = generateRandomMatrix(size);
    std::vector<std::vector<int>> B = generateRandomMatrix(size);

    std::cout << "Matrix A:" << std::endl;
    printMatrix(A);

    std::cout << "Matrix B:" << std::endl;
    printMatrix(B);

    // Traditional Matrix Multiplication
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<int>> resultTraditional = matrixMultiply(A, B);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationTraditional = end - start;

    std::cout << "Traditional Matrix Multiplication Result:" << std::endl;
    printMatrix(resultTraditional);
    std::cout << "Time taken by traditional multiplication: " << durationTraditional.count() << " seconds" << std::endl;

    // Strassen's Matrix Multiplication
    start = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<int>> resultStrassen = strassenMultiply(A, B);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationStrassen = end - start;

    std::cout << "Strassen's Matrix Multiplication Result:" << std::endl;
    printMatrix(resultStrassen);
    std::cout << "Time taken by Strassen's multiplication: " << durationStrassen.count() << " seconds" << std::endl;

    return 0;
}
