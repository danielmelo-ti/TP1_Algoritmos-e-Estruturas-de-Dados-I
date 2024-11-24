#ifndef LISTA_SONDAS_H
#define LISTA_SONDAS_H
#include "SONDA.h"

typedef struct CelulaLS
{
    Sonda sonda;
    struct CelulaLS *pProx;
}CelulaLS;

typedef struct Lista_Sondas
{
    CelulaLS* pPrimeiro;
    CelulaLS* pUltimo;
}Lista_Sondas;

void FLVaziaLS(Lista_Sondas *LS);
int LEhVaziaLS(Lista_Sondas *LS);
int InsereSondaLS(Lista_Sondas *LS, Sonda *s);
int RetiraSondaLS(Lista_Sondas *LS, int id, Sonda s);
void ImprimeLS(Lista_Sondas *LS);
Sonda* busca_sonda_por_id(Lista_Sondas *LS, int id_sonda);
//Funcao para mostrar a distancia de cada sonda em relacao a rocha
void calcular_distancias(Lista_Sondas *LS, RochaMineral *rocha);



#endif //LISTA_SONDAS_H