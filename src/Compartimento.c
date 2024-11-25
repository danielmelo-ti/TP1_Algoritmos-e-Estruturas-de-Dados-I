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

int RmoveRochaM(Compartimento *LRM, int posicao, RochaMineral *RochaM){
    if(LEhVaziaRochaM(LRM)){
        printf("Lista Vazia!");
        return 0;
    }

    CelulaC *pAux = LRM->pPrimeiro;
    CelulaC *pRemovida = NULL;

    for (int i = 0; i < posicao; i++)
    {
        if (pAux->pProx == NULL)
        {
            printf("Posicao Invalida!");
            return 0;
        }
        pAux = pAux->pProx;
    }

    pRemovida = pAux->pProx;

    if (pRemovida == NULL)
    {
        printf("Posicao invalida");
        return 0;
    }

    pAux->pProx = pRemovida->pProx;

    if (RochaM != NULL)
    {
        *RochaM = pRemovida->rocha;
    }
    
    if (pAux->pProx == NULL)
    {
        LRM->pUltimo = pAux;
    }
    
    return 1;
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
    CelulaC *pAuxI;
    pAuxI = LRM->pPrimeiro->pProx;
    while (pAuxI != NULL)
    {
        switch (pAuxI->rocha.categoria){
        case Ferrom:
            printf("Rocha: Ferrom, ");
            break;
        case Solaris:
            printf("Rocha: Solaris, ");
            break;
        case Aquaferro:
            printf("Rocha: Aquaferro, ");
            break;
        case Terrolis:
            printf("Rocha: Terrolis, ");
            break;
        case Terrasol:
            printf("Rocha: Terrasol, ");
            break;
        case Aquaterra:
            printf("Rocha: Aquaterra, ");
            break;
        case Calquer:
            printf("Rocha: Calquer, ");
            break;
        case Solarisfer:
            printf("Rocha: Solarisfer, ");
            break;
        case Terralis:
            printf("Rocha: Terralis, ");
            break;
        case Aquacalis:
            printf("Rocha: Aquacalis, ");
            break;
        default: printf("Rocha: Erro");
            break;
        }
        printf("Peso: %.2f\n", pAuxI->rocha.peso);
        pAuxI = pAuxI->pProx;
    }
}