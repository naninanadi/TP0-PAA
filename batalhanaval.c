#include "batalhanaval.h"

int VerificaAcerto(Barcos Mapa[18][78], Coordenadas Cord){
    if(Mapa[Cord.Linha][Cord.Coluna].PosicaoIndividual != ' '){
        return 1;
    }
    return 0;
}

void LimpaMapa(Barcos Mapa[18][78]){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            Mapa[i][j].PosicaoIndividual = ' ';
            Mapa[i][j].Id = -1;
        }
    }
}

int DeterminaOcupadoBarquinho1(Barcos Mapa[18][78], Coordenadas Cord){
    for(int i = -1; i <= 0; i++){
        for(int j = -1; j < 1; j++){
            if(Mapa[Cord.Linha+i][Cord.Coluna+j].PosicaoIndividual != ' '){
                return 0;
            }
        }
    }

    return 1;
}

int DeterminaOcupadoBarquinho2(Barcos Mapa[18][78], Coordenadas Cord){
    for(int i = -1; i <= 0; i++){
        for(int j = -2; j <= 2; j++){
            if(Mapa[Cord.Linha+i][Cord.Coluna+j].PosicaoIndividual != ' '){
                return 0;
            }
        }
    }

    return 1;
}

int DeterminaOcupadoBarquinho3(Barcos Mapa[18][78], Coordenadas Cord){
    for(int i = -1; i <= 0; i++){
        for(int j = -3; j <= 3; j++){
            if(Mapa[Cord.Linha+i][Cord.Coluna+j].PosicaoIndividual != ' '){
                return 0;
            }
        }
    }

    return 1;
}

Coordenadas GeraCoordenadasBarquinho1(Barcos Mapa[18][78]){
    Coordenadas Cord;

    do {
        Cord.Linha = rand() % 17;
        Cord.Coluna = (rand() % 76) + 1;
    } while(!DeterminaOcupadoBarquinho1(Mapa, Cord));
    
    return Cord;
}

Coordenadas GeraCoordenadasBarquinho2(Barcos Mapa[18][78]){
    Coordenadas Cord;

    do {
        Cord.Linha = rand() % 17;
        Cord.Coluna = (rand() % 74) + 2;
    } while(!DeterminaOcupadoBarquinho2(Mapa, Cord));

    return Cord;
}

Coordenadas GeraCoordenadasBarquinho3(Barcos Mapa[18][78]){
    Coordenadas Cord;

    do {
        Cord.Linha = rand() % 17;
        Cord.Coluna = (rand() % 72) + 3;
    } while(!DeterminaOcupadoBarquinho3(Mapa, Cord));

    return Cord;
}

void EscreveBarquinho1(Barcos Mapa[18][78], Coordenadas Cord, int Id){
    Mapa[Cord.Linha][Cord.Coluna].PosicaoIndividual = '_';
    Mapa[Cord.Linha][Cord.Coluna+1].PosicaoIndividual = '/';
    Mapa[Cord.Linha][Cord.Coluna-1].PosicaoIndividual = '\\';
    Mapa[Cord.Linha-1][Cord.Coluna].PosicaoIndividual = '|';
    Mapa[Cord.Linha-1][Cord.Coluna+1].PosicaoIndividual = '>';
    Mapa[Cord.Linha-1][Cord.Coluna-1].PosicaoIndividual = '_';
    AtribuiId1(Mapa, Cord, Id);
}

void EscreveBarquinho2(Barcos Mapa[18][78], Coordenadas Cord, int Id){
    Mapa[Cord.Linha][Cord.Coluna].PosicaoIndividual = '_';
    Mapa[Cord.Linha][Cord.Coluna+1].PosicaoIndividual = '_';
    Mapa[Cord.Linha][Cord.Coluna-1].PosicaoIndividual = '_';
    Mapa[Cord.Linha][Cord.Coluna+2].PosicaoIndividual = '/';
    Mapa[Cord.Linha][Cord.Coluna-2].PosicaoIndividual = '\\';
    Mapa[Cord.Linha-1][Cord.Coluna].PosicaoIndividual = '|';
    Mapa[Cord.Linha-1][Cord.Coluna+1].PosicaoIndividual = '>';
    Mapa[Cord.Linha-1][Cord.Coluna+2].PosicaoIndividual = '_';
    Mapa[Cord.Linha-1][Cord.Coluna-1].PosicaoIndividual = '_';
    Mapa[Cord.Linha-1][Cord.Coluna-2].PosicaoIndividual = '_';
    AtribuiId2(Mapa, Cord, Id);
}

void EscreveBarquinho3(Barcos Mapa[18][78], Coordenadas Cord, int Id){
    Mapa[Cord.Linha][Cord.Coluna].PosicaoIndividual = '_';
    Mapa[Cord.Linha][Cord.Coluna+1].PosicaoIndividual = '_';
    Mapa[Cord.Linha][Cord.Coluna-1].PosicaoIndividual = '_';
    Mapa[Cord.Linha][Cord.Coluna+2].PosicaoIndividual = '_';
    Mapa[Cord.Linha][Cord.Coluna-2].PosicaoIndividual = '_';
    Mapa[Cord.Linha][Cord.Coluna+3].PosicaoIndividual = '/';
    Mapa[Cord.Linha][Cord.Coluna-3].PosicaoIndividual = '\\';
    Mapa[Cord.Linha-1][Cord.Coluna].PosicaoIndividual = '|';
    Mapa[Cord.Linha-1][Cord.Coluna+1].PosicaoIndividual = '>';
    Mapa[Cord.Linha-1][Cord.Coluna+2].PosicaoIndividual = '_';
    Mapa[Cord.Linha-1][Cord.Coluna+3].PosicaoIndividual = '_';
    Mapa[Cord.Linha-1][Cord.Coluna-1].PosicaoIndividual = '_';
    Mapa[Cord.Linha-1][Cord.Coluna-2].PosicaoIndividual = '_';
    Mapa[Cord.Linha-1][Cord.Coluna-3].PosicaoIndividual = '_';
    AtribuiId3(Mapa, Cord, Id);
}

void PosicionaBarquinho1(Barcos Mapa[18][78], int Quantidade){
    Coordenadas Cord;
    for(int i = 0; i < Quantidade; i++){
        Cord = GeraCoordenadasBarquinho1(Mapa);
        EscreveBarquinho1(Mapa, Cord, i);
    }
}

void PosicionaBarquinho2(Barcos Mapa[18][78], int Quantidade, int InicioId){
    Coordenadas Cord;
    for(int i = 0; i < Quantidade; i++){
        Cord = GeraCoordenadasBarquinho2(Mapa);
        EscreveBarquinho2(Mapa, Cord, InicioId + i);
    }
}

void PosicionaBarquinho3(Barcos Mapa[18][78], int Quantidade, int InicioId){
    Coordenadas Cord;
    for(int i = 0; i < Quantidade; i++){
        Cord = GeraCoordenadasBarquinho3(Mapa);
        EscreveBarquinho3(Mapa, Cord, InicioId + i);
    }
}

void AtribuiId1(Barcos Mapa[18][78], Coordenadas Cord, int Id){
    for(int i = -1; i <= 0; i++){
        for(int j = -1; j < 1; j++){
            Mapa[Cord.Linha+i][Cord.Coluna+j].Id = Id;
        }
    }
}

void AtribuiId2(Barcos Mapa[18][78], Coordenadas Cord, int Id){
    for(int i = -1; i <= 0; i++){
        for(int j = -2; j <= 2; j++){
            Mapa[Cord.Linha+i][Cord.Coluna+j].Id = Id;
        }
    }
}

void AtribuiId3(Barcos Mapa[18][78], Coordenadas Cord, int Id){
    for(int i = -1; i <= 0; i++){
        for(int j = -3; j <= 3; j++){
            Mapa[Cord.Linha+i][Cord.Coluna+j].Id = Id;
        }
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

void GeraQuantidade(int QuantidadeTotal, int *QuantB1, int *QuantB2, int *QuantB3){
    // printf("entrar entra\n");
    *QuantB1 = 1 + rand() % QuantidadeTotal;
    *QuantB2 = 1 + rand() % (QuantidadeTotal - *QuantB1);
    *QuantB3 = 1 + rand() % (QuantidadeTotal - *QuantB1 - *QuantB2);

}

int Ataca(Barcos Mapa[18][78], Coordenadas Cord){
    if(VerificaAcerto(Mapa, Cord)){
        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++){
                if(Mapa[i][j].Id == Mapa[Cord.Linha][Cord.Coluna].Id){
                    MapaAuxiliar[i][j].PosicaoIndividual = Mapa[i][j].PosicaoIndividual;
                }
            }
        }
        MapaAuxiliar[Cord.Linha][Cord.Coluna].PosicaoIndividual = 'X';
        printf("================================================================================\n");
        printf("VOCE ACERTOU UM BARCO!\n");
        ImprimeMapa(MapaAuxiliar);
        return 1;
    } else {
        printf("================================================================================\n");
        printf("ERROU!\n");
        MapaAuxiliar[Cord.Linha][Cord.Coluna].PosicaoIndividual = '^';
        ImprimeMapa(MapaAuxiliar);
        return 0;
    }
}

void Testanto(){
    Barcos Mapa[18][78];
    LimpaMapa(Mapa);
    LimpaMapa(MapaAuxiliar);

    int QuantB1, QuantB2, QuantB3;
    GeraQuantidade(20, &QuantB1, &QuantB2, &QuantB3);

    PosicionaBarquinho1(Mapa, QuantB1);
    PosicionaBarquinho2(Mapa, QuantB2, QuantB1);
    PosicionaBarquinho3(Mapa, QuantB3, QuantB1 + QuantB2);

    ImprimeMapa(Mapa);

    while(1){
        int linha, coluna;
        printf("Digite a linha que deseja atacar (0-17): ");
        scanf("%d", &linha);
        printf("Digite a coluna que deseja atacar (0-77): ");
        scanf("%d", &coluna);

        Coordenadas Cord;
        Cord.Linha = linha;
        Cord.Coluna = coluna;

        if(Ataca(Mapa, Cord)){
            break;
        }
        
    }

    printf("================================================================================\n");
    printf("JOGO ENCERRADO!\n");
    printf("A POSICAO DOS BARCOS ERA:\n");
    ImprimeMapa(Mapa);
}