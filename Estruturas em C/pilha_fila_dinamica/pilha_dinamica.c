#include "pilha_dinamica.h" 

// Fun��o para criar um novo n�
NoP* criaNo(int dado) {

    NoP* novoNo = (NoP*)malloc(sizeof(NoP));
    if (!novoNo) {
        printf("Erro de alocacao de memoria.\n"); 
        exit(1); 
    }
    novoNo->dado = dado; 
    novoNo->proximo = NULL; 
    return novoNo;
}

// Fun��o para empilhar (push) um elemento
void empilhar(NoP** topo, int dado) {
   
    NoP* novoNo = criaNo(dado);
    novoNo->proximo = *topo; //aporta pro �ltimo inserido
    *topo = novoNo;
    printf("\n\nEmpilhado: %d\n\n", dado);
}

// Fun��o para desempilhar (pop) um elemento
int desempilhar(NoP** topo) {
    
    if (*topo == NULL) {
        printf("\n\nPilha vazia.\n\n"); 
        return -1; 
    }
    NoP* temp = *topo;
    int dado = temp->dado;
    *topo = (*topo)->proximo;
    free(temp);
    return dado;
}

// Fun��o para ver o elemento no topo da pilha sem remov�-lo (topoPilha)
int topoPilha(NoP* topo) {
 
    if (topo == NULL) {
        printf("\n\nPilha vazia.\n\n"); 
        return -1; 
    }
    return topo->dado;
}

// Fun��o para verificar se a pilha est� vazia
int pilhaVazia(NoP* topo) {
    return topo == NULL; //retorna 1 se verdadeiro
}

// Fun��o para exibir todos os elementos da pilha
void exibirPilha(NoP* topo) {
  
    NoP* temp = topo;
    while (temp != NULL) {
        printf("%d -> ", temp->dado);
        temp = temp->proximo;
    }
    printf("NULL\n\n");
}

// Fun��o para inserir um elemento em uma posi��o espec�fica da pilha
void inserirNoMeioPilha(NoP** topo, int dado, int posicao) {
    
    if (posicao < 0) {
        printf("\n\nPosi��o inv�lida.\n\n"); 
        return;
    }
    if (posicao == 0) {
        empilhar(topo, dado); 
        return;
    }
    NoP* novoNo = criaNo(dado);
    NoP* temp = *topo;
    for (int i = 0; temp != NULL && i < posicao - 1; i++) {
        temp = temp->proximo;
    }
    if (temp == NULL) {
        printf("\n\nPosi��o inv�lida.\n\n"); 
        free(novoNo); 
    } else {
        novoNo->proximo = temp->proximo;
        temp->proximo = novoNo;
        printf("\n\nInserido: %d na posi��o %d\n\n", dado, posicao);
    }
}

int pilha() {
  
    NoP* topo = NULL;
    int opcao, valor, posicao;

    do {
    	system ("cls");
        printf("\n------------------- Menu -------------------\n\n");
        printf("1. Empilhar elemento\n");
        printf("2. Desempilhar elemento\n");
        printf("3. Ver elemento no topo\n");
        printf("4. Verificar se a pilha est� vazia\n");
        printf("5. Exibir todos os elementos da pilha\n");
        printf("6. Inserir elemento no meio da pilha\n");
        printf("0. Sair\n\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n\nDigite o valor a ser empilhado: ");
                scanf("%d", &valor);
                empilhar(&topo, valor);
                system ("pause");
                system ("cls");
                break;
                
            case 2:
                valor = desempilhar(&topo);
                if (valor != -1) {
                    printf("\n\nElemento desempilhado: %d\n\n", valor);
                    system ("pause");
               		system ("cls");
                }
                break;
                
            case 3:
                valor = topoPilha(topo);
                if (valor != -1) {
                    printf("\n\nElemento no topo: %d\n\n", valor);
                    system ("pause");
                	system ("cls");
                }
                break;
                
            case 4:
                if (pilhaVazia(topo)) { //executa se verdadeiro
                    printf("\n\nA pilha est� vazia.\n");
                } else {
                    printf("\n\nA pilha n�o est� vazia.\n\n");
                }
                system ("pause");
                system ("cls");
                break;
                
            case 5:
                printf("\n\nElementos da pilha: ");
                exibirPilha(topo);
                system ("pause");
                system ("cls");
                break;
                
            case 6:
                printf("\n\nDigite o valor a ser inserido: ");
                scanf("%d", &valor);
                printf("\nDigite a posi��o em que deseja inserir: ");
                scanf("%d", &posicao);
                inserirNoMeioPilha(&topo, valor, posicao);
                system ("pause");
                system ("cls");
                break;
                
            case 0:
                while (!pilhaVazia(topo)) {
                    desempilhar(&topo);
                }
                printf("\n\nSaindo...\n\n");
                system ("pause");
                system ("cls");
                break;
                
            default:
                printf("\n\nOp��o inv�lida. Tente novamente.\n\n");
        }
    } while (opcao != 0);

    return 0;
}