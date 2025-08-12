#include <time.h>
#include <stdlib.h>

typedef struct Espaco{
    char Local;
    int Ocupado;
} Espaco;

typedef struct Coordenadas{
    int Linha;
    int Coluna;
} Coordenadas;

int DeterminaOcupado(Espaco Coordenada);

void Escreve(Espaco* Coordenada);

int GeraCoordenada(Espaco** Quadro);