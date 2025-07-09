#include <stdio.h>
#include <stdlib.h>

int ex3_realloc() {
    int *ptr; // Declaração de um ponteiro para armazenar o endereço do bloco de memória alocado

    int tamanho; // Variável para armazenar o tamanho inicial do array
    printf("\n\nDigite o tamanho inicial do array: ");
    scanf("%d", &tamanho); // Solicita ao usuário para digitar o tamanho inicial do array

    // Alocação dinâmica de memória usando malloc
    ptr = (int *) malloc(tamanho * sizeof(int));

    // Verifica se a alocação de memória foi bem-sucedida
    if (ptr == NULL) {
        printf("\nErro! Não foi possivel alocar memoria.\n");
        getchar();
        getchar();
        return 1; // Termina o programa com código de erro
    }
    // Preenche o array alocado dinamicamente com números
    for (int i = 0; i < tamanho; i++) {
        ptr[i] = i + 100; // Preenche o array com números de 100 a tamanho
    }
    // Imprime os elementos do array inicial
    printf("\nElementos do array inicial: { ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", ptr[i]);
    }
    printf("}\n");


    int novo_tamanho; // Variável para armazenar o novo tamanho do array
    printf("\nDigite o novo tamanho do array: ");
    scanf("%d", &novo_tamanho); // Solicita ao usuário para digitar o novo tamanho do array

    // Realocação dinâmica de memória usando realloc
    ptr = (int *) realloc(ptr, novo_tamanho * sizeof(int));

    // Verifica se a realocação de memória foi bem-sucedida
    if (ptr == NULL) {
        printf("\nErro! Não foi possível realocar memória.\n");
        return 1; // Termina o programa com código de erro
    }

    // Imprime os elementos do array após a realocação
    printf("\nElementos do array após a realocação: { ");
    for (int i = 0; i < novo_tamanho; i++) {
        printf("%d ", ptr[i]=i+100);
    }
    printf("}\n\n");
    getchar();
    getchar();
    // Libera a memória alocada dinamicamente
    free(ptr);

    return 0;
}
