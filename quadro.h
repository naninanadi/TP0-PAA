#include <time.h>
#include <stdlib.h>


typedef struct Coordenadas{
    int Linha;
    int Coluna;
} Coordenadas;

void LimpaQuadro(char Quadro[18][78], int linhas, int colunas);


void EscreveAsterisco(char Quadro[18][78], Coordenadas Cord);
void EscreveX(char Quadro[18][78], Coordenadas Cord);
void EscreveSoma(char Quadro[18][78], Coordenadas Cord);