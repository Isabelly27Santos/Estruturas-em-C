#include <stdio.h>
#include <stdlib.h>

int ex5_matriz() {
    int num_alunos, num_notas; // Vari�veis para armazenar o n�mero de alunos e de notas por aluno
    printf("\n\nDigite o n�mero de alunos: ");
    scanf("%d", &num_alunos);
    // Solicita ao usu�rio para digitar o n�mero de alunos

    printf("\nDigite o n�mero de notas por aluno: ");
    scanf("%d", &num_notas);
    // Solicita ao usu�rio para digitar o n�mero de notas por aluno

    // Aloca��o din�mica de mem�ria para armazenar as notas
    // dos alunos em uma matriz
    float **notas = (float **) malloc(num_alunos * sizeof(float *));
    /**
     sizeof(float *): calcula o tamanho em bytes de um ponteiro
     para float.

     num_alunos * sizeof(float *): Multiplica o n�mero de
      alunos (num_alunos) pelo tamanho de cada ponteiro para
      float em bytes (determinado por sizeof(float *)),
      resultando no total de bytes necess�rio para armazenar
      todos os ponteiros para as linhas da matriz.

    malloc(num_alunos * sizeof(float *)): A fun��o malloc()
     � usada para alocar dinamicamente mem�ria na quantidade
     especificada de bytes. Neste caso, estamos alocando
     mem�ria suficiente para armazenar todos os ponteiros
     para as linhas da matriz.

    (float **)malloc(...): A fun��o malloc() retorna um
     ponteiro void * para o bloco de mem�ria alocado.
     No entanto, como queremos armazenar ponteiros para float,
     fazemos um cast do ponteiro retornado por malloc()
     para float **. Isso informa ao compilador que o ponteiro
     retornado por malloc() ser� usado para armazenar
     ponteiros para float.

    float **notas = ...: Finalmente, armazenamos o ponteiro
     retornado por malloc() na vari�vel notas, que � declarada
     como um ponteiro para ponteiro para float. Agora, notas
     aponta para o in�cio do bloco de mem�ria alocado
     dinamicamente, que pode ser usado para armazenar os
     ponteiros para as linhas da matriz.
     */
    for (int i = 0; i < num_alunos; i++) {
        notas[i] = (float *) malloc(num_notas * sizeof(float));
    }

    // Verifica se a aloca��o de mem�ria foi bem-sucedida
    if (notas == NULL) {
        printf("Erro! Nao foi possivel alocar memoria.\n");
        getchar();
        getchar();
        return 1; // Termina o programa com c�digo de erro
    }

    // Solicita ao usu�rio para digitar as notas de cada aluno
    for (int i = 0; i < num_alunos; i++) {
        printf("\nDigite as notas do aluno %d:\n\n", i + 1);
        for (int j = 0; j < num_notas; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }

    // Imprime as notas dos alunos
    printf("\nNotas dos alunos:\n\n");
    for (int i = 0; i < num_alunos; i++) {
        printf("Aluno %d", i + 1);
        for (int j = 0; j < num_notas; j++) {
            printf(" | %.2f", notas[i][j]);
        }
        printf("\n---------------------------------------\n");
    }
    getchar();
    getchar();
    // Libera a mem�ria alocada dinamicamente
    for (int i = 0; i < num_alunos; i++) {
        free(notas[i]);
    }
    free(notas);

    return 0;
}
