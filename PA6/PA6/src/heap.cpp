#include "../include/Heap.hpp"
#include <stdexcept>

Heap::Heap(int maxsize) : tamanho(0), capacidade(maxsize) {
    data = new int[capacidade];
}

Heap::~Heap() {
    delete[] data;
}

void Heap::Inserir(int x) {
    if (tamanho >= capacidade) throw std::overflow_error("Heap cheio!");
    data[tamanho] = x;
    HeapifyPorCima(tamanho);
    tamanho++;
}

int Heap::Remover() {
    if (Vazio()) throw std::underflow_error("Heap vazio!");
    int min = data[0];
    data[0] = data[--tamanho];
    HeapifyPorBaixo(0);
    return min;
}

bool Heap::Vazio() {
    return tamanho == 0;
}

int Heap::GetAncestral(int posicao) {
    return (posicao - 1) / 2;
}

int Heap::GetSucessorEsq(int posicao) {
    return 2 * posicao + 1;
}

int Heap::GetSucessorDir(int posicao) {
    return 2 * posicao + 2;
}

void Heap::HeapifyPorBaixo(int posicao) {
    int menor = posicao;
    int esq = GetSucessorEsq(posicao);
    int dir = GetSucessorDir(posicao);

    if (esq < tamanho && data[esq] < data[menor]) menor = esq;
    if (dir < tamanho && data[dir] < data[menor]) menor = dir;

    if (menor != posicao) {
        std::swap(data[posicao], data[menor]);
        HeapifyPorBaixo(menor);
    }
}

void Heap::HeapifyPorCima(int posicao) {
    while (posicao > 0 && data[GetAncestral(posicao)] > data[posicao]) {
        std::swap(data[posicao], data[GetAncestral(posicao)]);
        posicao = GetAncestral(posicao);
    }
}
