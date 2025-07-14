#ifndef LISTA_DINAMICA_H
#define LISTA_DINAMICA_H

#include <stdbool.h>

// Estrutura de um n� da lista
typedef struct Lista {
    int dado;
    struct Lista* proximo;
} Lista;

// Fun��o para adicionar um n� ao final da listaRef
void adicionarNo(Lista** listaRef, int novoNumero);

// Fun��o para imprimir todos os elementos da lista
void listarTodosElementos(Lista* lista);

// Fun��o para incluir n�meros fornecidos pelo usu�rio
void incluirNumerosUsuario(Lista** listaRef);

// Fun��o para incluir um n�mero em uma posi��o espec�fica
bool incluirNumeroPosicao(Lista** listaRef, int novoNumero, int pos);

// Fun��o para incluir 30 n�meros aleat�rios na lista
void incluirNumerosAleatorios(Lista **listaRef);

// Fun��o para liberar a mem�ria alocada para a lista
void liberarLista(struct Lista* lista);

// Fun��o principal para demonstrar a lista encadeada
void exemploListaDinamica();

#endif // LISTA_DINAMICA_H