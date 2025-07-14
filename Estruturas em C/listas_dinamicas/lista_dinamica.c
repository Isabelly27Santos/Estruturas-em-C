#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista_dinamica.h"

// Funcao para adicionar um n� ao final da listaRef
void adicionarNo(Lista **listaRef, int novoNumero) { //listaRef aponta para o primeiro n� da lista
    Lista *novoNo = (Lista *) malloc(sizeof(Lista)); 
    Lista *ultimo = *listaRef;

    novoNo->dado = novoNumero;
    novoNo->proximo = NULL; 

    // Se a lista estiver vazia, o novo n� ser� o primeiro n� da lista
    if (*listaRef == NULL) {
        *listaRef = novoNo;
        return;
    }

    // Encontra o �ltimo n� da lista
    while (ultimo->proximo != NULL) { 
        ultimo = ultimo->proximo;
    }

    // Adiciona o novo n� como pr�ximo do �ltimo n� da lista
    ultimo->proximo = novoNo;
}

// Funcao para imprimir todos os elementos da lista
void listarTodosElementos(Lista *lista) {
    while (lista != NULL) {
        printf("%d -> ", lista->dado); 
        lista = lista->proximo; 
    }
    printf("NULL\n"); 
}

// Fun��o para incluir v�rios n�meros fornecidos pelo usu�rio
void incluirNumerosUsuario(Lista **listaRef) { //** permite alterar o conte�do de &lista no main
    int num, val;

    printf("\n\nQuantos n�meros voc� deseja adicionar?: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Digite o n�mero %d: ", i + 1);
        scanf("%d", &val);
        adicionarNo(listaRef, val);
    }
}

// Funcao para incluir um n�mero em uma posicao espec�fica
bool incluirNumeroPosicao(Lista **listaRef, int novoNumero, int pos) {
    Lista *novoNo = (Lista *) malloc(sizeof(Lista));
    novoNo->dado = novoNumero; 

    // Verifica se a posi��o � o in�cio da lista
    if (pos == 0) {
        novoNo->proximo = *listaRef; //listaRef cont�m o primeiro n�
        *listaRef = novoNo; 
        return true;
    }

    Lista *temp = *listaRef; // Cria um ponteiro tempor�rio para percorrer a lista
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->proximo; 
    }

    // Verifica se a posi��o � v�lida
    if (temp == NULL || temp->proximo == NULL) {
        return false; 
    }

    novoNo->proximo = temp->proximo; 
    temp->proximo = novoNo;
    return true;
}
    

// Funcao para incluir 30 n�meros aleat�rios na lista
void incluirNumerosAleatorios(Lista **listaRef) {
    srand(time(0));

    for (int i = 0; i < 30; i++) {
        int numeroAleatorio = rand() % 100; // Gera um n�mero aleat�rio entre 0 e 99
        adicionarNo(listaRef, numeroAleatorio);
    }
}

// Funcao para liberar a mem�ria alocada para a lista
void liberarLista(struct Lista *lista) {
    struct No *temp; 

    while (lista != NULL) {
        temp = lista; 
        lista = lista->proximo; 
        free(temp); 
    }
}

void exemploListaDinamica() {
	system ("cls");
    Lista *lista = NULL; // O ponteiro "aponta" para NULL

    do {
        int val, pos, opcao;

        printf("\n\n-------------------------- Menu --------------------------\n\n");
        printf("1. Incluir v�rios n�meros na lista\n");
        printf("2. Incluir um n�mero em uma posi��o espec�fica da lista\n");
        printf("3. Incluir 30 numeros aleat�rios\n");
        printf("4. Exibe a Lista\n");
        printf("0. Sair\n\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao); 

        switch (opcao) {
            case 1:
                incluirNumerosUsuario(&lista); //tudo que mudar na lista dentro fun��o, altera na lista original
                system ("pause");
                system ("cls");
                break;
            case 2:
                printf("\n\nDigite o valor a ser inserido: ");
                scanf("%d", &val);
                printf("\nDigite a posi��o em que deseja inserir: ");
                scanf("%d", &pos);
                if (incluirNumeroPosicao(&lista, val, pos)) {
                    printf("\n\nValor inserido com sucesso.\n\n");
                } else {
                    printf("\n\nPosi��o inv�lida.\n");
                }
                printf("\n\nLista ap�s inser��o na posi��o espec�fica:\n\n");
                listarTodosElementos(lista);
                system ("pause");
                system ("cls");
                break;
            case 3:
                incluirNumerosAleatorios(&lista); 
                printf("\n\nLista ap�s incluir 30 numeros aleat�rios:\n\n");
                listarTodosElementos(lista);
                system ("pause");
                system ("cls");
                break;
            case 4:
                listarTodosElementos(lista); 
                system ("pause");
                system ("cls");
                break;
            case 0:
                liberarLista(lista); 
                system ("pause");
                system ("cls");
                return; 
        }
    } while (true); 
}