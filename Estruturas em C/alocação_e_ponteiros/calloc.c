#include <stdio.h>
#include <stdlib.h>

int ex2_calloc() {
    int *ptr; // Declara��o de um ponteiro para armazenar o endere�o do bloco de mem�ria alocado

    int tamanho; // Vari�vel para armazenar o tamanho do array
    printf("\n\nDigite o tamanho do array: ");
    scanf("%d", &tamanho); // Solicita ao usu�rio para digitar o tamanho do array

    // Aloca��o din�mica de mem�ria usando calloc
    ptr = (int *) calloc(tamanho, sizeof(int));

    // Verifica se a aloca��o de mem�ria foi bem-sucedida
    if (ptr == NULL) {
        printf("Erro! N�o foi poss�vel alocar mem�ria.\n");
        getchar();
        getchar();
        return 1; // Termina o programa com c�digo de erro
    }

    // Imprime os elementos do array
    printf("\n\nElementos do array inicializados com zeros: { ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", ptr[i]);
    }
    printf("}\n");
    getchar();
    getchar();
    // Libera a mem�ria alocada dinamicamente
    free(ptr);

    return 0;
}
