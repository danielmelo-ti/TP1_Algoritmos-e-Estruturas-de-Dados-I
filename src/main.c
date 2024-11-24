#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "headers/Lista_Sondas.h"

void modo_interativo(Lista_Sondas *sondas);
void modo_arquivo(Lista_Sondas *sondas);
void execucao(FILE *arquivo, Lista_Sondas *sondas);

int main() {
    int modo;
    printf("Insira o modo de operacao (1. Interativo | 2. Arquivo): ");
    scanf("%d", &modo);

    Lista_Sondas sondas;
    FLVaziaLS(&sondas);

    if (modo == 1) {
        modo_interativo(&sondas);
    } else if (modo == 2) {
        modo_arquivo(&sondas);
    } else {
        
    }
}

void modo_interativo(Lista_Sondas *sondas) {
    execucao(stdin, sondas);
}

void modo_arquivo(Lista_Sondas *sondas) {
    char buffer[255];

    printf("Insira o nome do arquivo a testar: ");
    scanf("%s", buffer);

    FILE *arquivo = fopen(buffer, "r");

    if (arquivo) {
        execucao(arquivo, sondas);
    } else {
        printf("Erro: Arquivo inexistente.\n");
    }
}

void execucao(FILE *arquivo, Lista_Sondas *sondas) {
    int qnt_sondas, qnt_operacoes;
    Sonda sonda_aux;
    char tipo_operacao[10];
    RochaMineral rocha_aux;

    if (arquivo == stdin) printf("Insira a quantidade de sondas usadas: ");
    fscanf(arquivo, "%d", &qnt_sondas);
    fgetc(arquivo);

    for (int i = 0; i<qnt_sondas; i++){
        preencher_dados_sonda(arquivo, &sonda_aux);
        InsereSondaLS(sondas, &sonda_aux);
    }

    if (arquivo == stdin) printf("Insira a quantidade de operacoes que voce deseja realizar: ");
    fscanf(arquivo, "%d", &qnt_operacoes);
    fgetc(arquivo);

    for (int j = 0; j<qnt_operacoes; j++){
        if (arquivo == stdin) printf("Insira a operacao: ");
        fscanf(arquivo, "%s", tipo_operacao);
        fgetc(arquivo);

        if (strcmp(tipo_operacao, "R") == 0){
            preencher_rocha_mineral(arquivo, &rocha_aux);
            calcular_distancias(sondas, &rocha_aux);
        }
        else if (strcmp(tipo_operacao, "I") == 0){
            ImprimeLS(sondas);
        }
        else if (strcmp(tipo_operacao, "E") == 0){
            for (int i = 0; i < qnt_sondas; i++) {

            }
        }
    }
}

