#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compartimento.h"

void FListaRochaM(Compartimento *LRM, int pesoMAX){
    LRM->pPrimeiro = (Celula*)malloc(sizeof(Celula));
    LRM->pUltimo = LRM->pPrimeiro;
    LRM->pPrimeiro->pProx = NULL;
    LRM->PesoMax = pesoMAX;
}

int LEhVaziaRochaM(Compartimento *LRM){
    return(LRM->pPrimeiro == LRM->pUltimo);
}
double PesoAtual(Compartimento *LRM){
    double peso = 0;
    if (LEhVaziaRochaM(LRM))
    {
        return 0;
    }

    Celula *pAux;
    
    for(pAux = LRM->pPrimeiro->pProx; pAux != NULL; pAux = pAux->pProx)
    {
        peso += (pAux->rocha.peso);
    }
    return peso;
}

int InsereRochaM(Compartimento *LRM, RochaMineral *RochaM, int PesoMax){   
    int peso = PesoAtual(LRM);
    peso += (RochaM->peso);
    if (peso>PesoMax)
    {
        return 0;
    }
    LRM->pUltimo->pProx = (Celula*) malloc(sizeof(Celula));
    LRM->pUltimo = LRM->pUltimo->pProx;
    LRM->pUltimo->rocha = *RochaM;
    LRM->pUltimo->pProx = NULL;
    return 1;
}

int RmoveRochaM(Compartimento *LRM, int posicao, RochaMineral RochaM){
    //Implementar função
}

int TrocaRochaM(Compartimento *LRM, RochaMineral *RochaM, int PesoMax){
    Celula *pAux;
    pAux = LRM->pPrimeiro->pProx;
    while (strcmp(pAux->rocha.categoria, RochaM->categoria) != 0)
    {
        pAux = pAux->pProx;
    }
    (pAux->rocha.peso) = (RochaM->peso);
}

void ImprimeListaRochaM(Compartimento *LRM){
    Celula *pAux;
    pAux = LRM->pPrimeiro->pProx;
    while (pAux != NULL)
    {
        printf("%s\n", pAux->rocha.categoria);
        pAux = pAux->pProx;
    }
}