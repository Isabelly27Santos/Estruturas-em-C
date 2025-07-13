#include <stdio.h>

int main() {
    int vetor[10] = {5, 2, 9, 1, 7, 6, 8, 3, 10, 4};
    int i, j, temp; //temp=temporario

    // Ordenando em ordem decrescente com bubble sort
    for (i = 0; i < 10 - 1; i++) {
        for (j = 0; j < 10 - 1 - i; j++) {// troca se o da frente for maior
            if (vetor[j] < vetor[j + 1]) { //para ordem crescente, apenas mude < para >
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }

    // Exibindo o vetor ordenado
    printf("Vetor em ordem decrescente:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}

