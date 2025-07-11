#include <stdio.h>
#include <stdlib.h>

int acesso_memoria(){
    system ("cls");
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // Inicializando o ponteiro ptr para apontar para o primeiro elemento do array
    printf("\n\nElementos do array {");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d ", *(ptr + i)); // Imprime o valor apontado por ptr + i
    }
    printf("}\n");
    // Tentando acessar um elemento fora dos limites do array
    printf("\n\nValor fora dos limites do array: %d\n\n\n", *(ptr + 10)); // Tentando acessar o 11º elemento
    getchar();
    return 0;
}
