#include "../include/Heap.hpp"
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    Heap heap(n);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        heap.Inserir(x);
    }

    while (!heap.Vazio()) {
        std::cout << heap.Remover();
        if (!heap.Vazio()) std::cout << " ";
    }
    std::cout << std::endl;

    return 0;
}
