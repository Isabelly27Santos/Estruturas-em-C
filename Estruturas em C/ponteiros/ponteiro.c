#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int ponteiro() {
    system ("cls");
    int x = 10, *ptr; // Declaração de uma variável inteira x

    ptr = &x;   // Atribuição do endereço de x ao ponteiro ptr

    // Exibindo o valor de x e o valor apontado por ptr
    printf("\n\nint x = 10, *ptr;\t//variáveis criadas.\nptr = &x;\t\t//ptr agora aponta pra x.\n\nResultado:\n\n");
    printf("\tprintf x: %d\n", x);
    printf("\tprintf *ptr: %d\n", *ptr);
    printf("\tprintf ptr: %d\n", ptr);
    printf("\tprintf &x: %d\n", &x);
    printf("\nPressione qualquer tecla pra continuar...\n\n");
    getch();

    // Alterando o valor de x através do ponteiro
    *ptr = 20;
    printf("\n*ptr = 20;\n\n");

    // Exibindo o novo valor de x e o valor apontado por ptr
    printf("Novo valor de x: %d\n", x);
    printf("Novo valor apontado por ptr: %d\n", *ptr);
    printf("\n\n--------------------------------------------------------------------\n\n");
    printf("Aprendido:\n\n- Ao criar o ponteiro, declare ele como tipo *ptr.");
    printf("\n- Para fazer ele apontar pra uma variável escreva ptr = &var. ");
    printf("\n- Para acessar o endereço da variável escreva &var ou ptr. ");
    printf("\n- Para acessar o valor da variável escreva var ou *ptr.");
    printf("\n- Para alterar o conteúdo de ptr e var escreva *ptr = dado.\n\n\n");
    getchar();
    return 0;

}
