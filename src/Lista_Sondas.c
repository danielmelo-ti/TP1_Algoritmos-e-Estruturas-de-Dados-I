#include <stdio.h>
#include <stdlib.h>
#include "Lista_Sondas.h"

void FLVaziaLS(Lista_Sondas *LS){
    LS->pPrimeiro = (CelulaLS*)malloc(sizeof(CelulaLS));
    LS->pUltimo = LS->pPrimeiro;
    LS->pPrimeiro->pProx = NULL;
}

int LEhVaziaLS(Lista_Sondas *LS){
    return(LS->pPrimeiro == LS->pUltimo);
}

int InsereSondaLS(Lista_Sondas *LS, Sonda *s){
    LS->pPrimeiro->pProx = (CelulaLS*)malloc(sizeof(CelulaLS));
    LS->pUltimo = LS->pPrimeiro->pProx;
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

void ImprimeLS(Lista_Sondas *LS) {
    CelulaLS *pAtual = LS->pPrimeiro->pProx;  // Ponteiro para o primeiro elemento válido da lista
    int cnt = 1;

    while (pAtual != NULL) {
        printf("Sonda %d:\n", cnt);

        // Verifica se o compartimento da sonda tem rochas
        if (LEhVaziaRochaM(&pAtual->sonda.CompSonda)) {
            printf("  Compartimento vazio\n");
        } else {
            // Imprime as rochas no compartimento
            CelulaC *pRocha = pAtual->sonda.CompSonda.pPrimeiro->pProx;  // Inicia do primeiro elemento válido
            while (pRocha != NULL) {
                // Imprime a categoria e o peso de cada rocha
                printf("  Rocha: %s, Peso: %.2f\n", pRocha->rocha.categoria, pRocha->rocha.peso);
                pRocha = pRocha->pProx;  // Avança para a próxima rocha
            }
        }

        pAtual = pAtual->pProx;  // Avança para a próxima sonda
        cnt++;
    }
}

// void ImprimeLS(Lista_Sondas *LS){
//     CelulaLS *pAtual = LS->pPrimeiro->pProx;
//     int cnt = 1;
//     while (pAtual != NULL)
//     {
//         printf("%d\n", cnt);
//         printf("%s %d\n", pAtual->sonda.CompSonda.pPrimeiro->rocha.categoria, pAtual->sonda.CompSonda.pPrimeiro->rocha.peso);
//         pAtual = pAtual->pProx;
//         cnt++;
//     }
// }

/*
void ImprimeLS(Lista_Sondas *LS){
    int cnt = 1;
    while (LS->pUltimo->pProx != NULL)
    {
        printf("%d\n", cnt);
        printf("%d\n", LS->pPrimeiro->pProx);
        LS->pPrimeiro->pProx->pProx;
        cnt++;
    }
}
*/
