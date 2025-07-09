#include <stdio.h>
#include <stdlib.h>

// Definição do tipo Aluno
typedef struct {
    char nome[50];
    float *notas;
    int num_notas;
} Aluno;

int ex6_registro() {
    int num_alunos; // Variável para armazenar o número de alunos
    printf("\n\nDigite o número de alunos: ");
    scanf("%d", &num_alunos); // Solicita ao usuário para digitar o número de alunos

    // Alocação dinâmica de memória para um array de alunos
    Aluno *ptr = (Aluno *) malloc(num_alunos * sizeof(Aluno));

    // Verifica se a alocação de memória foi bem-sucedida
    if (ptr == NULL) {
        printf("Erro! Nao foi possivel alocar memoria.\n");
        getchar();
        getchar();
        return 1; // Termina o programa com código de erro
    }

    // Solicita ao usuário para digitar os dados de cada aluno
    for (int i = 0; i < num_alunos; i++) {
        printf("\nDigite o nome do aluno %d: ", i + 1);
        scanf("%s", ptr[i].nome);
        printf("\nDigite o número de notas do aluno %d: ", i + 1);
        scanf("%d", &ptr[i].num_notas);

        // Alocação dinâmica de memória para armazenar as notas do aluno
        ptr[i].notas = (float *) malloc(ptr[i].num_notas * sizeof(float));

        // Verifica se a alocação de memória foi bem-sucedida
        if (ptr[i].notas == NULL) {
            printf("Erro! Nao foi possivel alocar memoria.\n");
            getchar();
            getchar();
            return 1; // Termina o programa com código de erro
        }

        // Solicita ao usuário para digitar as notas do aluno
        printf("\nDigite as notas do aluno %d:\n\n", i + 1);
        for (int j = 0; j < ptr[i].num_notas; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &ptr[i].notas[j]);
        }
    }

    getchar();
    getchar();
    system ("cls");

    // Imprime os dados dos alunos
    printf("\n\nDados dos alunos:\n");
    for (int i = 0; i < num_alunos; i++) {
        printf("\n\nAluno %d -------------------------\n", i + 1);
        printf("Nome: %s\n", ptr[i].nome);
        printf("Notas: ");
        for (int j = 0; j < ptr[i].num_notas; j++) {
            printf(" %.2f |", ptr[i].notas[j]);
        }
    }
    getchar();
    getchar();
    // Libera a memória alocada dinamicamente
    for (int i = 0; i < num_alunos; i++) {
        free(ptr[i].notas);
    }
    free(ptr);

    return 0;
}
