#include <stdio.h>
#include <stdlib.h>
#include "mineral.h"
#include "Lista_minerais.h"
#include "rocha_mineral.c"

int main(){

    Lista_de_minerais l1;

    RochaMineral r1;

    preencher_rocha_mineral(&r1);

    return 0;
}
