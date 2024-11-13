#ifndef MINERAL_H
#define MINERAL_H

#include <stdio.h>
#include <stdlib.h>

//nomes dos minerais
typedef enum MINERIO {
    FERROLITA = 1,
    SOLARIUM = 2,
    AQUAVITAE = 3,
    TERRANITA = 4,
    CALARIS = 5
} MINERIO;
//cores dos minerais
typedef enum CORM{
    ACINZENTADO = 1,
    AMARELO = 2,
    AZULADO = 3,
    MARROM = 4,
    VERMELHO = 5
} CORM;
//TAD Mineral
typedef struct{
    MINERIO Nome;
    float Dureza;
    float Reatividade;
    CORM Cor;
} Mineral;
//inicializa o TAD
void inicializar_mineral(Mineral* mine, MINERIO Nome, double Dureza, double Reatividade, CORM Cor);
//Cria, de fato, o TAD e o preenche com os valores automaticamente assim que é dado o nome do mineral através de um int.
void set_mineral(Mineral* mine);
//definir o nome do mineral.
void set_nome(Mineral* mine);
//print do TAD completo, óbvio. Por que diabos estou escrevendo isso? Tédio é foda...
void imprimir_mineral(Mineral* mine);
//definir dados numéricos. Pelo menos esse vale a pena explicar o nome. É "numerical data", se estiver curioso.
void set_num_data(Mineral* mine, float dureza, float reatividade);
//print nome, duh.
void get_nome(Mineral* mine);
//print dados numéricos.
void get_num_data(Mineral* mine);
//print cor. mais uma óbvia.
void get_cor(Mineral* mine);
#endif
