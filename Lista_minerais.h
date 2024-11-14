#if !defined(MINERAL)
#define MINERAL
#define PMAX 3
#include "mineral.h"

typedef struct {
    Mineral minerais[PMAX];
    int ultimo;
} Lista_de_minerais;

//cria a lista vazia
void inicializa_lista(Lista_de_minerais* lista);
//retira um mineral pelo nome
void retira_mineral(Lista_de_minerais* lista, const char* Tnome);
//insere um mineral no final da lista
void insere_mineral(Lista_de_minerais* lista, const char* mine);
//imprime todos os componentes da lista
void imprime_lista(Lista_de_minerais* lista);
//esvazia a lista
void limpeza(Lista_de_minerais* lista);

#endif // mineral
