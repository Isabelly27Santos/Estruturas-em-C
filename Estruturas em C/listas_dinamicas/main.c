#include <stdio.h>
#include <stdlib.h>
#include <locale.h>>
#include "lista_dinamica.h" // Inclui o cabeçalho da lista dinâmica
#include "lista_duplamente_encadeada.h" // Inclui o cabeçalho da lista duplamente encadeada
#include "lista_tarefas.h" // Inclui o cabeçalho da lista de tarefas

int main(void) {
    int opcao;

    do {
    	setlocale (LC_ALL,"Portuguese");
    	system ("cls");
        // Exibindo o menu de opções
        printf("\n\n------------------- Menu -------------------\n\n");
        printf("1. Exemplo de Lista Dinâmica\n");
        printf("2. Exemplo de Lista Duplamente Encadeada\n");
        printf("3. Exemplo de Lista de Tarefas\n");
        printf("0. Sair\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Verificando a opção escolhida e chamando a função correspondente
        switch (opcao) {
            case 1:
                exemploListaDinamica();
                system ("pause");
                system ("cls");
                break;
            case 2:
                exemploListaDuplamenteEncadeada();
                system ("pause");
                system ("cls");
                break;
            case 3:
                exemploListaTarefas();
                system ("pause");
                system ("cls");
                break;
            case 0:
                printf("\n\nSaindo do programa. Obrigado!\n\n");
                system ("pause");
                system ("cls");
                break;
            default:
                printf("\n\nOpção inválida. Por favor, escolha uma opção válida.\n\n");
                system ("pause");
                system ("cls");
        }
    } while (opcao != 0);

    return 0;
}