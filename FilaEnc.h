#ifndef FILA_ENC_H
#define FILA_ENC_H

#define TRUE 1
#define FALSE 0

#define OK 0
#define ESTRUTURA_NAO_INICIALIZADA -1
#define ESTRUTURA_VAZIA -2

typedef struct {
  int item;
  struct No* prox;
} No;

typedef struct {
  No* inicio;
  No* fim;
  int tamanho;
} FilaEnc;

FilaEnc* criarFila();
int liberarFila(FilaEnc* fila);
int estahVazia(FilaEnc* fila);
int inserir(int item, FilaEnc* fila);
int remover(FilaEnc* fila, int* item);
int obterInicio(FilaEnc* fila, int* item);
int obterTamanho(FilaEnc* fila, int* item);
#endif // FILA_ENC_H
