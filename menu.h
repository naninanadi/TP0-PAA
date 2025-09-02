#include <stdio.h>
#include "impressao.h"
#define numlinhas 18
#define numcolunas 78   

void decisao();

void menuprogramadearte(char Quadro[18][78]);

char** criaquadro();

void escolha1arte(char Quadro[18][78], int Figuras, int Quatro);
void escolha2arte(char Quadro[18][78], int Figuras, int Quatro);
void escolha3arte(char Quadro[18][78], int Figuras, int Quatro);
void escolha4arte(char Quadro[18][78], int quanta, int quantsoma, int quantx);