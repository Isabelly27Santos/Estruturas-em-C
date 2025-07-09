#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_VERTICES 10

// Variáveis globais
int num_vertices = 0;
int vertices[MAX_VERTICES];
int matriz_adj[MAX_VERTICES][MAX_VERTICES];  // Matriz de adjacência
int opcao = 1;

// Prototipação
int definir_tamanho_grafo();
void desenhar_vertices();
void desenhar_matriz();
void inserir_aresta();
void remover_aresta();
void mostrar_menu();

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Definindo o número de vértices
    while (num_vertices <= 0 || num_vertices > MAX_VERTICES) {
        num_vertices = definir_tamanho_grafo();

        if (num_vertices <= 0 || num_vertices > MAX_VERTICES) {
            system("cls");
            printf("Escolha um valor entre 1 e %d!\n\n", MAX_VERTICES);
        } else {
            for (int i = 0; i < num_vertices; i++) {
                vertices[i] = i;
            }
        }
    }

    // Loop principal do programa
    while (opcao != 0) {
        system("cls");
        desenhar_vertices();
        desenhar_matriz();
        mostrar_menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir_aresta();
                break;
            case 2:
                remover_aresta();
                break;
        }
    }

    system("pause");
    return 0;
}

// Solicita ao usuário o número de vértices
int definir_tamanho_grafo() {
    int tamanho;
    printf("Digite a quantidade de vértices do grafo: ");
    scanf("%d", &tamanho);
    return tamanho;
}

// Mostra os vértices na tela
void desenhar_vertices() {
    printf("Lista de vértices:\n[ ");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d ", vertices[i]);
    }
    printf("]\n\n");
}

// Mostra a matriz de adjacência (conexões entre vértices)
void desenhar_matriz() {
    int i;
    printf("Matriz de adjacência:\n\n\    ");
    for (i = 0; i < num_vertices; i++){
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < num_vertices; i++){
        printf("---");
    }
    printf("\n");
    for (i= 0; i < num_vertices; i++) {
        printf("%d |",i);
        for (int j = 0; j < num_vertices; j++) {
            printf(" %d", matriz_adj[i][j]);
        }
        printf("\n");
    }
}

// Adiciona uma aresta entre dois vértices
void inserir_aresta() {
    int origem, destino;
    system("cls");

    printf("Digite o vértice de origem (0 a %d): ", num_vertices - 1);
    scanf("%d", &origem);

    printf("Digite o vértice de destino (0 a %d): ", num_vertices - 1);
    scanf("%d", &destino);

    if (origem < 0 || origem >= num_vertices || destino < 0 || destino >= num_vertices) {
        printf("\nValores inválidos! Use números entre 0 e %d.\n\n", num_vertices - 1);
        system("pause");
    } else {
        matriz_adj[origem][destino] = 1;
        matriz_adj[destino][origem] = 1; // Grafo não direcionado
    }
}

// Remove uma aresta entre dois vértices
void remover_aresta() {
    int origem, destino;
    system("cls");

    printf("Digite o vértice de origem (0 a %d): ", num_vertices - 1);
    scanf("%d", &origem);

    printf("Digite o vértice de destino (0 a %d): ", num_vertices - 1);
    scanf("%d", &destino);

    if (origem < 0 || origem >= num_vertices || destino < 0 || destino >= num_vertices) {
        printf("\nValores inválidos! Use números entre 0 e %d.\n\n", num_vertices - 1);
        system("pause");
    } else {
        matriz_adj[origem][destino] = 0;
        matriz_adj[destino][origem] = 0; // Grafo não direcionado
    }
}

// Exibe as opções do menu
void mostrar_menu() {
    printf("\nEscolha uma opção:\n");
    printf("1 - Inserir aresta\n");
    printf("2 - Remover aresta\n");
    printf("0 - Sair\n\n");
}
