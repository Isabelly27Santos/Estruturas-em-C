#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Pilha {
    char* urls[100];
    int topo; //marca o �ndice da �ltima url adicionada
};

typedef struct Pilha Pilha;

typedef struct No {
    char url[256];
    struct No* prox; //cont�m todos os n�s da fila
} No;

struct Fila {
    No* inicio_fila; //tem o endere�o do n� inicial
    No* fim_fila; //tem o endere�o do n� final
};

typedef struct Fila Fila;

// Prot�tipos
Pilha* inicializaPilha();
void remove_fila (Fila* f);
void empilha(Pilha* p, const char* url);
char* desempilha(Pilha* p);
int vaziaPilha(Pilha* p);
void exibirPilha(Pilha* p);
void liberaPilha(Pilha* p);
Fila* inicializaFila();
void enfileira(Fila* f, const char* url);
void exibirFila(Fila* f);
void liberaFila(Fila* f);
void carregarUrls(const char* nomeArquivo, Fila* f, Pilha* p, char* atual);

int main() {
    setlocale(LC_ALL, "Portuguese");

    Pilha* ptr_pilha = inicializaPilha();
    Fila* ptr_fila = inicializaFila();
    char atual[256] = ""; //indica a ultima url adicionada

    int opcao;
    char url[256];

    while (1) {
        system("cls"); 
        printf("\n\n\n---------------- Menu ----------------\n");
        printf("1 - Navegar para nova URL (adiciona a url nas listas)\n");
        printf("2 - Voltar para URL anterior (remove a url das listas)\n");
        printf("3 - Exibir hist�rico em pilha\n");
        printf("4 - Exibir hist�rico em fila\n");
        printf("5 - Carregar URLs do arquivo\n");
        printf("0 - Sair\n\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                printf("\nDigite a nova URL: ");
                fgets(url, 256, stdin);
                url[strcspn(url, "\n")] = '\0';
                if ((strstr(url, "www.") != NULL && strstr(url, ".com") != NULL)){ //verifica se existe www e .com na string
                	empilha(ptr_pilha, url);
                	enfileira(ptr_fila, url);
                	strcpy(atual, url); //copia o conte�do de url na atual
                	printf("Voc� est� acessando: %s\n", atual);
				}
				else {
					printf ("\n\nURL inv�lida! Tente novamente\n\n");
				}
                system("pause");
                break;
            case 2:
                if (!vaziaPilha(ptr_pilha)) {  //executa se a condi��o de vazia for falsa
                	remove_fila(ptr_fila);
                    strcpy(atual, desempilha(ptr_pilha));
                    printf("Voltando para: %s\n", atual);
                } else {
                    printf("Sem hist�rico para voltar.\n");
                }
                system("pause");
                break;
            case 3:
                exibirPilha(ptr_pilha);
                system("pause");
                break;
            case 4:
                exibirFila(ptr_fila);
                system("pause");
                break;
            case 5:
                carregarUrls("urls.txt", ptr_fila, ptr_pilha, atual);
                system("pause");
                break;
            case 0:
                printf("Encerrando...\n");
                liberaPilha(ptr_pilha);
                liberaFila(ptr_fila);
                system("pause");
                return 0;
        }
    }
}

Fila* inicializaFila() {
    Fila* f = malloc(sizeof(Fila));
    f->inicio_fila = f->fim_fila = NULL;
    return f;
}

void enfileira(Fila* f, const char* url) {
    No* novo = malloc(sizeof(No));
    strcpy(novo->url, url);
    novo->prox = NULL;
    if (f->fim_fila) f->fim_fila->prox = novo; //o mesmo que if (f->fim_fila != NULL)
    else f->inicio_fila = novo;
    f->fim_fila = novo;
}

void exibirFila(Fila* f) {
    printf("\nURLs organizadas em fila:\n");
    No* atual = f->inicio_fila;
    while (atual) {
        printf("- %s\n", atual->url);
        atual = atual->prox; //imprime da primeira url adicionada at� a �ltima
    }
}

void liberaFila(Fila* f) {
    No* atual = f->inicio_fila;
    while (atual) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(f);
}

void remove_fila (Fila* f){
	if (f->inicio_fila != NULL) {
        No* temp = f->inicio_fila;
        f->inicio_fila = f->inicio_fila->prox;
        if (f->inicio_fila == NULL) {
            f->fim_fila = NULL; // Fila ficou vazia
        }
        free(temp);
    }
}

void carregarUrls(const char* nomeArquivo, Fila* f, Pilha* p, char* atual) {
    FILE* arq = fopen(nomeArquivo, "r"); //abre o arquivo urls.txt para leitura, retorna NULL em caso de erro
    if (!arq) { // o mesmo que if (arq == NULL)
        printf("Erro ao abrir %s\n", nomeArquivo);
        return;
    }

    char linha[256];
    while (fgets(linha, 256, arq)) { //l� o arquivo de linha em linha e s� para quando chega ao final do texto
        linha[strcspn(linha, "\n")] = '\0';
        empilha(p, linha); 
        enfileira(f, linha);
        strcpy(atual, linha);
        printf("URL carregada: %s\n", atual);
    }

    fclose(arq);
}

Pilha* inicializaPilha() {
    Pilha* p = malloc(sizeof(Pilha));
    p->topo = -1;
    return p;
}

void empilha(Pilha* p, const char* url) {
    if (p->topo < 99) {
        p->urls[++p->topo] = strdup(url); //aloca espa�o, copia o conte�do de url e retorna um ponteiro em p->urls []
    }
}

char* desempilha(Pilha* p) {
    if (p->topo >= 0) {
    	char* temp = strdup(p->urls[p->topo]); 
    	free (p->urls[p->topo--]);
        return temp;
    }
    return "";
}

int vaziaPilha(Pilha* p) {
    return p->topo == -1; //retorna 1 se a condi��o for verdadeira e 0 se a condi��o for falsa
}

void exibirPilha(Pilha* p) {
    printf("\nHist�rico de Navega��o (Pilha):\n");
    for (int i = p->topo; i >= 0; i--) { //imprime a pilha da �ltima url adicionada at� a primeira
        printf("- %s\n", p->urls[i]);
    }
}

void liberaPilha(Pilha* p) {
    for (int i = 0; i <= p->topo; i++) {
        free(p->urls[i]);
    }
    free(p);
}