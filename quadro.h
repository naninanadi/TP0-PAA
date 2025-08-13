#include <time.h>
#include <stdlib.h>


typedef struct Coordenadas{
    int Linha;
    int Coluna;
} Coordenadas;

void LimpaQuadro(char** Quadro, int linhas, int colunas);


void EscreveAsterisco(char** Quadro, Coordenadas Cord);
void EscreveX(char** Quadro, Coordenadas Cord);
void EscreveSoma(char** Quadro, Coordenadas Cord);