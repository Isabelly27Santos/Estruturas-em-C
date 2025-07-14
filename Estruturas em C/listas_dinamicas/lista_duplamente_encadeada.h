#ifndef LISTA_DUPLAMENTE_ENCADEADA_H
#define LISTA_DUPLAMENTE_ENCADEADA_H

// Estrutura de um n� da lista duplamente encadeada
typedef struct NoListD {
    int dado;
    struct NoListD* proximo;
    struct NoListD* anterior;
} NoListD;

// Fun��o para criar um novo n�
NoListD* criaNoListD(int data);

// Fun��o para inserir um novo n� no in�cio da lista
void inseriNoInicio(NoListD** noDRef, int dado);

// Fun��o para imprimir todos os elementos da lista
void exibeTodosElementosLista(NoListD* noD);

// Fun��o para liberar a mem�ria alocada para a lista
void liberarMemoriaAlocada(NoListD* noD);

// Fun��o para inserir um novo n� em uma posi��o espec�fica
int inserirNoPosicao(NoListD** noDRef, int dado, int pos);

// Fun��o para incluir n�meros fornecidos pelo usu�rio
void incluirNumerosUsuarioD(NoListD** noDRef);

// Fun��o para incluir 30 n�meros aleat�rios na lista
void incluirNumerosAleatoriosD(NoListD** noDRef);

// Fun��o principal para demonstrar a lista duplamente encadeada
void exemploListaDuplamenteEncadeada();

#endif // LISTA_DUPLAMENTE_ENCADEADA_H