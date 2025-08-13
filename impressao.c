#include "impressao.h"

void ImprimeQuadro(char** Quadro){
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

void ImprimeMatriz(char** Matriz, int linhas, int colunas){
     for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%c", Matriz[i][j]);   
        }
        printf("\n");
    }
}