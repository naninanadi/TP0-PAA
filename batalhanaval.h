#include <stdio.h>
#include "impressao.h"
#define linhas  18
#define colunas 78

typedef enum  TipoBarco{
        Tipo1,
        Tipo2,
        Tipo3
    } TipoBarco;

typedef struct Barcos{
    TipoBarco Tipo;
    char PosicaoIndividual;
    int Id;
} Barcos;

Barcos MapaAuxiliar[18][78];

int VerificaAcerto(Barcos Mapa[18][78], Coordenadas Cord);

void LimpaMapa(Barcos Mapa[18][78]);

int DeterminaOcupadoBarquinho1(Barcos Mapa[18][78], Coordenadas Cord);
int DeterminaOcupadoBarquinho2(Barcos Mapa[18][78], Coordenadas Cord);
int DeterminaOcupadoBarquinho3(Barcos Mapa[18][78], Coordenadas Cord);

Coordenadas GeraCoordenadasBarquinho1(Barcos Mapa[18][78]);
Coordenadas GeraCoordenadasBarquinho2(Barcos Mapa[18][78]);
Coordenadas GeraCoordenadasBarquinho3(Barcos Mapa[18][78]);

void EscreveBarquinho1(Barcos Mapa[18][78], Coordenadas Cord, int Id);
void EscreveBarquinho2(Barcos Mapa[18][78], Coordenadas Cord, int Id);
void EscreveBarquinho3(Barcos Mapa[18][78], Coordenadas Cord, int Id);

void PosicionaBarquinho1(Barcos Mapa[18][78], int Quantidade);
void PosicionaBarquinho2(Barcos Mapa[18][78], int Quantidade, int InicioId);
void PosicionaBarquinho3(Barcos Mapa[18][78], int Quantidade, int InicioId);


void AtribuiId1(Barcos Mapa[18][78], Coordenadas Cord, int Id);
void AtribuiId2(Barcos Mapa[18][78], Coordenadas Cord, int Id);
void AtribuiId3(Barcos Mapa[18][78], Coordenadas Cord, int Id);


void Testanto();