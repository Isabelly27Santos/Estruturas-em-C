#include <stdio.h>
#include <stdlib.h>

// Defini��o do tipo Aluno
typedef struct {
    char nome[50];
    float *notas;
    int num_notas;
} Aluno;

int ex6_registro() {
    int num_alunos; // Vari�vel para armazenar o n�mero de alunos
    printf("\n\nDigite o n�mero de alunos: ");
    scanf("%d", &num_alunos); // Solicita ao usu�rio para digitar o n�mero de alunos

    // Aloca��o din�mica de mem�ria para um array de alunos
    Aluno *ptr = (Aluno *) malloc(num_alunos * sizeof(Aluno));

    // Verifica se a aloca��o de mem�ria foi bem-sucedida
    if (ptr == NULL) {
        printf("Erro! Nao foi possivel alocar memoria.\n");
        getchar();
        getchar();
        return 1; // Termina o programa com c�digo de erro
    }

    // Solicita ao usu�rio para digitar os dados de cada aluno
    for (int i = 0; i < num_alunos; i++) {
        printf("\nDigite o nome do aluno %d: ", i + 1);
        scanf("%s", ptr[i].nome);
        printf("\nDigite o n�mero de notas do aluno %d: ", i + 1);
        scanf("%d", &ptr[i].num_notas);

        // Aloca��o din�mica de mem�ria para armazenar as notas do aluno
        ptr[i].notas = (float *) malloc(ptr[i].num_notas * sizeof(float));

        // Verifica se a aloca��o de mem�ria foi bem-sucedida
        if (ptr[i].notas == NULL) {
            printf("Erro! Nao foi possivel alocar memoria.\n");
            getchar();
            getchar();
            return 1; // Termina o programa com c�digo de erro
        }

        // Solicita ao usu�rio para digitar as notas do aluno
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
    // Libera a mem�ria alocada dinamicamente
    for (int i = 0; i < num_alunos; i++) {
        free(ptr[i].notas);
    }
    free(ptr);

    return 0;
}
