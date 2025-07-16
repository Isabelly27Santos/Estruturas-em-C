#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pilha_dinamica.h"
#include "fila_dinamica.h"


int main(void) {
    int opcao;
    setlocale (LC_ALL,"Portuguese");

    do {
        system ("cls");
        printf("\n\n------------------ Menu ------------------\n");
        printf("1. Exemplo de Pilha com Lista Dinâmica\n");
        printf("2. Exemplo de Fila com Lista Dinâmica\n");
        printf("0. Sair\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                pilha();
                break;
            case 2:
                fila();
                break;
            case 0:
                printf("\n\nSaíndo do programa. Obrigado!\n\n");
                break;
            default:
                printf("\n\nOpção inválida.\n\n");
        }
    } while (opcao != 0);

    return 0;
}
