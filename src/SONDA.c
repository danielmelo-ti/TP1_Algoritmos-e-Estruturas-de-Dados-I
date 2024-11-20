#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/SONDA.h"

//Funções SET
void set_IDENTIFICADOR(Sonda* sonda, int id)
{
    sonda->Identificador = id;
}

void set_VELOCIDADE(Sonda* sonda, int velo){
    sonda->velocidade = velo;
}

void set_COMBUSTIVEL(Sonda* sonda, int combus){
    sonda->combustivel = combus;
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

int get_VELOCIDADE(Sonda* sonda){
    return (sonda->velocidade);
}
int get_COMBUSTIVEL(Sonda* sonda){
    return (sonda->combustivel);
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
void Inicializar(Sonda* sonda, int id, int velo, int combus, int PesoMax, Localizacao coordenada, EstaLigada modo)
{
    set_IDENTIFICADOR(sonda, id);
    set_VELOCIDADE(sonda, velo);
    set_COMBUSTIVEL(sonda, combus);
    FListaRochaM(&sonda->CompSonda, PesoMax);
    set_LOCALIZACAO(sonda, coordenada);
    set_ESTALIGADA(sonda, modo);
}

void carrega_rocha(Sonda *sonda, RochaMineral *rocha){
    InsereRochaM(&sonda->CompSonda, rocha, 200);
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

void preencher_dados_sonda(Sonda *sonda){
    int id;
    int velo;
    int combus;
    int pesoMAX;
    Localizacao coordenada;
    EstaLigada modo;

    char buffer[100];

    id = rand() % 100;

    printf("Insira os dados da sonda: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Remove a quebra de linha, se houver
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    // Usando strtok para dividir os dados na linha
    char *token = strtok(buffer, " ");
    
    // Lê a localização (latitude e longitude)
    coordenada.Latitude = atof(token);
    token = strtok(NULL, " ");
    coordenada.Longitude = atof(token);
    
    // Lê o peso maximo (capacidade maxima)
    token = strtok(NULL, " ");
    pesoMAX = atoi(token);
    
    // Lê a velo
    token = strtok(NULL, " ");
    velo = atoi(token);

    // Lê o nivel de combustivel
    token = strtok(NULL, " ");
    combus = atoi(token);

    modo = DESLIGADA;

    Inicializar(sonda, id, velo, combus, pesoMAX, coordenada, modo);
}