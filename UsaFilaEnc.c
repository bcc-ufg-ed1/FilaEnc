#include<stdio.h>
#include<stdlib.h>
#include "FilaEnc.h"

void imprimirFila(FilaEnc* f) {
    FilaEnc* fAux = criarFila();
    int item;
    while(!estahVazia(f)) {
        remover(f, &item);
        printf("%d\n", item);
        inserir(item, fAux);
    }
    while(!estahVazia(fAux)) {
        remover(fAux, &item);
        inserir(item, f);
    }
    liberarFila(fAux);
}

int main() {
    FilaEnc* minhaFila = criarFila();
    inserir(1, minhaFila);
    inserir(2, minhaFila);
    inserir(3, minhaFila);
    imprimirFila(minhaFila);
    liberarFila(minhaFila);
    return EXIT_SUCCESS;
}
