#ifndef FILA_DINAMICA_H
#define FILA_DINAMICA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NoF {
    int dado;
    struct NoF* proximo;
} NoF;

typedef struct {
    NoF* frente;
    NoF* tras;
} Fila;

Fila* criaFila();
NoF* criaNoF(int dado);
void incluirFila(Fila* fila, int dado);
int removerFila(Fila* fila);
int inicioFila(Fila* fila);
int filaVazia(Fila* fila);
void exibirFila(Fila* fila);
void inserirNoMeioFila(Fila* fila, int dado, int posicao);
int removerDoMeioFila(Fila* fila, int posicao);
int fila();

#endif 