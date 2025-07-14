#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista_dinamica.h"

// Funcao para adicionar um nó ao final da listaRef
void adicionarNo(Lista **listaRef, int novoNumero) { //listaRef aponta para o primeiro nó da lista
    Lista *novoNo = (Lista *) malloc(sizeof(Lista)); 
    Lista *ultimo = *listaRef;

    novoNo->dado = novoNumero;
    novoNo->proximo = NULL; 

    // Se a lista estiver vazia, o novo nó será o primeiro nó da lista
    if (*listaRef == NULL) {
        *listaRef = novoNo;
        return;
    }

    // Encontra o último nó da lista
    while (ultimo->proximo != NULL) { 
        ultimo = ultimo->proximo;
    }

    // Adiciona o novo nó como próximo do último nó da lista
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

// Função para incluir vários números fornecidos pelo usuário
void incluirNumerosUsuario(Lista **listaRef) { //** permite alterar o conteúdo de &lista no main
    int num, val;

    printf("\n\nQuantos números você deseja adicionar?: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &val);
        adicionarNo(listaRef, val);
    }
}

// Funcao para incluir um número em uma posicao específica
bool incluirNumeroPosicao(Lista **listaRef, int novoNumero, int pos) {
    Lista *novoNo = (Lista *) malloc(sizeof(Lista));
    novoNo->dado = novoNumero; 

    // Verifica se a posição é o início da lista
    if (pos == 0) {
        novoNo->proximo = *listaRef; //listaRef contém o primeiro nó
        *listaRef = novoNo; 
        return true;
    }

    Lista *temp = *listaRef; // Cria um ponteiro temporário para percorrer a lista
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->proximo; 
    }

    // Verifica se a posição é válida
    if (temp == NULL || temp->proximo == NULL) {
        return false; 
    }

    novoNo->proximo = temp->proximo; 
    temp->proximo = novoNo;
    return true;
}
    

// Funcao para incluir 30 números aleatórios na lista
void incluirNumerosAleatorios(Lista **listaRef) {
    srand(time(0));

    for (int i = 0; i < 30; i++) {
        int numeroAleatorio = rand() % 100; // Gera um número aleatório entre 0 e 99
        adicionarNo(listaRef, numeroAleatorio);
    }
}

// Funcao para liberar a memória alocada para a lista
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
        printf("1. Incluir vários números na lista\n");
        printf("2. Incluir um número em uma posição específica da lista\n");
        printf("3. Incluir 30 numeros aleatórios\n");
        printf("4. Exibe a Lista\n");
        printf("0. Sair\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao); 

        switch (opcao) {
            case 1:
                incluirNumerosUsuario(&lista); //tudo que mudar na lista dentro função, altera na lista original
                system ("pause");
                system ("cls");
                break;
            case 2:
                printf("\n\nDigite o valor a ser inserido: ");
                scanf("%d", &val);
                printf("\nDigite a posição em que deseja inserir: ");
                scanf("%d", &pos);
                if (incluirNumeroPosicao(&lista, val, pos)) {
                    printf("\n\nValor inserido com sucesso.\n\n");
                } else {
                    printf("\n\nPosição inválida.\n");
                }
                printf("\n\nLista após inserção na posição específica:\n\n");
                listarTodosElementos(lista);
                system ("pause");
                system ("cls");
                break;
            case 3:
                incluirNumerosAleatorios(&lista); 
                printf("\n\nLista após incluir 30 numeros aleatórios:\n\n");
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