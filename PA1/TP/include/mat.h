#ifndef MAT_H
#define MAT_H

#include <vector>

class Matriz {
private:
    std::vector<std::vector<int>> data;
    int rows, cols;

public:
    Matriz(int rows, int cols);
    void preencher();
    void imprimir() const;
    Matriz somar(const Matriz &other) const;
    Matriz multiplicar(const Matriz &other) const;
    Matriz transpor() const;
};

#endif