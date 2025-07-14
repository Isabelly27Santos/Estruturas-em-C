#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista_duplamente_encadeada.h"

// Fun��o para criar um novo n� na lista duplamente encadeada
NoListD* criaNoListD(int dado) {
    NoListD* novoNoD = (NoListD*)malloc(sizeof(NoListD));
    novoNoD->dado = dado;
    novoNoD->proximo = NULL;
    novoNoD->anterior = NULL;
    return novoNoD;
}


// Fun��o para inserir um novo n� no in�cio da lista duplamente encadeada
void inseriNoInicio(NoListD** noDRef, int dado) {
	
    NoListD* novoNo = criaNoListD(dado);
    novoNo->proximo = *noDRef;
    // Se a lista n�o estiver vazia, atualiza o ponteiro anterior do n� atual da cabe�a
    if (*noDRef != NULL) {
        (*noDRef)->anterior = novoNo;
    }
    // Atualiza a cabe�a da lista para o novo n�
    *noDRef = novoNo;
}


// Fun��o para imprimir todos os elementos da lista duplamente encadeada
void exibeTodosElementosLista(NoListD* noD) {
    NoListD* temp = noD;

    while (temp != NULL) {
        printf("%d <-> ", temp->dado);
        temp = temp->proximo;
    }
    printf("NULL\n");
}

// Fun��o para liberar a mem�ria alocada para a lista duplamente encadeada
void liberarMemoriaAlocada(NoListD* noD) {
    NoListD* temp;

    while (noD != NULL) {
        temp = noD;
        noD = noD->proximo;
        free(temp);
    }
}


// Fun��o para inserir um novo n� em uma posi��o espec�fica
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

    // Procura o n� na posi��o anterior � posi��o especificada
    NoListD* atual = *noDRef;
    for (int i = 0; atual != NULL && i < pos - 1; i++) {
        atual = atual->proximo;
    }
    
    if (atual == NULL) return 0;

    // Insere o novo n� entre o n� atual e o pr�ximo n�
    novoNo->proximo = atual->proximo;
    if (atual->proximo != NULL) {
        atual->proximo->anterior = novoNo;
    }
    atual->proximo = novoNo;
    novoNo->anterior = atual;
    return 1;
}

// Fun��o para incluir n�meros fornecidos pelo usu�rio
void incluirNumerosUsuarioD(NoListD** noDRef) {
    int num, val;

    printf("\n\nQuantos n�meros voc� deseja adicionar?: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Digite o n�mero %d: ", i + 1);
        scanf("%d", &val);
        inseriNoInicio(noDRef, val);
    }
}

// Fun��o para incluir 30 n�meros aleat�rios na lista
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
        printf("1. Incluir no in�cio uma quantidade X de n�meros\n");
        printf("2. Incluir um n�mero em uma posi��o espec�fica\n");
        printf("3. Incluir 30 n�meros aleat�rios no in�cio\n");
        printf("4. Exibir a lista\n");
        printf("0. Sair\n\n");
        printf("Escolha uma opc�o: ");
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
                printf("Digite a posi��o em que deseja inserir: ");
                scanf("%d", &pos);
                if (inserirNoPosicao(&no, val, pos)) {
                    printf("\n\nValor inserido com sucesso.\n\n");
                } else {
                    printf("\n\nPosi��o inv�lida.\n\n");
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
                printf("\n\nOpc�o inv�lida.\n\n");
                getchar ();
                system ("pause");
                system ("cls");
        }
    }
}