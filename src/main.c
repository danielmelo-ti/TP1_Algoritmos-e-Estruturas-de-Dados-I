#include <stdio.h>
#include <stdlib.h>
#include "mineral.h"
#include "Lista_minerais.h"

int main(){

    Mineral m1;
    Mineral m2;
    Mineral* M1 = &m1;

    Lista_de_minerais l1;

    set_mineral(M1);
    set_mineral(&m2);

    inicializa_lista(&l1);
    insere_mineral(&l1, m1);
    insere_mineral(&l1, m2);
    imprime_lista(&l1);

    return 0;
}
