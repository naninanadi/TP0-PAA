#include "impressao.h"

void ImprimeQuadro(Espaco** Quadro){
    for(int i = 0; i < 22; i++){
        for(int j = 0; j < 82; j++){
            if(i == 0 || i == 21){
                printf("-");
            } else if(j == 0 || j == 81){
                printf("|");
            } else {
                printf("%c", Quadro[i-1][j-1].Local);
            }
        }
        printf("\n");
    }
}