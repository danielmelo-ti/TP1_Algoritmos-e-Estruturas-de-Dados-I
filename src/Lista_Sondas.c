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
    CelulaLS *atual = LS->pPrimeiro; // Começa do primeiro elemento da lista
    int contador = 0;
    while (atual != NULL) {
        // Calcula a distância entre a sonda e a rocha
        float distancia = distancia_sonda_rocha(&atual->sonda, rocha);
        
        // Exibe a distância da sonda até a rocha
        printf("Distancia da Sonda %d ate a rocha: %.2f\n", atual->sonda.Identificador, distancia); //TODO:mudar do pirnt para a funcao que vai salvar as 
                                                                                                    // distancias e colocar a rocha na sonda mais proxima
        
        // Avança para o próximo nó da lista
        atual = atual->pProx;
    }
}

Sonda* busca_sonda_por_id(Lista_Sondas *LS, int id_sonda) {
    CelulaLS *atual_busca_id = LS->pPrimeiro;  // Começa pelo primeiro nó

    while (atual_busca_id != NULL) {
        if (atual_busca_id->sonda.Identificador == id_sonda) {  // Verifica o Identificador
            return &(atual_busca_id->sonda);  // Retorna o endereço da sonda encontrada
        }
        atual_busca_id = atual_busca_id->pProx;  // Avança para o próximo nó
    }

    return NULL;  // Retorna NULL se não encontrar a sonda
}

void ImprimeLS(Lista_Sondas *LS) {
    CelulaLS *pAtual = LS->pPrimeiro->pProx;  // Ponteiro para o primeiro elemento válido da lista
    int cnt = 1;

    while (pAtual != NULL) {
        printf("Sonda %d:\n", cnt);

        // Verifica se o compartimento da sonda tem rochas
        if (LEhVaziaRochaM(&pAtual->sonda.CompSonda)) {
            printf("Compartimento vazio\n");
        } else {
            // Imprime as rochas no compartimento
            CelulaC *pRocha = pAtual->sonda.CompSonda.pPrimeiro->pProx;  // Inicia do primeiro elemento válido
            while (pRocha != NULL) {
                // Imprime a categoria e o peso de cada rocha
                printf("  Rocha: %d, Peso: %.2f\n", pRocha->rocha.categoria, pRocha->rocha.peso);
                // FIXME: Quebrou aqui ó
                pRocha = pRocha->pProx;  // Avança para a próxima rocha
            }
        }

        pAtual = pAtual->pProx;  // Avança para a próxima sonda
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