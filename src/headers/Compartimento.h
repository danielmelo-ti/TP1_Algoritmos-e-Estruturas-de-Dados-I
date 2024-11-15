#ifndef COMPARTIMENTO_H
#define COMPARTIMENTO_H
#include "rocha_mineral.h"

typedef struct Celula
{
    RochaMineral rocha;
    struct Celula *pProx;
}Celula;

typedef struct Compartimento
{
    float PesoMax;
    Celula *pPrimeiro;
    Celula *pUltimo;
}Compartimento;

void FListaRochaM(Compartimento *LRM);
int LEhVaziaRochaM(Compartimento *LRM);
double PesoAtual(Compartimento *LRM);
int InsereRochaM(Compartimento *LRM, RochaMineral RochaM, int PesoMax);
int RmoveRochaM(Compartimento *LRM, int posicao, RochaMineral RochaM);
int TrocaRochaM(Compartimento *LRM, RochaMineral RochaM, int PesoMax);
void ImprimeListaRochaM(Compartimento *LRM);

 
#endif //COMPARTIMENTO_H