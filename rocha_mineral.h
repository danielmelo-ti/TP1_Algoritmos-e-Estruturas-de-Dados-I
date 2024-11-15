#ifndef ROCHA_MINERAL_H
#define ROCHA_MINERAL_H

#include "Lista_minerais.h"

typedef enum Categoria {
    Ferrom,
    Solaris,
    Aquaferro,
    Terrolis,
    Terrasol,
    Aquaterra,
    Calquer,
    Solarisfer,
    Terralis,
    Aquacalis
} Categoria;

typedef struct Localizacao_rocha {
    float Latitude;
    float Longitude;
} Localizacao_rocha;

typedef struct RochaMineral {
    int id;
    float peso;
    Lista_de_minerais lista;
    Categoria categoria;
    Localizacao_rocha localizacao;
    char data_coleta[255];
} RochaMineral;

//inicializa rocha
void inicializar_rocha_mineral(RochaMineral *nova_rocha, int novo_id, float novo_peso, Lista_de_minerais *nova_lista, Localizacao_rocha nova_localizacao, char *nova_data_coleta);

//get
int get_id(RochaMineral *nova_rocha);
float get_peso(RochaMineral *nova_rocha);
Categoria get_categoria(RochaMineral *nova_rocha);
Localizacao_rocha get_localizacao(RochaMineral *nova_rocha);
char *get_data_coleta(RochaMineral *nova_rocha);

//set
void set_id(RochaMineral *nova_rocha, int novo_id);
void set_peso(RochaMineral *nova_rocha, float novo_peso);
void set_localizacao(RochaMineral *nova_rocha, Localizacao_rocha nova_localizacao);
void set_data_coleta(RochaMineral *nova_rocha, char *nova_data_coleta);

// categoriza a rocha
void classificar_rocha(RochaMineral *nova_rocha, Lista_de_minerais *nova_lista);
// imprime rocha mineral
void imprimir_rocha_mineral(RochaMineral *nova_rocha);

#endif