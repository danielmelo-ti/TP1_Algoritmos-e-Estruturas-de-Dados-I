#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SONDA.h"
#include "rocha_mineral.h"

int main() {
    srand(time(NULL));
    RochaMineral r1;
    Lista_de_minerais lista_minerais;
    inicializa_lista(&lista_minerais);
    preencher_rocha_mineral(&r1, &lista_minerais); // Passando a lista para preencher os minerais
    imprimir_rocha_mineral(&r1); // Imprime as informações da rocha
    return 0;
}