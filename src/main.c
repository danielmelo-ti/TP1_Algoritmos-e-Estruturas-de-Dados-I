#include <stdio.h>
#include <stdlib.h>
#include "mineral.h"

int main(){

    Mineral m1;
    Mineral* M = &m1;

    set_mineral(M);
    imprimir_mineral(M);

    return 0;
}
