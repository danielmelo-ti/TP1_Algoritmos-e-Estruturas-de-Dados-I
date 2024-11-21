#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "headers/sistema_controle.h"

int entrada;

void modo_entrada(){
    printf("Qual modo de entrada voce deseja utilizar: \n");
    printf("1 - Leitura de arquivo\n");
    printf("2 - Menu interativo\n");
    scanf("%d", &entrada);
    if(entrada == 1){
        inicializar_sistema_controle_CA();
    } else {
        inicializar_sistema_controle_I();
    }
}

void inicializar_sistema_controle_CA(){
    int qnt_sondas;
    Sonda sonda_aux;
    int qnt_operacoes;
    char tipo_operacao[10];
    RochaMineral rocha_aux;
    Lista_de_minerais lista_minerais;
    Compartimento lista_rochas;
    Lista_Sondas lista_sondas;

    inicializa_lista(&lista_minerais);
    FLVaziaLS(&lista_sondas);

    printf("Insira a quantidade de sondas usadas: ");
    scanf("%d", &qnt_sondas);
    getchar();

    for (int i = 0; i<qnt_sondas; i++){
        preencher_dados_sonda(&sonda_aux, lista_rochas);
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
            calcular_distancias(&lista_sondas, &rocha_aux);
            // TODO: funcao para pegar a sonda mais proxima
            // TODO: carrega_rocha (sonda mais proxima, rocha, PMAX)
        }
        else if (strcmp(tipo_operacao, "I") == 0){
            ImprimeLS(&lista_sondas);
        }
        else if (strcmp(tipo_operacao, "E") == 0){
            // TODO: Redistribui
        }
    }
}

void inicializar_sistema_controle_I(){
    int qnt_sondas;
    Sonda sonda_aux;
    int qnt_operacoes;
    char tipo_operacao[10];
    RochaMineral rocha_aux;
    Lista_de_minerais lista_minerais;
    Compartimento lista_rochas;
    Lista_Sondas lista_sondas;

    int operacao_interativo;
    
    int operacao_acabou = 1;

    inicializa_lista(&lista_minerais);
    FListaRochaM(&lista_rochas, 200);
    FLVaziaLS(&lista_sondas);

    while (operacao_acabou != 2){
        printf("====================\n");
        printf("1 - Coleta\n");
        printf("2 - Impressao\n");
        printf("3 - Redistribuicao\n");
        printf("====================\n");
        printf("O que deseja fazer: ");
        scanf("%d", &operacao_interativo);
        if (operacao_interativo == 1){
            preencher_rocha_mineral(&rocha_aux, &lista_minerais);
            InsereRochaM(&lista_rochas, &rocha_aux, 200);
        }
        else if (operacao_interativo == 2){
            ImprimeLS(&lista_sondas);
        }
        else if (operacao_interativo == 3){
            // Redistribui
        }
        printf("Procedimento realizado!\n");
        printf("Deseja fazer nova operacao? (1 - SIM / 2 - NAO)\n");
        scanf("%d", &operacao_acabou);
    }
}