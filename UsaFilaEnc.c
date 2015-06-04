#include<stdio.h>
#include<stdlib.h>
#include "FilaEnc.h"

void imprimirFila(FilaEnc* f) {
    FilaEnc* fAux = criarFila();
    int item;
    while(!estahVazia(f)) {
        remover(f, &item);
        printf("%d\n", item);
        inserir(fAux, item);
    }
    while(!estahVazia(fAux)) {
        remover(fAux, &item);
        inserir(f, item);
    }
    liberarFila(fAux);
}

int main() {
    FilaEnc* minhaFila = criarFila();
    inserir(minhaFila, 1);
    inserir(minhaFila, 2);
    inserir(minhaFila, 3);
    imprimirFila(minhaFila);
    liberarFila(minhaFila);
    return EXIT_SUCCESS;
}
