#include <stdio.h>
#include <stdlib.h>

int ex3_realloc() {
    int *ptr; // Declara��o de um ponteiro para armazenar o endere�o do bloco de mem�ria alocado

    int tamanho; // Vari�vel para armazenar o tamanho inicial do array
    printf("\n\nDigite o tamanho inicial do array: ");
    scanf("%d", &tamanho); // Solicita ao usu�rio para digitar o tamanho inicial do array

    // Aloca��o din�mica de mem�ria usando malloc
    ptr = (int *) malloc(tamanho * sizeof(int));

    // Verifica se a aloca��o de mem�ria foi bem-sucedida
    if (ptr == NULL) {
        printf("\nErro! N�o foi possivel alocar memoria.\n");
        getchar();
        getchar();
        return 1; // Termina o programa com c�digo de erro
    }
    // Preenche o array alocado dinamicamente com n�meros
    for (int i = 0; i < tamanho; i++) {
        ptr[i] = i + 100; // Preenche o array com n�meros de 100 a tamanho
    }
    // Imprime os elementos do array inicial
    printf("\nElementos do array inicial: { ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", ptr[i]);
    }
    printf("}\n");


    int novo_tamanho; // Vari�vel para armazenar o novo tamanho do array
    printf("\nDigite o novo tamanho do array: ");
    scanf("%d", &novo_tamanho); // Solicita ao usu�rio para digitar o novo tamanho do array

    // Realoca��o din�mica de mem�ria usando realloc
    ptr = (int *) realloc(ptr, novo_tamanho * sizeof(int));

    // Verifica se a realoca��o de mem�ria foi bem-sucedida
    if (ptr == NULL) {
        printf("\nErro! N�o foi poss�vel realocar mem�ria.\n");
        return 1; // Termina o programa com c�digo de erro
    }

    // Imprime os elementos do array ap�s a realoca��o
    printf("\nElementos do array ap�s a realoca��o: { ");
    for (int i = 0; i < novo_tamanho; i++) {
        printf("%d ", ptr[i]=i+100);
    }
    printf("}\n\n");
    getchar();
    getchar();
    // Libera a mem�ria alocada dinamicamente
    free(ptr);

    return 0;
}
