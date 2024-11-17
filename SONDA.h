#ifndef SONDA_H_INCLUDED
#define SONDA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Compartimento.h"

typedef struct Localizacao
{
    double Latitude;
    double Longitude;
}Localizacao;

typedef enum EstaLigada
{
    DESLIGADA = 0,
    LIGADA = 1
}EstaLigada;

typedef struct Sonda
{
    int Identificador;
    int velocidade;
    int combustivel;
    Compartimento CompSonda;
    Localizacao coordenadas;
    EstaLigada modo;
}Sonda;

//Funções SET
void set_IDENTIFICADOR(Sonda* sonda, int Id);
//COMPARTIMENTO NÃO DEFINIDO!
//void set_COMPARTIMENTO(Sonda* sonda);
void set_LOCALIZACAO(Sonda* sonda, Localizacao coordenada);
void set_VELOCIDADE(Sonda* sonda, int velo);
void set_COMBUSTIVEL(Sonda* sonda, int combus);
void set_ESTALIGADA(Sonda* sonda, EstaLigada modo);

//Funções GET
int get_IDENTIFICADOR(Sonda* S);
//COMPARTIMENTO NÃO DEFINIDO!
//Compartimento get_COMPARTIMENTO(Sonda* sonda);
void get_VELOCIDADE(Sonda* sonda);
void get_COMBUSTIVEL(Sonda* sonda);
Localizacao get_LOCALIZACAO(Sonda* sonda);
EstaLigada get_ESTALIGADA(Sonda* sonda);


//Função para iniciar a sonda (SEM rocha mineral, ou seja, COMPARTIMENTO VAZIO, e inicialmente DESLIGADA)
void Inicializar(Sonda* sonda, int id, int velo, int combus, int pesoMAX, Localizacao coordenada, EstaLigada modo);
//Função para LIGAR sonda
void LigarSonda(Sonda* sonda);
//Função para DESLIGAR sonda
void DesligarSonda(Sonda* sonda);
//Função para MOVER sonda
void MoverSonda(Sonda* sonda, Localizacao novaCoordenada);
//Funcao para preencher dados da sonda
void preencher_dados_sonda(Sonda *sonda);
#endif // SONDA_H_INCLUDED