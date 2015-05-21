#include<stdlib.h>
#include "FilaEnc.h"

FilaEnc* criarFila() {
	FilaEnc *fila = malloc(sizeof(*fila));
    if (fila == NULL)
        return NULL;
	fila->inicio = NULL;
	fila->fim = NULL;
	fila->tamanho=0;
	return fila;
}

No* criarNo(int item, No* prox) {
	No *no = malloc(sizeof(*no));
	no->item = item;
	no->prox = prox;
	return no;
}

int inserir(int item, FilaEnc* fila) {
    if (fila == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;

    No *novoNo = criarNo(item, NULL);
    if (fila->fim == NULL)
        fila->inicio = novoNo;
    else
        fila->fim->prox = novoNo;
    fila->fim = novoNo;
    fila->tamanho++;
    return OK;
}

int estahVazia(FilaEnc *fila) {
    if (fila == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;

    if (fila->fim == NULL) return TRUE;
    else return FALSE;
}

int remover(FilaEnc* fila, int* item) {
    if (fila == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahVazia(fila))
        return ESTRUTURA_VAZIA;
    No* aux = fila->inicio;
    if (item != NULL)
        *item = aux->item;
    fila->inicio = aux->prox;
    if (fila->inicio == NULL) fila->fim = NULL;
    free(aux);
    aux = NULL;
    fila->tamanho--;
    return OK;
}

int obterInicio(FilaEnc* fila, int* item) {
    if (fila == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahVazia(fila))
        return ESTRUTURA_VAZIA;
    *item = fila->inicio->item;
    return OK;
}

int liberarFila(FilaEnc *fila) {
    if (fila == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
	while(!estahVazia(fila))
        remover(fila, NULL);
	free(fila);
	fila = NULL;
	return OK;
}
int obterTamanho(FilaEnc* fila,int* item){
    if (fila == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    *item = fila->tamanho;
    return OK;
}


