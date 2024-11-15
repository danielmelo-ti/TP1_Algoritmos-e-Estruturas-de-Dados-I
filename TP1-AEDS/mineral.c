#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mineral.h"

//inicializa o TAD e permite que o usuário insira os dados como quiser.

void preenche_mineral(Mineral* mine, char* nome1){  
    set_nome(mine,nome1);
    if (strcmp(nome1, "Ferrolita") == 0)
    {
        mine->Dureza = 0.5;
        mine->Reatividade = 0.7;
        mine->Cor = ACINZENTADO;
    }
    else if (strcmp(nome1, "Solarium") == 0)
    {
        mine->Dureza = 0.9;
        mine->Reatividade = 0.2;
        mine->Cor = AMARELO;
    }
    else if (strcmp(nome1, "Aquavitae") == 0)
    {
        mine->Dureza = 0.5;
        mine->Reatividade = 0.8;
        mine->Cor = AZULADO;
    }
    else if (strcmp(nome1, "Terranita") == 0)
    {
        mine->Dureza = 0.7;
        mine->Reatividade = 0.6;
        mine->Cor = MARROM;
    }
    else if (strcmp(nome1, "Calaris") == 0)
    {
        mine->Dureza = 0.6;
        mine->Reatividade = 0.5;
        mine->Cor = VERMELHO;
    }
    else
    {
        printf("Esse mineral nao existe na amostra.\n");
    }
}


Mineral inicializar_mineral(Mineral* mine, char* Nome, double Dureza, double Reatividade, CORM Cor){

    set_nome(mine, Nome);
    set_hardness(mine, Dureza);
    set_react(mine, Reatividade);
    set_cor(mine, Cor);
    return(*mine);
}

// sets

void set_nome(Mineral *mine, char *nome) 
{
    strcpy(mine->Nome, nome);
}

void set_hardness(Mineral *mine, double dureza){
    mine->Dureza = dureza;
}

void set_react(Mineral *mine, double react){
    mine->Reatividade = react;
}

void set_cor(Mineral *mine, CORM cor){
    mine->Cor = cor;
}

//gets

char* get_nome(Mineral *mine){
    return(mine->Nome);
}

double get_num_data(Mineral* mine){
    return(mine->Dureza && mine->Reatividade);
}

void get_cor(Mineral* mine){
    switch (mine->Cor) {
        case ACINZENTADO:
            printf("Cor: ACINZENTADO\n");
            break;
        case AMARELO:
            printf("Cor: AMARELO\n");
            break;
        case AZULADO:
            printf("Cor: AZULADO\n");
            break;
        case MARROM:
            printf("Cor: MARROM\n");
            break;
        case VERMELHO:
            printf("Cor: VERMELHO\n");
            break;
        default:
            printf("A cor nao corresponde a nenhum mineral da regiao\n");
            break;
    }
}

//agora imprimir os valores do TAD através do uso de múltiplas funções.

void imprimir_mineral(Mineral* mine){
    get_nome(mine);
    get_num_data(mine);
    get_cor(mine);
}