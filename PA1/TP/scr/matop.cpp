#include <iostream>
#include <cstring>  // para strcmp
#include <cstdlib>  // para atoi
#include "mat.h"

int main(int argc, char *argv[]) {
    if (argc < 5) {
        std::cout << "Uso: ./matop -s|-m|-t -x <int> -y <int>\n";
        return 1;
    }

    int x = std::atoi(argv[3]);
    int y = std::atoi(argv[5]);

    Matriz mat1(x, y);
    Matriz mat2(x, y);
    mat1.preencher();
    mat2.preencher();

    if (std::strcmp(argv[1], "-s") == 0) {
        Matriz result = mat1.somar(mat2);
        result.imprimir();
    } else if (std::strcmp(argv[1], "-m") == 0) {
        Matriz result = mat1.multiplicar(mat2);
        result.imprimir();
    } else if (std::strcmp(argv[1], "-t") == 0) {
        Matriz result = mat1.transpor();
        result.imprimir();
    } else {
        std::cout << "Operação inválida.\n";
    }

    return 0;
}
