#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Lista_Sondas.h"

int main() {
    srand(time(NULL));

    int qnt_sondas;
    Sonda sonda_aux;
    int qnt_operacoes;
    char tipo_operacao[10];
    RochaMineral rocha_aux;
    Lista_de_minerais lista_minerais;
    Compartimento lista_rochas;
    Lista_Sondas lista_sondas;

    inicializa_lista(&lista_minerais);
    FListaRochaM(&lista_rochas, 200);
    FLVaziaLS(&lista_sondas);

    printf("Insira a quantidade de sondas usadas: ");
    scanf("%d", &qnt_sondas);
    getchar();

    for (int i = 0; i<qnt_sondas; i++){
        preencher_dados_sonda(&sonda_aux);
        InsereSondaLS(&lista_sondas, &sonda_aux);
    }

    printf("Insira a quantidade de operacoes que voce deseja realizar: ");
    scanf("%d", &qnt_operacoes);
    getchar();

    for (int j = 0; j<qnt_operacoes; j++){
        printf("Insira a operacao: ");
        scanf("%s", tipo_operacao);
        getchar();
        if (strcmp(tipo_operacao, "R") == 0){
            preencher_rocha_mineral(&rocha_aux, &lista_minerais);
            InsereRochaM(&lista_rochas, &rocha_aux, 200);
            ImprimeListaRochaM(&lista_rochas);
        }
        else if (strcmp(tipo_operacao, "I") == 0){
            ImprimeLS(&lista_sondas);
        }
        else if (strcmp(tipo_operacao, "E") == 0){
            // Equilibra os pesos
        }
    }
}