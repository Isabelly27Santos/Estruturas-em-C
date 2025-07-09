#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 2

// Definindo a estrutura de registro Estudante
struct Estudante {
    char nome[50];
    int idade;
    int numero_identificacao;
    float notas[5]; // Suponha que há 5 disciplinas
};

int registro() {
    int i, j, ch;

    system ("cls");
    printf("------ Cadastro de Estudantes ------\n");
    // Declaração de uma variável do tipo Estudante
    struct Estudante estudante[TAM];

    // Preenchendo os dados do estudante
    for (i = 0; i <TAM; i++){
        printf("\nDigite o nome do %dº estudante: ",i+1);
        while ((ch = getchar()) != '\n' && ch != EOF);
        fgets(estudante[i].nome,sizeof(estudante[i].nome),stdin);
        estudante[i].nome[strcspn(estudante[i].nome,"\n")]='\0';

        printf("\nDigite a idade do %dº estudante: ",i+1);
        scanf(" %d", &estudante[i].idade);

        printf("\nDigite o número de identificação do %dº estudante: ",i+1);
        scanf(" %d", &estudante[i].numero_identificacao);

        printf("\nDigite as notas do %dº estudante em 5 disciplinas:\n\n",i+1);
        for (j = 0; j < 5; j++) {
            printf("Nota %d: ", j+1);
            scanf(" %f", &estudante[i].notas[j]);
        }
        printf("\n\n");
        system ("pause");
        system ("cls");
    }

    // Exibindo os dados do estudante
    system ("cls");
    for (i = 0; i <TAM; i++){
        printf("   ...Dados do Estudante...\n\n");
        printf("Nome: %s\n", estudante[i].nome);
        printf("Idade: %d\n", estudante[i].idade);
        printf("Número de Identificação: %03d\n", estudante[i].numero_identificacao);
        printf("\n-----------Notas-------------\n");
        for (j = 0; j < 5; j++) {
            printf("Disciplina %d: %.2f\n", j+1, estudante[i].notas[j]);
        }
        printf("-----------------------------\n\n");

    }
    system ("pause");

    return 0;
}
