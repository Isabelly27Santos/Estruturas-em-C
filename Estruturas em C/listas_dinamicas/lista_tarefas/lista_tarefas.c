
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_tarefas.h"

// Fun��o para criar uma nova tarefa
Tarefa *criaTarefa(const char *titulo, const char *descricao, int completada) {

    Tarefa *novaTarefa = (Tarefa *) malloc(sizeof(Tarefa));
    strncpy(novaTarefa->titulo, titulo, TAMANHO_MAXIMO_TITULO);
    strncpy(novaTarefa->descricao, descricao, TAMANHO_MAXIMO_DESCRICAO);
    novaTarefa->completada = completada;
    novaTarefa->proximo = NULL;

    return novaTarefa;
}


// Fun��o para adicionar uma tarefa no in�cio da lista
void adicionaTarefa(Tarefa **tarefa, const char *titulo, const char *descricao, int completada) {
	
    Tarefa *novaTarefa = criaTarefa(titulo, descricao, completada);

    novaTarefa->proximo = *tarefa; //faz apontar pro pr�ximo da listra, se for o primeiro aponta pra NULL

    *tarefa = novaTarefa; //agora o ponteiro de tarefa no main aponta pra �ltima tarefa adicionada
}


// Fun��o para adicionar uma tarefa na posi��o X
int adicionaTarefaPosicao(Tarefa **tarefaRef, const char *titulo, const char *descricao, int completada, int pos) {

    if (pos < 0)
        return 0;

    Tarefa *novaTarefa = criaTarefa(titulo, descricao, completada);

    if (pos == 0) {
        novaTarefa->proximo = *tarefaRef;
        *tarefaRef = novaTarefa;
        return 1;
    }

    Tarefa *atual = *tarefaRef;
    for (int i = 0; atual != NULL && i < pos - 1; i++) {
        atual = atual->proximo;
    }

    if (atual == NULL)
        return 0;

    novaTarefa->proximo = atual->proximo;
    atual->proximo = novaTarefa;
    return 1;
}


// Fun��o para alterar uma tarefa na posi��o X
int alteraTarefaPosicao(Tarefa *tarefa, int pos, const char *novoTitulo, const char *novaDescricao, int novaCompletada) {
    
	if (pos < 0)
        return 0;

    Tarefa *atual = tarefa;
    for (int i = 0; atual != NULL && i < pos; i++) {
        atual = atual->proximo;
    }

    if (atual == NULL)
        return 0;

    strncpy(atual->titulo, novoTitulo, TAMANHO_MAXIMO_TITULO);
    strncpy(atual->descricao, novaDescricao, TAMANHO_MAXIMO_DESCRICAO);
    atual->completada = novaCompletada;
    return 1;
}


// Fun��o para listar uma tarefa espec�fica
void exibeTarefaPosicao(Tarefa *tarefa, int pos) {
  
    if (pos < 0) {
        printf("\n\nPosi��o inv�lida.\n\n");
        return;
    }

    Tarefa *atual = tarefa;
    for (int i = 0; atual != NULL && i < pos; i++) {
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("\n\nPosi��o inv�lida.\n\n");
        return;
    }

    printf("\nT�tulo: %s\n", atual->titulo);
    printf("Descri��o: %s\n", atual->descricao);
    printf("Completada: %s\n\n", atual->completada ? "Sim" : "N�o");
    printf("------------------------------------\n\n");
}

// Fun��o para marcar uma tarefa como conclu�da
void completarTarefa(Tarefa *tarefa, const char *titulo) {
   
    Tarefa *temp = tarefa;
    while (temp != NULL) {
        if (strcmp(temp->titulo, titulo) == 0) { //retorna 0 se forem iguais
            temp->completada = 1;
            printf("\n\nTarefa '%s' marcada como conclu�da.\n\n", titulo);
            return;
        }
        temp = temp->proximo;
    }
    printf("\n\nTarefa '%s' n�o encontrada.\n\n", titulo);
}

// Fun��o para imprimir todas as tarefas
void exibirTodasTarefas(Tarefa *tarefa) {

    Tarefa *temp = tarefa;
    while (temp != NULL) {
        printf("\nTitulo: %s\n", temp->titulo);
        printf("Descri��o: %s\n", temp->descricao);
        printf("Completada: %s\n", temp->completada ? "Sim" : "N�o"); //se tiver 1 � verdadeiro, se for 0 � falso
        printf("----------------------------------------\n");
        temp = temp->proximo;
    }
}


// Fun��o para excluir uma tarefa na posi��o X
int excluirTarefaPosicao(Tarefa **tarefaRef, int pos) {
	
    if (pos < 0 || *tarefaRef == NULL) {
        return 0;
    }
    
    Tarefa *temp = *tarefaRef;
    
    if (pos == 0) {
        *tarefaRef = temp->proximo;
        free(temp);
        return 1; 
    }

    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->proximo;
    }

    if (temp == NULL || temp->proximo == NULL) return 0;

    Tarefa *next = temp->proximo->proximo;
    free(temp->proximo); 
    temp->proximo = next;
    return 1; 
}

// Fun��o para liberar a mem�ria alocada para a lista
void liberarMemoria(Tarefa *tarefa) {
    // Vari�vel tempor�ria para percorrer a lista de tarefas
    Tarefa *temp;
    // Percorre a lista e libera a mem�ria alocada para cada n�
    while (tarefa != NULL) {
        temp = tarefa;
        tarefa = tarefa->proximo;
        free(temp);
    }
}

void exemploListaTarefas() {
	system ("cls");
    Tarefa *tarefa = NULL;
    int opcao, pos, completada;
    char titulo[TAMANHO_MAXIMO_TITULO], descricao[TAMANHO_MAXIMO_DESCRICAO];

    while (1) {
   
        printf("\n\n----------------- Menu de Lista de Tarefas -----------------\n\n");
        printf("1. Incluir uma tarefa no in�cio\n");
        printf("2. Incluir uma tarefa na posi��o X\n");
        printf("3. Exibir todas as tarefas\n");
        printf("4. Completar uma tarefa\n");
        printf("5. Editar uma tarefa da lista\n");
        printf("6. Buscar uma tarefa na lista\n");
        printf("7. Excluir uma tarefa\n");
        printf("0. Voltar ao menu principal\n\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao); 
        getchar(); 

        switch (opcao) {
            case 1:
                printf("\n\nDigite o t�tulo da tarefa: "); 
                fgets(titulo, TAMANHO_MAXIMO_TITULO, stdin);
                titulo[strcspn(titulo, "\n")] = 0; 
                printf("\nDigite a descri��o da tarefa: "); 
                fgets(descricao, TAMANHO_MAXIMO_DESCRICAO, stdin);
                descricao[strcspn(descricao, "\n")] = 0;
                printf("\nA tarefa est� completa? (0 para n�o, 1 para sim): ");
                scanf("%d", &completada); 
                adicionaTarefa(&tarefa, titulo, descricao, completada); 
            	system ("pause");
            	system ("cls");
                break;
                
            case 2:
                printf("\n\nDigite o t�tulo da tarefa: ");
                fgets(titulo, TAMANHO_MAXIMO_TITULO, stdin);
                titulo[strcspn(titulo, "\n")] = 0;
                printf("\nDigite a descri��o da tarefa: ");
                fgets(descricao, TAMANHO_MAXIMO_DESCRICAO, stdin);
                descricao[strcspn(descricao, "\n")] = 0; 
                printf("\nDigite a posi��o em que deseja inserir a tarefa: ");
                scanf("%d", &pos);
                printf("\nA tarefa est� completa? (0 para n�o, 1 para sim): ");
                scanf("%d", &completada);
                if (adicionaTarefaPosicao(&tarefa, titulo, descricao, completada, pos)) {
                    printf("\n\nTarefa adicionada com sucesso.\n\n");
                } else {
                    printf("\n\nPosi��o inv�lida.\n\n");
                }
                system ("pause");
            	system ("cls");
                break;
                
            case 3:
                printf("\n\n--------------------- Lista de Tarefas ---------------------\n");
                exibirTodasTarefas(tarefa);
                system ("pause");
            	system ("cls");
                break;
                
            case 4:
                printf("\n\nDigite o t�tulo da tarefa a ser marcada como completa: ");
                fgets(titulo, TAMANHO_MAXIMO_TITULO, stdin);
                titulo[strcspn(titulo, "\n")] = 0; 
                completarTarefa(tarefa, titulo);
                system ("pause");
            	system ("cls");
                break;
                
            case 5:
                printf("\n\nDigite a posic�o da tarefa a ser editada: ");
                scanf("%d", &pos);
                getchar(); 
                printf("\nDigite o novo t�tulo da tarefa: ");
                fgets(titulo, TAMANHO_MAXIMO_TITULO, stdin);
                titulo[strcspn(titulo, "\n")] = 0;
                printf("\nDigite a nova descri��o da tarefa: ");
                fgets(descricao, TAMANHO_MAXIMO_DESCRICAO, stdin);
                descricao[strcspn(descricao, "\n")] = 0; 
                printf("\nA tarefa est� completa? (0 para n�o, 1 para sim): ");
                scanf("%d", &completada);
                if (alteraTarefaPosicao(tarefa, pos, titulo, descricao, completada)) {
                    printf("\n\nTarefa alterada com sucesso.\n\n");
                } else {
                    printf("\n\nPosi��o inv�lida.\n\n");
                }
                system ("pause");
            	system ("cls");
                break;
                
            case 6:
                printf("\n\nDigite a posi��o da tarefa a ser exibida: ");
                scanf("%d", &pos);
                exibeTarefaPosicao(tarefa, pos);
                system ("pause");
            	system ("cls");
                break;
                
            case 7:
                printf("\n\nDigite a posi��o da tarefa a ser exclu�da: ");
                scanf("%d", &pos);
                if (excluirTarefaPosicao(&tarefa, pos)) {
                    printf("\n\nTarefa exclu�da com sucesso.\n\n");
                } else {
                    printf("\n\nPosi��o inv�lida.\n\n");
                }
                system ("pause");
            	system ("cls");
                break;
                
            case 0:
                liberarMemoria(tarefa);
                printf("\n\nVoltando ao menu principal...\n\n");
                system ("pause");
            	system ("cls");
                return;
            default:
                printf("\n\nOp��o inv�lida.\n\n");
                system ("pause");
            	system ("cls");
        }
    }
}
