#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "headers/sistema_controle.h"
#include "Leitura_de_Arquivo.h"

int main() {
    FILE *arquivo = fopen("ENTRADATESTE1.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    Lista_Sondas lista_sondas;
    Lista_de_minerais lista_minerais;

    FLVaziaLS(&lista_sondas);
    inicializa_lista(&lista_minerais);

    // Chama as funções para leitura e processamento
    ler_sondas(arquivo, &lista_sondas);
    processar_operacoes(arquivo, &lista_sondas, &lista_minerais);

    fclose(arquivo);
    return 0;
}