#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int comparacao_ponteiro(){
    system ("cls");
    setlocale(LC_ALL,"Portuguese");
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr1 = arr; // Ponteiro ptr1 aponta para o primeiro elemento do array
    int *ptr2 = arr + 2; // Ponteiro ptr2 aponta para o terceiro elemento do array

    // Comparando os ponteiros
    if (ptr1 < ptr2) {
        printf("ptr1 aponta para um endereço anterior a ptr2\n");
    } else if (ptr1 > ptr2) {
        printf("ptr1 aponta para um endereço posterior a ptr2\n");
    } else {
        printf("ptr1 e ptr2 apontam para o mesmo endereço.\n\n\n");
    }
    printf("Encerrado!\n\n");
    getchar();
    getchar();
    return 0;
}
