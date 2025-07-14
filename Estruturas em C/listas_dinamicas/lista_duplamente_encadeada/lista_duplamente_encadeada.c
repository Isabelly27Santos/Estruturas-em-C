#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista_duplamente_encadeada.h"

// Função para criar um novo nó na lista duplamente encadeada
NoListD* criaNoListD(int dado) {
    NoListD* novoNoD = (NoListD*)malloc(sizeof(NoListD));
    novoNoD->dado = dado;
    novoNoD->proximo = NULL;
    novoNoD->anterior = NULL;
    return novoNoD;
}


// Função para inserir um novo nó no início da lista duplamente encadeada
void inseriNoInicio(NoListD** noDRef, int dado) {
	
    NoListD* novoNo = criaNoListD(dado);
    novoNo->proximo = *noDRef;
    // Se a lista não estiver vazia, atualiza o ponteiro anterior do nó atual da cabeça
    if (*noDRef != NULL) {
        (*noDRef)->anterior = novoNo;
    }
    // Atualiza a cabeça da lista para o novo nó
    *noDRef = novoNo;
}


// Função para imprimir todos os elementos da lista duplamente encadeada
void exibeTodosElementosLista(NoListD* noD) {
    NoListD* temp = noD;

    while (temp != NULL) {
        printf("%d <-> ", temp->dado);
        temp = temp->proximo;
    }
    printf("NULL\n");
}

// Função para liberar a memória alocada para a lista duplamente encadeada
void liberarMemoriaAlocada(NoListD* noD) {
    NoListD* temp;

    while (noD != NULL) {
        temp = noD;
        noD = noD->proximo;
        free(temp);
    }
}


// Função para inserir um novo nó em uma posição específica
int inserirNoPosicao(NoListD** noDRef, int dado, int pos) {
	
    if (pos < 0) return 0;

    NoListD* novoNo = criaNoListD(dado);

    if (pos == 0) {
        novoNo->proximo = *noDRef;
        if (*noDRef != NULL) {
            (*noDRef)->anterior = novoNo;
        }
        *noDRef = novoNo;
        return 1;
    }

    // Procura o nó na posição anterior à posição especificada
    NoListD* atual = *noDRef;
    for (int i = 0; atual != NULL && i < pos - 1; i++) {
        atual = atual->proximo;
    }
    
    if (atual == NULL) return 0;

    // Insere o novo nó entre o nó atual e o próximo nó
    novoNo->proximo = atual->proximo;
    if (atual->proximo != NULL) {
        atual->proximo->anterior = novoNo;
    }
    atual->proximo = novoNo;
    novoNo->anterior = atual;
    return 1;
}

// Função para incluir números fornecidos pelo usuário
void incluirNumerosUsuarioD(NoListD** noDRef) {
    int num, val;

    printf("\n\nQuantos números você deseja adicionar?: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &val);
        inseriNoInicio(noDRef, val);
    }
}

// Função para incluir 30 números aleatórios na lista
void incluirNumerosAleatoriosD(NoListD** noDRef) {
	
    srand(time(0));

    for (int i = 0; i < 30; i++) {
        int rand_num = rand() % 100;
        inseriNoInicio(noDRef, rand_num); 
    }
}


void exemploListaDuplamenteEncadeada() {
    NoListD* no = NULL; 

    int opcao, val, pos;

    while (1) {
    	system ("cls");
        printf("\n-------------------- Menu --------------------\n");
        printf("1. Incluir no início uma quantidade X de números\n");
        printf("2. Incluir um número em uma posição específica\n");
        printf("3. Incluir 30 números aleatórios no início\n");
        printf("4. Exibir a lista\n");
        printf("0. Sair\n\n");
        printf("Escolha uma opcão: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluirNumerosUsuarioD(&no); 
                getchar ();
                system ("pause");
                system ("cls");
                break;
            case 2:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &val);
                printf("Digite a posição em que deseja inserir: ");
                scanf("%d", &pos);
                if (inserirNoPosicao(&no, val, pos)) {
                    printf("\n\nValor inserido com sucesso.\n\n");
                } else {
                    printf("\n\nPosição inválida.\n\n");
                }
                getchar ();
                system ("pause");
                system ("cls");
                break;
            case 3:
                incluirNumerosAleatoriosD(&no);
                getchar ();
                system ("pause");
                system ("cls");
                break;
            case 4:
                printf("Lista duplamente encadeada: ");
                exibeTodosElementosLista(no);
                getchar ();
                system ("pause");
                system ("cls");
                break;
            case 0:
                liberarMemoriaAlocada(no);
                printf("\n\nSaindo....\n\n");
                getchar ();
                system ("pause");
                system ("cls");
                return;
            default:
                printf("\n\nOpcão inválida.\n\n");
                getchar ();
                system ("pause");
                system ("cls");
        }
    }
}