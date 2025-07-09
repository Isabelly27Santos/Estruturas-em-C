#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int vetor();
int matriz();
int registro();

int main(void) {

    setlocale(LC_ALL, "Portuguese");
    system("chcp 1252 > nul");

    int opcao;

    do {
        // Exibindo o menu de opções
        system ("cls");
        printf("\nMenu:\n");
        printf("1. Função Vetor\n");
        printf("2. Função Matriz\n");
        printf("3. Função Registro\n");
        printf("0. Sair\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Verificando a opção escolhida e chamando a função correspondente
        switch (opcao) {
            case 1:
                vetor();
                break;
            case 2:
                matriz();
                break;
            case 3:
                registro();
                break;
            case 0:
                printf("Saindo do programa. Obrigado!\n\n");
                break;
            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
        }
    } while (opcao != 0);

    return 0;
}
