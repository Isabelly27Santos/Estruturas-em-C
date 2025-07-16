#include "fila_dinamica.h" 

// Fun��o para criar uma nova fila
Fila *criaFila() {
    
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    if (!fila) { //se retornar NULL executa
        printf("Erro de alocacao de memoria.\n"); 
        exit(1); 
    }
    fila->frente = fila->tras = NULL;
    return fila;
}

// Fun��o para criar um novo n�
NoF *criaNoF(int dado) {
  
    NoF *novoNo = (NoF *) malloc(sizeof(NoF));
    if (!novoNo) {
        printf("Erro de alocacao de memoria.\n"); 
        exit(1); 
    }
    novoNo->dado = dado; 
    novoNo->proximo = NULL; 
    return novoNo;
}

// Fun��o para adicionar (enqueue) um elemento na fila
void incluirFila(Fila *fila, int dado) {
	
    NoF *novoNo = criaNoF(dado);
    if (fila->tras == NULL) {
        fila->frente = fila->tras = novoNo; //o primeiro adicionado ser� o primeiro da fila (frente)
    } else {
        fila->tras->proximo = novoNo; //o �ltimo adicionado ser� armazenado em fila->tras->proximo (tras)
        fila->tras = novoNo;
    }
    printf("\n\nAdicionado: %d\n\n", dado);
}

// Fun��o para remover (dequeue) um elemento da fila
int removerFila(Fila *fila) {
	
    if (fila->frente == NULL) {
        printf("\n\nFila vazia.\n\n");
        return -1; 
    }
    NoF *temp = fila->frente;
    int dado = temp->dado;
    fila->frente = fila->frente->proximo;
    if (fila->frente == NULL) {
        fila->tras = NULL; //zera a fila 
    }
    free(temp);
    return dado;
}

// Fun��o para ver o elemento na frente da fila sem remov�-lo (inicioFila)
int inicioFila(Fila *fila) {
	
    if (fila->frente == NULL) {
        printf("\n\nFila vazia.\n\n");
        return -1;
    }
    return fila->frente->dado;
}

// Fun��o para verificar se a fila est� vazia
int filaVazia(Fila *fila) {
	
    return fila->frente == NULL; //retorna 1 se fila->frente est� vazia
}

// Fun��o para exibir todos os elementos da fila
void exibirFila(Fila *fila) {
	
    NoF *temp = fila->frente;
    while (temp != NULL) {
        printf("%d -> ", temp->dado);
        temp = temp->proximo;
    }
    printf("NULL\n\n");
}

// Fun��o para inserir um elemento no meio da fila
void inserirNoMeioFila(Fila *fila, int dado, int posicao) {

    if (posicao < 0) {
        printf("\n\nPosi��o inv�lida.\n\n"); 
        return; 
    }
    if (posicao == 0) {
        NoF *novoNo = criaNoF(dado);
        novoNo->proximo = fila->frente;
        fila->frente = novoNo;
        if (fila->tras == NULL) {
            fila->tras = novoNo;
        }
        printf("\n\Inserido: %d na posi��o %d\n\n", dado, posicao);
        return;
    }
    NoF *novoNo = criaNoF(dado);
    NoF *temp = fila->frente;
    for (int i = 0; temp != NULL && i < posicao - 1; i++) {
        temp = temp->proximo;
    }
    if (temp == NULL) {
        printf("\n\nPosi��o inv�lida.\n\n"); 
        free(novoNo); 
    } else {
        novoNo->proximo = temp->proximo;
        temp->proximo = novoNo;
        if (novoNo->proximo == NULL) {
            fila->tras = novoNo;
        }
        printf("\n\nInserido: %d na posi��o %d\n\n", dado, posicao);
    }
}


// Fun��o para remover um elemento do meio da fila
int removerDoMeioFila(Fila *fila, int posicao) {
	
    if (fila->frente == NULL || posicao < 0) {
        printf("\n\nFila vazia ou posi��o inv�lida.\n\n"); 
        return -1; 
    }
    if (posicao == 0) {
        return removerFila(fila);
    }
    NoF *temp = fila->frente;
    for (int i = 0; temp != NULL && i < posicao - 1; i++) {
        temp = temp->proximo;
    }
    if (temp == NULL || temp->proximo == NULL) {
        printf("\n\nPosi��o inv�lida.\n\n"); 
        return -1; 
    }
    NoF *noRemovido = temp->proximo;
    int dado = noRemovido->dado;
    temp->proximo = noRemovido->proximo;
    if (temp->proximo == NULL) {
        fila->tras = temp;
    }
    free(noRemovido);
    return dado;
}

int fila() {
    
    Fila *fila = criaFila();

    int opcao, valor, posicao;

    do {
        system ("cls");
        printf("\n\n--------------- Menu ---------------\n\n");
        printf("1. Adicionar elemento �fila\n");
        printf("2. Remover elemento da fila\n");
        printf("3. Ver elemento que est� na frente da fila\n");
        printf("4. Verificar se a fila est� vazia\n");
        printf("5. Exibir todos os elementos da fila\n");
        printf("6. Inserir elemento no meio da fila\n");
        printf("7. Remover elemento do meio da fila\n");
        printf("0. Sair\n\n");
        printf("Escolha uma op��o: ");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n\nDigite o valor a ser adicionado: ");
                scanf("%d", &valor);
                incluirFila(fila, valor);
                system ("pause");
                system ("cls");
                break;

            case 2:
                valor = removerFila(fila);
                if (valor != -1) {
                    printf("\n\nElemento removido: %d\n\n", valor);
                    system ("pause");
               		system ("cls");	
                }
                break;

            case 3:
                valor = inicioFila(fila);
                if (valor != -1) {
                    printf("\n\nElemento na frente da fila: %d\n\n", valor);
                    system ("pause");
               		system ("cls");	
                }
                break;

            case 4:
                if (filaVazia(fila)) { //se retornar 1 executa
                    printf("\n\nA fila est� vazia.\n\n");
                } else {
                    printf("\n\nA fila n�o est� vazia.\n\n");
                    system ("pause");
               		system ("cls");	
                }
                break;

            case 5:
                printf("\n\nElementos da fila: ");
                exibirFila(fila);
                system ("pause");
               	system ("cls");	
                break;

            case 6:
                printf("\n\nDigite o valor a ser inserido: ");
                scanf("%d", &valor);
                printf("\nDigite a posi��o em que deseja inserir: ");
                scanf("%d", &posicao);
                inserirNoMeioFila(fila, valor, posicao);
                system ("pause");
               	system ("cls");	
                break;

            case 7:
    
                printf("\n\nDigite a posi��o do elemento a ser removido: ");
                scanf("%d", &posicao);
                valor = removerDoMeioFila(fila, posicao);
                if (valor != -1) {
                    printf("\nElemento removido da posi��o %d: %d\n\n", posicao, valor);
                }
                system ("pause");
               	system ("cls");	
                break;

            case 0:
                while (!filaVazia(fila)) {
                    removerFila(fila);
                }
                free(fila);
                printf("\n\nSaindo...\n\n");
                system ("pause");
               	system ("cls");	
                break;

            default:
                printf("\n\nOp��o inv�lida. Tente novamente.\n\n");
                system ("pause");
               	system ("cls");	
        }
    } while (opcao != 0); 

    return 0; 
}
