#ifndef MINERAL_H
#define MINERAL_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define TMAX 100
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
    char Nome[TMAX];
    float Dureza;
    float Reatividade;
    CORM Cor;
} Mineral;

//inicializa o TAD
Mineral inicializar_mineral(Mineral* mine, char* Nome, double Dureza, double Reatividade, CORM Cor);

//Cria, de fato, o TAD e o preenche com os valores automaticamente assim que é dado o nome do mineral através de um int.
void preenche_mineral(Mineral* mine, char* Nome);

//sets

//definir o nome do mineral.
void set_nome(Mineral* mine, char* Nome);

//define a dureza
void set_hardness(Mineral *mine, double hard);
//define a reatividade
void set_react(Mineral *mine, double react);
//define cor
void set_cor(Mineral *mine, CORM cor);
//gets

//print nome, duh.
char* get_nome(Mineral* mine);
//print dados numéricos.
double get_num_data(Mineral* mine);
//print cor. mais uma óbvia.
void get_cor(Mineral* mine);
//print do TAD completo, óbvio. Por que diabos estou escrevendo isso? Tédio é foda...
void imprimir_mineral(Mineral* mine);
#endif