#include "menu.h"

void decisao(){

    char** Quadro = criaquadro();
    int a;
    printf("================================================================================\n");
    printf("MENU\n");
    printf("================================================================================\n");
    printf("O que gostaria de fazer?\n1 - ENTRAR NO PROGRAMA GERADOR DE OBRAS DE ARTE COM ASTERISCO\n2 - JOGAR BATALHA NAVAL\n3 - SAIR\n");
    scanf("%d", &a);
    switch (a){
    case 1:
        menuprogramadearte(Quadro);
        break;
    case 2:
        printf("n tem ainda :(\n");
        break;
    case 3:
        break;
    default:
        printf("Atencao! Essa opcao nao esta disponivel! Tente novamente.\n\n");
        decisao();
        break;
    }
}

void menuprogramadearte(char** Quadro){
    int escolha;

    printf("================================================================================\n");
    printf("PROGRAMA GERADOR DE OBRAS DE ARTE COM ASTERISCO\n");
    printf("================================================================================\n");
    printf("Quantas figuras gostaria de utilizar? (1 - 100)\n");
    int figuras; scanf("%d", &figuras);
    printf("Qual tipo de figura gostaria de usar na obra de arte?\n1 - Asterisco Simples\n2 - Simbolo de soma\n3 - Letra X\n4 - Todas as opcoes\n5 - Voltar ao menu\n");
    scanf("%d", &escolha);
    switch (escolha){
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    case 5:
        decisao();
        break;
    default:
        printf("Atenção! Essa opcao nao esta disponivel! Tente novamente.\n");
        menuprogramadearte(Quadro);
        break;
    }
}

char** criaquadro(){
    char** quadro = malloc(numlinhas * sizeof(char*));
    for (int i = 0; i < numlinhas; i++)
        quadro[i] = malloc(numcolunas * sizeof(char));

    return quadro;
}