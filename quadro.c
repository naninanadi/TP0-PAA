#include "quadro.h"

void LimpaQuadro(char Quadro[18][78], int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            Quadro[i][j] = ' ';
        }
    }
}

void EscreveAsterisco(char Quadro[18][78], Coordenadas Cord){
    Quadro[Cord.Linha][Cord.Coluna] = '*';
}

void EscreveX(char Quadro[18][78], Coordenadas Cord){
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            if(i == j || j == i *(-1)){
                Quadro[Cord.Linha + i][Cord.Coluna + j] = '*';
            }
        }
    }
}

void EscreveSoma(char Quadro[18][78], Coordenadas Cord){
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            if(j == 0 || i == 0){
                Quadro[Cord.Linha + i][Cord.Coluna + j] = '*';
            }
        }
    }
}

void ImprimeQuadro(char Quadro[18][78]){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 80; j++){
            if(i == 0 || i == 19){
                printf("-");
            } else if(j == 0 || j == 79){
                printf("|");
            } else {
                printf("%c", Quadro[i-1][j-1]);
            }
        }
        printf("\n");
    }
}