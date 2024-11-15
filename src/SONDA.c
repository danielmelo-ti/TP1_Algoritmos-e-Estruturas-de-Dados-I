#include <stdio.h>
#include <stdlib.h>

#include "SONDA.h"

//Funções SET
void set_IDENTIFICADOR(Sonda* sonda, int id)
{
    sonda->Identificador = id;
}

//COMPARTIMENTO NÃO DEFINIDO!
//void set_COMPARTIMENTO(Sonda* sonda)

void set_VELOCIDADE(Sonda* sonda, int velo){
    sonda->Velocidade = velo;
}

void set_COMBUSTIVEL(Sonda* sonda, int combus){
    sonda->Combustivel = combus;
}

void set_LOCALIZACAO(Sonda* sonda, Localizacao coordenada)
{
    sonda->coordenadas = coordenada;
}

void set_ESTALIGADA(Sonda* sonda, EstaLigada modo)
{
    sonda->modo = modo;
}

//Funções GET
int get_IDENTIFICADOR(Sonda* sonda)
{
    return (sonda->Identificador);
}
//COMPARTIMENTO NÃO DEFINIDO!
//Compartimento get_COMPARTIMENTO(Sonda* sonda)
int get_VELOCIDADE(Sonda* sonda){
    return (sonda->Velocidade);
}

int get_COMBUSTIVEL(Sonda* sonda){
    return (sonda->Combustivel);
}

Localizacao get_LOCALIZACAO(Sonda* sonda)
{
    return (sonda->coordenadas);
}
EstaLigada get_ESTALIGADA(Sonda* sonda)
{
    return (sonda->modo);
}


//Função para iniciar a sonda (SEM rocha mineral, ou seja, COMPARTIMENTO VAZIO, e inicialmente DESLIGADA)
void Inicializar(Sonda* sonda, int id, int velo, int combus, Localizacao coordenada, EstaLigada modo)
{
    set_IDENTIFICADOR(sonda, id);
    //COMPARTIMENTO NÃO DEFINIDO!
    //set_COMPARTIMENTO();
    set_VELOCIDADE(sonda, velo);
    set_COMBUSTIVEL(sonda, combus);
    set_LOCALIZACAO(sonda, coordenada);
    set_ESTALIGADA(sonda, 0);
}
//Função para LIGAR sonda
void LigarSonda(Sonda* sonda) {
    if (sonda->modo == DESLIGADA) {
        sonda->modo = LIGADA; // Atualiza o valor apontado para LIGADA
    }
}
//Função para DESLIGAR sonda
void DesligarSonda(Sonda* sonda) {
    if (sonda->modo == LIGADA) {
        sonda->modo = DESLIGADA; // Atualiza o valor apontado para DESLIGADA
    }
}
//Função para MOVER sonda
void MoverSonda(Sonda* sonda, Localizacao novaCoordenada)
{
    sonda->coordenadas = novaCoordenada;
    printf("Sonda movida para o local escolhido!\n");
}