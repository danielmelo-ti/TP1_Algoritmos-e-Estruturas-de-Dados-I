#ifndef COMPARTIMENTO_H_
#define COMPARTIMENTO_H_

#include "rocha_mineral.h"

//cria a lista vazia
void inicializa_compartimento(Lista_de_minerais* lista);
//retira um mineral pelo nome
void retira_mineral(Lista_de_minerais* lista, MINERIO Tnome);
//insere um mineral no final da lista
void insere_mineral(Lista_de_minerais* lista, Mineral mine);
//imprime todos os componentes da lista
void imprime_lista(Lista_de_minerais* lista);
//esvazia a lista
void limpeza(Lista_de_minerais* lista);

#endif