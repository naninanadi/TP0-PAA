#include <stdio.h>
#include "impressao.h"

typedef struct Barcos{
    enum TipoBarco{
        Tipo1,
        Tipo2,
        Tipo3
    } tipo;
    char PosicaoIndividual;
} Barcos;

Barcos MapaAuxiliar[18][78];

int VerificaAcerto(Barcos Mapa[18][78], Coordenadas Cord);

void LimpaMapa(Barcos Mapa[18][78], int linhas, int colunas);

int DeterminaOcupadoBarquinho1(Barcos Mapa[18][78], Coordenadas Cord);
int DeterminaOcupadoBarquinho2(Barcos Mapa[18][78], Coordenadas Cord);
int DeterminaOcupadoBarquinho3(Barcos Mapa[18][78], Coordenadas Cord);

Coordenadas GeraCoordenadasBarquinho1(Barcos Mapa[18][78]);
Coordenadas GeraCoordenadasBarquinho2(Barcos Mapa[18][78]);
Coordenadas GeraCoordenadasBarquinho3(Barcos Mapa[18][78]);

void EscreveBarquinho1(Barcos Mapa[18][78], Coordenadas Cord);
void EscreveBarquinho2(Barcos Mapa[18][78], Coordenadas Cord);
void EscreveBarquinho3(Barcos Mapa[18][78], Coordenadas Cord);

void PosicionaBarquinho1(Barcos Mapa[18][78], int Quantidade);
void PosicionaBarquinho2(Barcos Mapa[18][78], int Quantidade);
void PosicionaBarquinho3(Barcos Mapa[18][78], int Quantidade);