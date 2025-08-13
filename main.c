#include <stdio.h>
#include "menu.h"
#define numlinhas 18
#define numcolunas 78

int main(){

    srand(time(NULL));

    decisao();

    // char** teste = malloc(numlinhas * sizeof(char*));
    // for (int i = 0; i < numlinhas; i++)
    //     teste[i] = malloc(numcolunas * sizeof(char));

    // Coordenadas cord;

    // LimpaQuadro(teste,numlinhas,numcolunas);

    // for(int i = 0; i < 10; i++){
    //     cord = GeraCoordenadaSoma(teste);
    //     EscreveSoma(teste, cord);
    // }


    // ImprimeQuadro(teste);
    return 0;
}