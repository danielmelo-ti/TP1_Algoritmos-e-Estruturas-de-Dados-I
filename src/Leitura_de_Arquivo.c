#include <stdio.h>
#include <string.h>
#include "Leitura_de_Arquivo.h"

void ler_sondas(FILE *arquivo, Lista_Sondas *lista_sondas) {
    int qnt_sondas;
    Sonda sonda_aux;

    fscanf(arquivo, "%d", &qnt_sondas); // Lê o número de sondas

    for (int i = 0; i < qnt_sondas; i++) {
        preencher_dados_sonda(&sonda_aux); // Função para preencher dados da sonda
        InsereSondaLS(lista_sondas, &sonda_aux); // Insere na lista de sondas
    }
}

void processar_operacoes(FILE *arquivo, Lista_Sondas *lista_sondas, Lista_de_minerais *lista_minerais) {
    int qnt_operacoes;
    char tipo_operacao[10];
    RochaMineral rocha_aux;

    fscanf(arquivo, "%d", &qnt_operacoes); // Lê o número de operações

    for (int j = 0; j < qnt_operacoes; j++) {
        fscanf(arquivo, "%s", tipo_operacao); // Lê o tipo de operação

        if (strcmp(tipo_operacao, "R") == 0) {
            preencher_rocha_mineral(&rocha_aux, lista_minerais); // Preenche os dados da rocha
            calcular_distancias(lista_sondas, &rocha_aux); // Calcula distâncias para as sondas
            // TODO: Encontrar a sonda mais próxima e carregar a rocha
        } else if (strcmp(tipo_operacao, "I") == 0) {
            ImprimeLS(lista_sondas); // Imprime a lista de sondas
        } else if (strcmp(tipo_operacao, "E") == 0) {
            // TODO: Implementar redistribuição
        }
    }
}

