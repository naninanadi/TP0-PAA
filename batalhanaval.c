#include "batalhanaval.h"

Barcos MapaAuxiliar[18][78];

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
        Cord.Linha = rand() % 16 + 1;
        Cord.Coluna = (rand() % 76) + 1;
    } while(!DeterminaOcupadoBarquinho1(Mapa, Cord));

    return Cord;
}

Coordenadas GeraCoordenadasBarquinho2(Barcos Mapa[18][78]){
    Coordenadas Cord;

    do {
        Cord.Linha = rand() % 16 + 1;
        Cord.Coluna = (rand() % 74) + 2;
    } while(!DeterminaOcupadoBarquinho2(Mapa, Cord) );

    return Cord;
}

Coordenadas GeraCoordenadasBarquinho3(Barcos Mapa[18][78]){
    Coordenadas Cord;

    do {
        Cord.Linha = rand() % 16 + 1;
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
    if(QuantidadeTotal < 3) QuantidadeTotal = 3;  
    *QuantB1 = 1 + rand() % (QuantidadeTotal - 2);          
    *QuantB2 = 1 + rand() % (QuantidadeTotal - *QuantB1 - 1);
    *QuantB3 = QuantidadeTotal - *QuantB1 - *QuantB2;      
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

void LimpaMapaInicio(Barcos Mapa[6][78]){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 78; j++){
            Mapa[i][j].PosicaoIndividual = ' ';
        }
    }
}

void EscreveBarquinhoInicio(Barcos Mapa[6][78], Coordenadas Cord){
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
}

void ImprimeMapaInicio(Barcos Mapa[6][78]){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 80; j++){
            if(j == 0 || j == 79){
                printf("|");
            } else {
                printf("%c", Mapa[i][j-1].PosicaoIndividual);
            }
        }
        printf("\n");
    }
}

void IniciaoJogo(){

    srand(time(NULL));

    Barcos MatrizdeInicio[6][78]; LimpaMapaInicio(MatrizdeInicio);
    Coordenadas BAux;
    for(int i = 3; i <= 77; i+= 35){
        BAux.Linha = 3;
        BAux.Coluna = i;
        EscreveBarquinhoInicio(MatrizdeInicio, BAux);
    }
    
    printf("================================================================================\n");
    printf("|                   BEM VINDO AO JOGO DA BATALHA NAVAL!                        |\n");
    printf("================================================================================\n");
    ImprimeMapaInicio(MatrizdeInicio);
    printf("================================================================================\n");
    printf("As regras sao simples:\n");
    printf("1 - Voce ira escolher a quantidade de barcos que deseja jogar (3 - 100);\n");
    printf("2 - Voce ira escolher as coordenadas (linha e coluna) para atacar\n");
    printf("3 - Se voce acertar um barco, ele sera revelado na tela e jogo acaba\n");
    printf("4 - Voce pode continuar errando quantas vezes quiser\n");
    printf("5 - Se quiser sair, digite -1 para linha ou -1 para coluna\n");
    printf("Bom jogo!\n");
    printf("================================================================================\n");
}

int Jogo(){

    IniciaoJogo();
    Barcos Mapa[18][78];
    LimpaMapa(Mapa);
    LimpaMapa(MapaAuxiliar);

    int QuantB1, QuantB2, QuantB3, QuantB;
    QuantB = 100;

    
    printf("Com quantos barcos gostaria de jogar? ");
    scanf("%d", &QuantB);

    if(QuantB <= 0){
        printf("Voltando ao menu...\n");
        return 1;
    } else if (QuantB < 3){
        QuantB = 3;
        printf("Numero de barcos muito baixo, iniciando o jogo com 3 barcos\n");
    } else if (QuantB > 100){
        QuantB = 100;
        printf("Numero de barcos muito alto, iniciando o jogo com 100 barcos\n");
    }

    GeraQuantidade(QuantB, &QuantB1, &QuantB2, &QuantB3);

    PosicionaBarquinho1(Mapa, QuantB1);
    PosicionaBarquinho2(Mapa, QuantB2, QuantB1);
    PosicionaBarquinho3(Mapa, QuantB3, QuantB1 + QuantB2);

    while(1){
        int linha, coluna;
        printf("DIGITE A LINHA A SER ATACADA (0-17): ");
        scanf("%d", &linha);
        if(linha == -1){
            printf("Voltando ao menu...\n");
            return 1;
        } else if (linha < 0 || linha > 17) {
            printf("Linha invalida! Tente novamente.\n");
            continue;
        }

        printf("DIGITE A COLUNA A SER ATACADA (0-77): ");
        scanf("%d", &coluna);
        if(coluna == -1){
            printf("Saindo do jogo...\n");
            return 1;
        } else if (coluna < 0 || coluna > 77) {
            printf("Coluna invalida! Tente novamente.\n");
            continue;
        }
        
        Coordenadas Cord;
        Cord.Linha = linha;
        Cord.Coluna = coluna;

        if(Ataca(Mapa, Cord)){
            break;
        }
        
    }

    printf("================================================================================\n");
    printf("JOGO ENCERRADO!\n");

    printf("GOSTARIA DE SABER A POSICAO DOS BARCOS? (1 - SIM / 0 - NAO): ");
    int resp; scanf("%d", &resp);
    if(resp){
        printf("A POSICAO DOS BARCOS ERA:\n");
        ImprimeMapa(Mapa);
    }

    printf("================================================================================\n");
    printf("O que gostaria de fazer agora?\n1 - JOGAR NOVAMENTE\n2 - VOLTAR AO MENU\nQualquer numero para sair\n");
    int resp2, aux; scanf("%d", &resp2);
    if(resp2 == 1){
        aux = Jogo();
    } else if(resp2 == 2){
        return 1;
    } else {
        printf("OBRIGADO POR JOGAR!\n");
        return 0;
    }
}