#include <stdio.h>
#include <stdlib.h>

int ex1_malloc() {
    int *ptr; // Declara��o de um ponteiro para armazenar o endere�o do bloco de mem�ria alocado

    int tamanho; // Vari�vel para armazenar o tamanho do array
    printf("\n\nDigite o tamanho do array: ");
    scanf("%d", &tamanho); // Solicita ao usu�rio para digitar o tamanho do array

    // Aloca��o din�mica de mem�ria usando malloc
    ptr = (int *) malloc(tamanho * sizeof(int));

    // Verifica se a aloca��o de mem�ria foi bem-sucedida
    if (ptr == NULL) {
        printf("\n\nErro! N�o foi possivel alocar mem�ria.\n");
        getchar();
        return 1; // Termina o programa com c�digo de erro
    }

    // Preenche o array alocado dinamicamente com n�meros
    for (int i = 0; i < tamanho; i++) {
        ptr[i] = i + 10; // Preenche o array com n�meros de 10 a tamanho
    }

    // Imprime os elementos do array
    printf("Elementos do array: { ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", ptr[i]);
    }
    printf("}\n\n\n");
    getchar();
    getchar();
    // Libera a mem�ria alocada dinamicamente
    free(ptr);

    return 0;
}
