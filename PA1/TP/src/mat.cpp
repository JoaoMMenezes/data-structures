#include "mat.h"
#include "msgassert.h"
#include <iostream>
#include <cstdlib>  // para rand()

Matriz::Matriz(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<int>(cols)) {}

void Matriz::preencher() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = rand() % 10;
        }
    }
}

void Matriz::imprimir() const {
    for (const auto &row : data) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

Matriz Matriz::somar(const Matriz &other) const {
    msgassert(rows == other.rows && cols == other.cols, "Dimensões incompatíveis para soma.");
    Matriz result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matriz Matriz::multiplicar(const Matriz &other) const {
    msgassert(cols == other.rows, "Dimensões incompatíveis para multiplicação.");
    Matriz result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

Matriz Matriz::transpor() const {
    Matriz result(cols, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[j][i] = data[i][j];
        }
    }
    return result;
}
