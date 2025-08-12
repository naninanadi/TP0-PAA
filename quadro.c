#include "quadro.h"

int DeterminaOcupado(Espaco Coordenada){
    if(Coordenada.Local == " "){
        return 0;
    } else {
        return 1;
    }
}

void Escreve(Espaco* Coordenada){
    Coordenada->Local = '*';
}

Coordenadas GeraCoordenada(Espaco** Quadro){
    Coordenadas Cord;
    int i = (rand() % 21);
    int j = (rand() % 81);
    if(!DeterminaOcupado(Quadro[i][j])){
        GeraCoordenada(Quadro);
    }
    Cord.Linha = i;
    Cord.Coluna = j;

    return Cord;
}