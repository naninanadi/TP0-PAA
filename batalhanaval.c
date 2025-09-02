#include "batalhanaval.h"

int VerificaAcerto(Barcos Mapa[18][78], Coordenadas Cord){
    if(Mapa[Cord.Linha][Cord.Coluna].PosicaoIndividual != ' '){
        return 0;
    }
    return 0;
}

void LimpaMapa(Barcos Mapa[18][78], int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            Mapa[i][j].PosicaoIndividual = ' ';
        }
    }
}

int DeterminaOcupadoBarquinho1(Barcos Mapa[18][78], Coordenadas Cord){
    if(Mapa[Cord.Linha][Cord.Coluna].PosicaoIndividual != ' '){
        return 0;
    }
    if(Mapa[Cord.Linha][Cord.Coluna+1].PosicaoIndividual != ' '){
        return 0;
    }
    if(Mapa[Cord.Linha][Cord.Coluna-1].PosicaoIndividual != ' '){
        return 0;
    }
    
    return 1;
}

int DeterminaOcupadoBarquinho2(Barcos Mapa[18][78], Coordenadas Cord){
    if(Mapa[Cord.Linha][Cord.Coluna].PosicaoIndividual != ' '){
        return 0;
    }
    if(Mapa[Cord.Linha][Cord.Coluna+1].PosicaoIndividual != ' '){
        return 0;
    }
    if(Mapa[Cord.Linha][Cord.Coluna-1].PosicaoIndividual != ' '){
        return 0;
    }
    if(Mapa[Cord.Linha][Cord.Coluna-2].PosicaoIndividual != ' '){
        return 0;
    }

    return 1;
}

int DeterminaOcupadoBarquinho3(Barcos Mapa[18][78], Coordenadas Cord){
    if(Mapa[Cord.Linha][Cord.Coluna].PosicaoIndividual != ' '){
        return 0;
    }
    if(Mapa[Cord.Linha][Cord.Coluna+1].PosicaoIndividual != ' '){
        return 0;
    }
    if(Mapa[Cord.Linha][Cord.Coluna+2].PosicaoIndividual != ' '){
        return 0;
    }
    if(Mapa[Cord.Linha][Cord.Coluna-1].PosicaoIndividual != ' '){
        return 0;
    }
    if(Mapa[Cord.Linha][Cord.Coluna-2].PosicaoIndividual != ' '){
        return 0;
    }

    return 1;
}

Coordenadas GeraCoordenadasBarquinho1(Barcos Mapa[18][78]){
    Coordenadas Cord;

    do {
        Cord.Linha = rand() % 18;
        Cord.Coluna = (rand() % 76) + 1;
    } while(!DeterminaOcupadoBarquinho1(Mapa, Cord));
    
    return Cord;
}

Coordenadas GeraCoordenadasBarquinho2(Barcos Mapa[18][78]){
    Coordenadas Cord;

    do {
        Cord.Linha = rand() % 18;
        Cord.Coluna = (rand() % 75) + 2;
    } while(!DeterminaOcupadoBarquinho2(Mapa, Cord));

    return Cord;
}

Coordenadas GeraCoordenadasBarquinho3(Barcos Mapa[18][78]){
    Coordenadas Cord;

    do {
        Cord.Linha = rand() % 18;
        Cord.Coluna = (rand() % 74) + 2;
    } while(!DeterminaOcupadoBarquinho3(Mapa, Cord));

    return Cord;
}

void EscreveBarquinho1(Barcos Mapa[18][78], Coordenadas Cord){
    Mapa[Cord.Linha][Cord.Coluna].PosicaoIndividual = '_';
    Mapa[Cord.Linha][Cord.Coluna+1].PosicaoIndividual = '/';
    Mapa[Cord.Linha][Cord.Coluna-1].PosicaoIndividual = '\\'; 
}

void EscreveBarquinho2(Barcos Mapa[18][78], Coordenadas Cord){
    Mapa[Cord.Linha][Cord.Coluna].PosicaoIndividual = '_';
    Mapa[Cord.Linha][Cord.Coluna+1].PosicaoIndividual = '/';
    Mapa[Cord.Linha][Cord.Coluna-1].PosicaoIndividual = '_';
    Mapa[Cord.Linha][Cord.Coluna-2].PosicaoIndividual = '\\';
}

void EscreveBarquinho3(Barcos Mapa[18][78], Coordenadas Cord){
    Mapa[Cord.Linha][Cord.Coluna].PosicaoIndividual = '_';
    Mapa[Cord.Linha][Cord.Coluna+2].PosicaoIndividual = '/';
    Mapa[Cord.Linha][Cord.Coluna-2].PosicaoIndividual = '\\';
    Mapa[Cord.Linha][Cord.Coluna+1].PosicaoIndividual = '_';
    Mapa[Cord.Linha][Cord.Coluna-1].PosicaoIndividual = '_';
}

void PosicionaBarquinho1(Barcos Mapa[18][78], int Quantidade){
    Coordenadas Cord;
    for(int i = 0; i < Quantidade; i++){
        Cord = GeraCoordenadasBarquinho1(Mapa);
        EscreveBarquinho1(Mapa, Cord);
    }
}

void PosicionaBarquinho2(Barcos Mapa[18][78], int Quantidade){
    Coordenadas Cord;
    for(int i = 0; i < Quantidade; i++){
        Cord = GeraCoordenadasBarquinho2(Mapa);
        EscreveBarquinho2(Mapa, Cord);
    }
}

void PosicionaBarquinho3(Barcos Mapa[18][78], int Quantidade){
    Coordenadas Cord;
    for(int i = 0; i < Quantidade; i++){
        Cord = GeraCoordenadasBarquinho3(Mapa);
        EscreveBarquinho3(Mapa, Cord);
    }
}

void ImprimeMapa(Barcos Mapa[18][78]){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 80; j++){
            if(i == 0 || i == 19){
                printf("-");
            } else if(j == 0 || j == 79){
                printf("|");
            } else {
                printf("%c", Mapa[i-1][j-1].PosicaoIndividual);
            }
        }
        printf("\n");
    }
}


void Testanto(){
    Barcos Mapa[18][78];
    LimpaMapa(Mapa, 18, 78);
    PosicionaBarquinho1(Mapa, 5);
    PosicionaBarquinho2(Mapa, 7);
    PosicionaBarquinho3(Mapa, 4);
    ImprimeMapa(Mapa);
}