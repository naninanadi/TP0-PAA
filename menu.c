#include "menu.h"

void decisao(){

    char** Quadro = criaquadro();
    LimpaQuadro(Quadro, numlinhas, numcolunas);

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

    int Quatro; int quanta, quantsoma, quantx;
    if(escolha != 4){
        Quatro = 0;
    }

    switch (escolha){
        case 1:
            escolha1arte(Quadro, figuras, Quatro);
            break;
        case 2:
            escolha2arte(Quadro, figuras, Quatro);
            break;
        case 3:
            escolha3arte(Quadro, figuras, Quatro);
            break;
        case 4:
            quanta = 1 + rand() % figuras;
            printf("figuras=%d quanta=%d\n", figuras, quanta);
            quantsoma = 1 + rand() % (figuras - quanta + 1);
            quantx = 1 + rand() % (figuras - quanta - quantsoma + 1);

            escolha4arte(Quadro, quanta, quantsoma, quantx);
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

void escolha1arte(char** Quadro, int Figuras, int Quatro){
    Coordenadas Cord;
    for(int i = 0; i < Figuras; i++){
        Cord = GeraCoordenadaAseterisco(Quadro);
        EscreveAsterisco(Quadro, Cord);
    }

    

    if(!Quatro){

        ImprimeQuadro(Quadro);

        int aux; 
        printf("O que gostaria de fazer a seguir?\n1 - Recriar a obra com as mesmas caracteristicas\n2 - Voltar ao programa\n3 - Voltar ao menu\nQualquer numero para sair\n");
        scanf("%d", &aux); 

        switch (aux){
        case 1:
            LimpaQuadro(Quadro, numlinhas, numcolunas);
            escolha1arte(Quadro, Figuras, Quatro);
            break;
        case 2:
            LimpaQuadro(Quadro, numlinhas, numcolunas);
            menuprogramadearte(Quadro);
        case 3:
            decisao();
        default:
            break;
        }
    }
}

void escolha2arte(char** Quadro, int Figuras, int Quatro){
    Coordenadas Cord;
    for(int i = 0; i < Figuras; i++){
        Cord = GeraCoordenadaSoma(Quadro);
        EscreveSoma(Quadro, Cord);
    }

    

    if(!Quatro){

        ImprimeQuadro(Quadro);

        int aux; 
        printf("O que gostaria de fazer a seguir?\n1 - Recriar a obra com as mesmas caracteristicas\n2 - Voltar ao programa\n3 - Voltar ao menu\nQualquer numero para sair\n");
        scanf("%d", &aux); 

        switch (aux){
        case 1:
            LimpaQuadro(Quadro, numlinhas, numcolunas);
            escolha2arte(Quadro, Figuras, Quatro);
            break;
        case 2:
            LimpaQuadro(Quadro, numlinhas, numcolunas);
            menuprogramadearte(Quadro);
        case 3:
            decisao();
        default:
            break;
        }
    }
}

void escolha3arte(char** Quadro, int Figuras, int Quatro){
    Coordenadas Cord;
    for(int i = 0; i < Figuras; i++){
        Cord = GeraCoordenadaX(Quadro);
        EscreveX(Quadro, Cord);
    }

    

    if(!Quatro){
        
        ImprimeQuadro(Quadro);

        int aux; 
        printf("O que gostaria de fazer a seguir?\n1 - Recriar a obra com as mesmas caracteristicas\n2 - Voltar ao programa\n3 - Voltar ao menu\nQualquer numero para sair\n");
        scanf("%d", &aux); 

        switch (aux){
        case 1:
            LimpaQuadro(Quadro, numlinhas, numcolunas);
            escolha3arte(Quadro, Figuras, Quatro);
            break;
        case 2:
            LimpaQuadro(Quadro, numlinhas, numcolunas);
            menuprogramadearte(Quadro);
        case 3:
            decisao();
        default:
            break;
        }
    }
}

void escolha4arte(char** Quadro, int quanta, int quantsoma, int quantx){

    // printf("oi amigos\n");
    escolha1arte(Quadro, quanta, 1);
    // printf("a\n");
    escolha2arte(Quadro, quantsoma, 1);
    // printf("aaa\n");
    escolha3arte(Quadro, quantx, 1);
    // printf("vem aqui\n");


    ImprimeQuadro(Quadro);

    int aux; 
    printf("O que gostaria de fazer a seguir?\n1 - Recriar a obra com as mesmas caracteristicas\n2 - Voltar ao programa\n3 - Voltar ao menu\nQualquer numero para sair\n");
    scanf("%d", &aux); 

    switch (aux){
    case 1:
        LimpaQuadro(Quadro, numlinhas, numcolunas);
        escolha4arte(Quadro, quanta, quantsoma, quantx);
        break;
    case 2:
        LimpaQuadro(Quadro, numlinhas, numcolunas);
        menuprogramadearte(Quadro);
    case 3:
        decisao();
    default:
        break;
    }

}