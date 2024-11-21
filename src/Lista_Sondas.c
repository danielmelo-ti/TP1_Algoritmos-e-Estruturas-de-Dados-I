#include <stdio.h>
#include <stdlib.h>
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
    while (atual != NULL) {
        // Calcula a distância entre a sonda e a rocha
        float distancia = distancia_sonda_rocha(&atual->sonda, rocha);
        lista_distancias[cnt] = distancia;
        id_sondas[cnt] = atual->sonda.Identificador;
        // print para testes
        printf("Distancia da Sonda %d ate a rocha: %.2f\n", atual->sonda.Identificador, distancia); //TODO: mudar do pirnt para a funcao que vai salvar as 
                                                                                                    // distancias e colocar a rocha na sonda mais proxima
        cnt++;
        atual = atual->pProx;
    }
    
    int menor_indice = 0;
    for (int i = 1; i < cnt; i++) {
        if (lista_distancias[i] < lista_distancias[menor_indice]) {
            menor_indice = i;
        }
    }

    // Identificar a sonda correspondente
    int id_menor_sonda = id_sondas[menor_indice];
    Sonda *sonda_mais_proxima = busca_sonda_por_id(LS, id_menor_sonda);

    if (sonda_mais_proxima != NULL) {
        printf("Sonda mais proxima e a Sonda %d com distancia %.2f\n", 
                id_menor_sonda, lista_distancias[menor_indice]);
    }

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
            //imprime as rochas no compartimento
            // CelulaC *pRocha = pAtual->sonda.CompSonda.pPrimeiro->pProx;
            // while (pRocha != NULL) {
            //     //imprime a categoria e o peso de cada rocha
            //     printf("  Rocha: %d, Peso: %.2f\n", pRocha->rocha.categoria, pRocha->rocha.peso);
            //     // FIXME: Quebrou aqui ó
            //     pRocha = pRocha->pProx;
            // }
            ImprimeListaRochaM(&pAtual->sonda.CompSonda);
        }

        pAtual = pAtual->pProx;
        cnt++;
    }
}

// const char* obterCategoria(Categoria cat) {
//     const char* nomes[] = {
//         "Ferrom", "Solaris", "Aquaferro", "Terrolis",
//         "Terrasol", "Aquaterra", "Calquer",
//         "Solarisfer", "Terralis", "Aquacalis"
//     };
//     return nomes[cat];
// }

// // Função para imprimir informações das sondas e suas rochas
// void imprimeLS(Sonda *listaDeSondas, int tamanho) {
//     for (int i = 0; i < tamanho; i++) {
//         Sonda sondaAtual = listaDeSondas[i];
//         printf("%d\n", sondaAtual.Identificador);

//         CelulaC *atual = sondaAtual.CompSonda.pPrimeiro;
//         while (atual != NULL) {
//             RochaMineral rochaAtual = atual->rocha;
//             printf("%s %.2f\n", obterCategoria(rochaAtual.categoria), rochaAtual.peso);
//             atual = atual->pProx;
//         }

//         printf("\n"); // Separador entre sondas
//     }
// }

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