#include "Lista_minerais.h"
#include "mineral.h"
#include <stdio.h>
#include <string.h>

void inicializa_lista(Lista_de_minerais* lista){
    lista->ultimo = 0;
}

void insere_mineral(Lista_de_minerais *lista, const char entrada) {
    char buffer[TMAX * PMAX];
    strncpy(buffer, entrada, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    char *palavra = strtok(buffer, " ");

    // Inserir enquanto houver palavras e espaço na lista
    while (palavra != NULL && lista->ultimo < PMAX) {
        set_mineral(&lista->minerais[lista->ultimo], palavra);
        lista->ultimo++;  // Incrementa a posição do último elemento
        palavra = strtok(NULL, " ");
    }
}
void imprime_lista(Lista_de_minerais *lista){
    //uso de ponteiro para permitir impressão mais fácil dos valores, sem necessidade de switch case
    for (int i = 0; i < lista->ultimo; i++)
    {

    get_nome(&lista->minerais[i]);
    printf("Dureza: %.1f\n", lista->minerais[i].Dureza);
    printf("Reatividade: %.1f\n", lista->minerais[i].Reatividade);

    switch (lista->minerais[i].Cor) {
        case ACINZENTADO:
            printf("Cor: ACINZENTADO\n");
            break;
        case AMARELO:
            printf("Cor: AMARELO\n");
            break;
        case AZULADO:
            printf("Cor: AZULADO\n");
            break;
        case MARROM:
            printf("Cor: MARROM\n");
            break;
        case VERMELHO:
            printf("Cor: VERMELHO\n");
            break;
        default:
            printf("A cor nao corresponde a nenhum mineral da regiao\n");
            break;
    }
    printf("--------------\n");
    }
}

void retira_mineral(Lista_de_minerais* lista, const char* Tnome){
    //Tnome é o nome usado para identificar qual Mineral remover. T vem de "target", e homenagem ao Zivianni.
    if (lista->ultimo <= 1)
    {
        printf("A lista não pode conter menos de um elemento. Se quer esvaziá-la, use a operação 'esvaziar_lista'.");
    }
    else
    { //for para percorrer a lista linear e remover o mineral
        int found = 0;
        for (int i = 0; i < lista->ultimo; i++)
        {
            if (strcmp(lista->minerais[i].Nome, Tnome) == 0)
            {   //for para ajustar os itens à frente do mineral retirado para a posição anterior
                for (int j = i; j < lista->ultimo; j++)
                {
                    lista->minerais[j] = lista->minerais[j+1];
                }
            lista->ultimo--;
            found = 1;
            break;
            }
        if (found == 0)
        {
            printf("O mineral procurado não se encotra na lista.");
        }

        }

    }


}

void limpeza(Lista_de_minerais* lista){
    lista->ultimo = 0;
}