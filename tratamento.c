#include "tratamento.h"
#include <stdio.h>

int DeterminaOcupadoAsterisco(char Coordenada){
    if(Coordenada == ' '){
        return 0;
    } else {
        return 1;
    }
}

int DeterminaOcupadoX(char Quadro[18][78], Coordenadas Cord){
    int Verifica = 0;
    for(int i = -1; i < 2; i++){
        if(Verifica){
            break;
        }
        for(int j = -1; j < 2; j++){
            if(i == j || j == i *(-1)){
                if(Quadro[Cord.Linha+i][Cord.Coluna+j] == '*'){
                    Verifica = 1;
                }
            }
        }
    }

    return Verifica;
}

int DeterminaOcupadoSoma(char Quadro[18][78], Coordenadas Cord){
    int Verifica = 0;
    for(int i = -1; i < 2; i++){
        if(Verifica){
            break;
        }
        for(int j = -1; j < 2; j++){
            if(j == 0 || i == 0){
                if(Quadro[Cord.Linha+i][Cord.Coluna+j] == '*'){
                    Verifica = 1;
                }
            }
        }
    }

    return Verifica;
}

Coordenadas GeraCoordenadaAseterisco(char Quadro[18][78]){
    Coordenadas Cord;

    int i = (rand() % 19);
    int j = (rand() % 79);

    while(DeterminaOcupadoAsterisco(Quadro[i][j])){
        i = (rand() % 19);
        j = (rand() % 79);

        // printf("i=%d j=%d\n", i, j);
    }

    Cord.Linha = i;
    Cord.Coluna = j;

    return Cord;
}

Coordenadas GeraCoordenadaX(char Quadro[18][78]){
    Coordenadas Cord;

    int i = (rand() % 17 + 1);
    int j = (rand() % 77 + 1);

    Cord.Linha = i;
    Cord.Coluna = j;

    while(DeterminaOcupadoX(Quadro, Cord)){
        i = (rand() % 17 + 1);
        j = (rand() % 77 + 1);

        Cord.Linha = i;
        Cord.Coluna = j;

        // printf("ta infinito X\n");
    }

    return Cord;
}

Coordenadas GeraCoordenadaSoma(char Quadro[18][78]){
    Coordenadas Cord;

    int i = (rand() % 17 + 1);
    int j = (rand() % 77 + 1);

    Cord.Linha = i;
    Cord.Coluna = j;    

    while(DeterminaOcupadoSoma(Quadro, Cord)){
        i = (rand() % 17 + 1);
        j = (rand() % 77 + 1);

        Cord.Linha = i;
        Cord.Coluna = j; 

        // printf("ta infinito +\n");
    }
    

    return Cord;
}