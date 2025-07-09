#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int incremento_decremento(){
    system ("cls");
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // Inicializando o ponteiro ptr para apontar para o primeiro elemento do array
    printf("\n\nvetor e ponteiro criados, agora o *ptr aponta para o primeiro índice do vetor.\n\n\t{ ");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d ", *(ptr + i)); // Imprime o valor apontado por ptr + i
    }
    printf("} - vetor impresso usando *ptr + i dentro do for.\n");
    printf("\nprintf *ptr: %d\n", *ptr); // Imprime o valor apontado por ptr (10)

    // Incrementando o ponteiro ptr

    ptr++;
    printf("\n*ptr++;\nprintf *ptr: %d\n", *ptr); // Imprime o valor apontado por ptr (20)

    // Decrementando o ponteiro ptr
    ptr--;
    printf("\n*ptr--;\nprintf *ptr: %d\n\n", *ptr); // Imprime o valor apontado por ptr (10) novamente

    // Realizando operações aritméticas com o ponteiro

    ptr +=2;
    printf("*ptr +=2;\n printf *ptr: %d\n\n", *ptr); // Imprime o valor apontado por ptr (30)

    ptr -=1;
    printf("*ptr -=1;\nprintf *ptr: %d\n\n", *ptr); // Imprime o valor apontado por ptr (20)

    printf("printf *ptr+=2: %d\n\n", *ptr+=2); // Imprime o valor 20 + 2

    printf("printf *ptr-=1: %d\n", *ptr-=1); // Imprime o valor 20 - 1

    printf("\nPressione qualquer tecla pra continuar...\n\n");
    getch();

    printf("\n--------------------------------------------------------------------\n\n");
    printf("Aprendido:\n\n- Ao utilizar o ponteiro em vetores ou matrizes, o ponteiro sempre vai apontar para o primeiro índice.\n");
    printf("- Fazer operações aritméticas antes do printf altera a posição do índice.\n");
    printf("- Fazer operações dentro do printf altera o valor da variável que o ponteiro aponta.\n\n\n");
    getchar();


    return 0;
}
