#include <stdio.h>
#include <stdlib.h>

int ex7_comparacao_memoria() {
    int tamanho;

    // Solicita ao usu�rio o tamanho do vetor
    printf("\n\nDigite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // Vetor de tamanho fixo
    int arr[tamanho];

    // Vetor com aloca��o din�mica
    int *ptr = (int *)malloc((tamanho) * sizeof(int)); // Alocando tamanho

    if (ptr == NULL) {
        printf("Erro ao alocar memoria para o vetor dinamico.\n");
        getchar();
        getchar();
        return 1; // Termina o programa com c�digo de erro
    }
    for (int i = 0; i <tamanho; ++i) {
        arr[i]=i;
        ptr[i]=i;
    }
    for (int i = 0; i < tamanho; ++i) {
        printf("valor de arr: %d e valor ptr: %d\n", arr[i], ptr[i]);
    }
    // Calcula o tamanho da mem�ria alocada para cada vetor
    size_t tamanho_vetor_fixo = sizeof(arr);
    size_t tamanho_vetor_dinamico = (tamanho) * sizeof(int); // Alocamos metade do tamanho



    // Imprime os tamanhos calculados
    printf("\nTamanho do vetor de tamanho fixo: %zu bytes\n", tamanho_vetor_fixo);
    printf("Tamanho do vetor com aloca��o din�mica: %zu bytes\n", tamanho_vetor_dinamico);
    getchar();
    getchar();
    // Libera a mem�ria alocada dinamicamente
    ptr = NULL;
    free(ptr);

    return 0;
}
