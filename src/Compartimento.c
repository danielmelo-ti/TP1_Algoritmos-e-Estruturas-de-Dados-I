#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/compartimento.h"

void FListaRochaM(Compartimento *LRM, int pesoMAX){
    LRM->pPrimeiro = (CelulaC*)malloc(sizeof(CelulaC));
    LRM->pUltimo = LRM->pPrimeiro;
    LRM->pPrimeiro->pProx = NULL;
    LRM->pesoMAX = pesoMAX;
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

    CelulaC *pAux;
    
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
    LRM->pUltimo->pProx = (CelulaC*) malloc(sizeof(CelulaC));
    LRM->pUltimo = LRM->pUltimo->pProx;
    LRM->pUltimo->rocha = *RochaM;
    LRM->pUltimo->pProx = NULL;
    return 1;
}

int RmoveRochaM(Compartimento *LRM, int posicao, RochaMineral RochaM){
    //Implementar função
}

int TrocaRochaM(Compartimento *LRM, RochaMineral *RochaM, int PesoMax){
    CelulaC *pAux;
    pAux = LRM->pPrimeiro->pProx;
    while (pAux->rocha.categoria != RochaM->categoria)
    {
        pAux = pAux->pProx;
    }
    (pAux->rocha.peso) = (RochaM->peso);
}

void ImprimeListaRochaM(Compartimento *LRM){
    CelulaC *pAux;
    pAux = LRM->pPrimeiro->pProx;
    while (pAux != NULL)
    {
        printf("%s\n", pAux->rocha.categoria);
        pAux = pAux->pProx;
    }
}