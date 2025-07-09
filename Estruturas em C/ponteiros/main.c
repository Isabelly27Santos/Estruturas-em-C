#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int ponteiro();

int incremento_decremento();

int aritimetica();

int acesso_memoria();

int comparacao_ponteiro();

int main(void) {

    setlocale(LC_ALL, "en_US.UTF-8");

    int opcao;

    do {
        // Exibindo o menu de opções
        printf("\n\n------------------- Menu -------------------\n\n");
        printf("1. Função de Ponteiro\n");
        printf("2. Função de Incremento e decremento\n");
        printf("3. Função de Aritimética\n");
        printf("4. Função de Comparação de ponteiro\n");
        printf("5. Função de Acesso inválido de memória\n");
        printf("0. Sair\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Verificando a opção escolhida e chamando a função correspondente
        switch (opcao) {
            case 1:
                ponteiro();
                system ("pause");
                system ("cls");
                break;
            case 2:
                incremento_decremento();
                system ("pause");
                system ("cls");
                break;
            case 3:
                aritimetica();
                system ("pause");
                system ("cls");
                break;
            case 4:
                comparacao_ponteiro();
                system ("pause");
                system ("cls");
                break;
            case 5:
                acesso_memoria();
                system ("pause");
                system ("cls");
                break;
            case 0:
                printf("Saindo do programa. Obrigado!\n\n\n");
                system ("pause");
                break;
            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n\n\n");
                system ("pause");
                system ("cls");
        }
    } while (opcao != 0);

    return 0;
}
