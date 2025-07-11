#include <stdio.h>
#include <stdlib.h>

int ex4_notas() {
    int num_notas; // Vari�vel para armazenar o n�mero de notas do aluno
    printf("\n\nDigite o n�mero de notas do aluno: ");
    scanf("%d", &num_notas); // Solicita ao usu�rio para digitar o n�mero de notas

    // Aloca��o din�mica de mem�ria para armazenar as notas
    float *notas = (float *) malloc(num_notas * sizeof(float));
/**
sizeof(float): Esta parte determina o tamanho em bytes de um
 n�mero do tipo float.  Um float � geralmente representado
 usando 4 bytes (32 bits).

num_notas * sizeof(float): Multiplica o n�mero de notas (num_notas)
 pelo tamanho de cada nota em bytes (determinado por sizeof(float)),
 resultando no total de bytes necess�rio para armazenar todas as notas.

malloc(num_notas * sizeof(float)): A fun��o malloc() � usada para
 alocar dinamicamente mem�ria na quantidade especificada de bytes.
 Neste caso, estamos alocando mem�ria suficiente para armazenar
 todas as notas do aluno.

(float *)malloc(...): A fun��o malloc() retorna um ponteiro
 void * para o bloco de mem�ria alocado. No entanto,
 como queremos armazenar valores float,
 fazemos um cast do ponteiro (converter para ponteiro)
 retornado por malloc() para float *. Isso informa
 ao compilador que o ponteiro retornado por malloc()
 ser� usado para armazenar valores float.

float *notas = ...: Finalmente, armazenamos o ponteiro retornado
 por malloc() na vari�vel notas, que � declarada como um
 ponteiro para float. Notas aponta para o in�cio do bloco de
 mem�ria alocado dinamicamente, que pode ser usado para
 armazenar as notas do aluno.
*/
    // Verifica se a aloca��o de mem�ria foi bem-sucedida
    if (notas == NULL) {
        printf("Erro! Nao foi possivel alocar memoria.\n");
        return 1; // Termina o programa com c�digo de erro
    }

    // Solicita ao usu�rio para digitar as notas
    printf("\n\nDigite as notas do aluno:\n\n");
    for (int i = 0; i < num_notas; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    // Calcula a m�dia das notas
    float soma = 0;
    for (int i = 0; i < num_notas; i++) {
        soma += notas[i];
    }
    float media = soma / num_notas;

    // Imprime a m�dia das notas
    printf("\n\nM�dia do aluno: %.2f\n", media);
    getchar();
    getchar();
    // Libera a mem�ria alocada dinamicamente
    free(notas);

    return 0;
}
