#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "headers/Lista_Sondas.h"

void FLVaziaLS(Lista_Sondas *LS){
    LS->pPrimeiro = (CelulaLS*)malloc(sizeof(CelulaLS));
    LS->pUltimo = LS->pPrimeiro;
    LS->pPrimeiro->pProx = NULL;
}

int LEhVaziaLS(Lista_Sondas *LS){
    return(LS->pPrimeiro == LS->pUltimo);
}

int InsereSondaLS(Lista_Sondas *LS, Sonda *s){
    LS->pUltimo->pProx = (CelulaLS*)malloc(sizeof(CelulaLS));
    LS->pUltimo = LS->pUltimo->pProx;
    LS->pUltimo->sonda = *s;
    LS->pUltimo->pProx = NULL;
    return 1;
}

int RetiraSondaLS(Lista_Sondas *LS, int id, Sonda s){
    CelulaLS *pAnt = LS->pPrimeiro;
    CelulaLS *pAtual = LS->pPrimeiro->pProx;

    while (pAtual != NULL)
    {
        if (pAtual->sonda.Identificador == id)
        {
            pAnt->pProx = pAtual->pProx;

            if (pAtual == LS->pUltimo)
            {
                LS->pUltimo = pAnt;
            }

            free(pAtual);
            return 1; //id encontrado
        }

        pAnt = pAtual;
        pAtual = pAtual->pProx;
    }
    return 0; //id não encontrado
}

void calcular_distancias(Lista_Sondas *LS, RochaMineral *rocha){
    float lista_distancias[15];
    int id_sondas[15];
    CelulaLS *atual = LS->pPrimeiro->pProx;
    int cnt = 0;
    int menor_indice = 0;
    while (atual != NULL) {
        // Calcula a distância entre a sonda e a rocha
        float distancia = distancia_sonda_rocha(&atual->sonda, rocha);
        lista_distancias[cnt] = distancia;
        id_sondas[cnt] = atual->sonda.Identificador;
        // print para testes
        printf("  Distancia da Sonda %d ate a rocha: %.2f\n", atual->sonda.Identificador, distancia);
        cnt++;
        atual = atual->pProx;
    }

    float menor_distancia = INFINITY;

    for (int i = 0; i < cnt; i++) {
        Sonda sonda = *busca_sonda_por_id(LS, id_sondas[i]);
        if (menor_distancia > lista_distancias[i] && rocha->peso <= sonda.CompSonda.pesoMAX - PesoAtual(&sonda.CompSonda)){
            menor_indice = i;
            menor_distancia = lista_distancias[i];
        }
    }

    // Identificar a sonda correspondente
    int id_sonda_proxima = id_sondas[menor_indice];
    Sonda *sonda_mais_proxima = busca_sonda_por_id(LS, id_sonda_proxima);

    if (sonda_mais_proxima != NULL) {
        printf("============================================================\n");
        printf("Sonda mais proxima e a Sonda %d com distancia %.2f\n", id_sonda_proxima, lista_distancias[menor_indice]);
        printf("============================================================\n");
    }

    MoverSonda(sonda_mais_proxima, rocha);

    InsereRochaM(&sonda_mais_proxima->CompSonda, rocha, PMAX);
}

Sonda* busca_sonda_por_id(Lista_Sondas *LS, int id_sonda) {
    CelulaLS *atual_busca_id = LS->pPrimeiro->pProx;

    while (atual_busca_id != NULL) {
        if (atual_busca_id->sonda.Identificador == id_sonda) {
            return &(atual_busca_id->sonda);  //retorna o endereço da sonda mais proxima
        }
        atual_busca_id = atual_busca_id->pProx;
    }

    return NULL;
}

void ImprimeLS(Lista_Sondas *LS) {
    CelulaLS *pAtual = LS->pPrimeiro->pProx;
    int cnt = 1;

    while (pAtual != NULL) {
        printf("Sonda %d:\n", cnt);

        //verifica se o compartimento da sonda tem rochas
        if (LEhVaziaRochaM(&pAtual->sonda.CompSonda)) {
            printf("Compartimento vazio\n");
        } else {
            ImprimeListaRochaM(&pAtual->sonda.CompSonda);
        }

        pAtual = pAtual->pProx;
        cnt++;
    }
}