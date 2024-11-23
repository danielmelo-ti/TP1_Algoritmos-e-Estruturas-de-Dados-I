#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "Lista_Sondas.h"

// Funções para leitura do arquivo
void ler_sondas(FILE *arquivo, Lista_Sondas *lista_sondas);
void processar_operacoes(FILE *arquivo, Lista_Sondas *lista_sondas, Lista_de_minerais *lista_minerais);

#endif // ARQUIVO_H
