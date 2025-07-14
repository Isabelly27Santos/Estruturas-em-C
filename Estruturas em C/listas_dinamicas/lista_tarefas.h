
#ifndef LISTA_TAREFAS_H
#define LISTA_TAREFAS_H

#define TAMANHO_MAXIMO_TITULO 100
#define TAMANHO_MAXIMO_DESCRICAO 256

// Estrutura de um n� da lista de tarefas
typedef struct Task {
    char titulo[TAMANHO_MAXIMO_TITULO];
    char descricao[TAMANHO_MAXIMO_DESCRICAO];
    int completada;
    struct Task* proximo;
} Tarefa;

// Fun��o para criar uma nova tarefa
Tarefa* criaTarefa(const char* titulo, const char* descricao, int completada);

// Fun��o para adicionar uma tarefa no in�cio da lista
void adicionaTarefa(Tarefa** tarefa, const char* titulo, const char* descricao, int completada);

// Fun��o para adicionar uma tarefa na posi��o X
int adicionaTarefaPosicao(Tarefa** tarefaRef, const char* titulo, const char* descricao, int completada, int pos);

// Fun��o para alterar uma tarefa na posi��o X
int alteraTarefaPosicao(Tarefa* tarefa, int pos, const char* novoTitulo, const char* novaDescricao, int novaCompletada);

// Fun��o para imprimir todas as tarefas
void exibirTodasTarefas(Tarefa* tarefa);

// Fun��o para listar uma tarefa espec�fica
void exibeTarefaPosicao(Tarefa* tarefa, int pos);

// Fun��o para marcar uma tarefa como conclu�da
void completarTarefa(Tarefa* tarefa, const char* titulo);

// Fun��o para excluir uma tarefa na posi��o X
int excluirTarefaPosicao(Tarefa** tarefaRef, int pos);

// Fun��o para liberar a mem�ria alocada para a lista
void liberarMemoria(Tarefa* tarefa);

// Fun��o principal para demonstrar a lista de tarefas
void exemploListaTarefas();

#endif // LISTA_TAREFAS_H
