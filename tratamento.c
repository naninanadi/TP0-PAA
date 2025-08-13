#include "tratamento.h"

int DeterminaOcupadoAsterisco(char Coordenada){
    if(Coordenada == ' '){
        return 0;
    } else {
        return 1;
    }
}

int DeterminaOcupadoX(char** Quadro, Coordenadas Cord){
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

int DeterminaOcupadoSoma(char** Quadro, Coordenadas Cord){
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

Coordenadas GeraCoordenadaAseterisco(char** Quadro){
    Coordenadas Cord;
    int i = (rand() % 19);
    int j = (rand() % 79);
    if(DeterminaOcupadoAsterisco(Quadro[i][j])){
        GeraCoordenadaAseterisco(Quadro);
    }
    Cord.Linha = i;
    Cord.Coluna = j;
    

    return Cord;
}

Coordenadas GeraCoordenadaX(char** Quadro){
    Coordenadas Cord;

    int i = (rand() % 17 + 1);
    int j = (rand() % 77 + 1);

    Cord.Linha = i;
    Cord.Coluna = j;

    if(DeterminaOcupadoX(Quadro, Cord)){
        GeraCoordenadaX(Quadro);
    }

    return Cord;
}

Coordenadas GeraCoordenadaSoma(char** Quadro){
    Coordenadas Cord;

    int i = (rand() % 17 + 1);
    int j = (rand() % 77 + 1);

    Cord.Linha = i;
    Cord.Coluna = j;    

    if(DeterminaOcupadoSoma(Quadro, Cord)){
        GeraCoordenadaSoma(Quadro);
    }
    

    return Cord;
}