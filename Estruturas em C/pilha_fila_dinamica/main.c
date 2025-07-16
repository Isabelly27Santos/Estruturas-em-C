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
        printf("1. Exemplo de Pilha com Lista Din�mica\n");
        printf("2. Exemplo de Fila com Lista Din�mica\n");
        printf("0. Sair\n");
        printf("\nEscolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                pilha();
                break;
            case 2:
                fila();
                break;
            case 0:
                printf("\n\nSa�ndo do programa. Obrigado!\n\n");
                break;
            default:
                printf("\n\nOp��o inv�lida.\n\n");
        }
    } while (opcao != 0);

    return 0;
}
