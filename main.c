#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "SONDA.h"

int main() {
    srand(time(NULL));

    int qnt_sondas;
    Sonda sonda1;
    int qnt_operacoes;
    char tipo_operacao[10];
    RochaMineral rocha1;
    Lista_de_minerais lista1;

    printf("Insira a quantidade de sondas usadas: ");
    scanf("%d", &qnt_sondas);

    for (int i = 0; i<qnt_sondas; i++){
        preencher_dados_sonda(&sonda1);
    }

    printf("Insira a quantidade de operacoes que voce deseja realizar: ");
    scanf("%d", &qnt_operacoes);

    for (int j = 0; j<qnt_operacoes; j++){
        printf("Insira a operacao: ");
        scanf("%s", tipo_operacao);
        if (strcmp(tipo_operacao, "R") == 0){
            preencher_rocha_mineral(&rocha1, &lista1);
        }
        else if (strcmp(tipo_operacao, "I") == 0){
            // imprime dados da sonda
        }
        else if (strcmp(tipo_operacao, "E") == 0){
            // Equilibra os pesos
        }
    }

    RochaMineral r1;
    Lista_de_minerais lista_minerais;
    inicializa_lista(&lista_minerais);
    preencher_rocha_mineral(&r1, &lista_minerais); // Passando a lista para preencher os minerais
    imprime_lista(&lista_minerais);
    imprimir_rocha_mineral(&r1); // Imprime as informações da rocha
    return 0;
}