#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int ex1_malloc();

int ex2_calloc();

int ex3_realloc();

int ex4_notas();

int ex5_matriz();

int ex6_registro();

int ex7_comparacao_memoria();

int main(void) {
    // Define a codificação de caracteres para UTF-8
    setlocale(LC_ALL, "en_US.UTF-8");

    int opcao;

    do {
        system ("cls");
        // Exibindo o menu de opções
        printf("\n\n------------------------ Menu ------------------------\n\n");
        printf("1. Exemplo da função Malloc\n");
        printf("2. Exemplo da função Calloc\n");
        printf("3. Exemplo da função Realloc\n");
        printf("4. Exemplo de alocação dinâmica com vetor (notas)\n");
        printf("5. Exemplo de alocação dinâmica com matriz (alunos)\n");
        printf("6. Exemplo de alocação dinâmica com registro (alunos)\n");
        printf("7. Exemplo de camparação com alocação de memória\n");
        printf("0. Sair\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Verificando a opção escolhida e chamando a função correspondente
        switch (opcao) {
            case 1:
                system ("cls");
                ex1_malloc();
                system ("pause");
                break;
            case 2:
                system ("cls");
                ex2_calloc();
                system ("pause");
                break;
            case 3:
                system ("cls");
                ex3_realloc();
                system ("pause");
                break;
            case 4:
                system ("cls");
                ex4_notas();
                system ("pause");
                break;
            case 5:
                system ("cls");
                ex5_matriz();
                system ("pause");
                break;
            case 6:
                system ("cls");
                ex6_registro();
                system ("pause");
                break;
            case 7:
                system ("cls");
                ex7_comparacao_memoria();
                system ("pause");
                break;
            case 0:
                system ("cls");
                printf("\n\nSaíndo do programa. Obrigado!\n\n\n");
                system ("pause");
                break;
            default:
                printf("\n\nOpção inválida. Por favor, escolha uma opção válida.\n\n\n");
        }
    } while (opcao != 0);

    return 0;
}
