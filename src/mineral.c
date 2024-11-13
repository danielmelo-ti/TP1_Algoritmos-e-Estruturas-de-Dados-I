#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mineral.h"

//inicializa o TAD e permite que o usuário insira os dados como quiser.

void inicializar_mineral(Mineral* mine, MINERIO Nome, double Dureza, double Reatividade, CORM Cor){
    if (Nome < FERROLITA || Nome > CALARIS || Cor < ACINZENTADO || Cor > VERMELHO)
    {
        printf("O Nome e cor do mineral devem ser representados de acordo com os dados a seguir:\n");
        printf("FERROLITA = 1, SOLARIUM = 2, AQUAVITAE = 3, TERRANITA = 4, CALARIS = 5");
        printf("ACINZENTADO = 1, AMARELO = 2, AZULADO = 3, MARROM = 4, VERMELHO = 5");
    }
    mine->Nome = Nome;
    mine->Dureza = Dureza;
    mine->Reatividade = Reatividade;
    mine->Cor = Cor;

}

//uso do switch aqui para preencher por completo o TAD Mineral com o input apenas do valor para nome.

void set_mineral(Mineral* mine){
    set_nome(mine);
    switch (mine->Nome)
    {
    case 1:
        mine->Dureza = 0.5;
        mine->Reatividade = 0.7;
        mine->Cor = ACINZENTADO;
        break;
    case 2:
        mine->Dureza = 0.9;
        mine->Reatividade = 0.2;
        mine->Cor = AMARELO;
        break;
    case 3:
        mine->Dureza = 0.5;
        mine->Reatividade = 0.8;
        mine->Cor = AZULADO;
        break;
    case 4:
        mine->Dureza = 0.7;
        mine->Reatividade = 0.6;
        mine->Cor = MARROM;
        break;
    case 5:
        mine->Dureza = 0.6;
        mine->Reatividade = 0.5;
        mine->Cor = VERMELHO;
        break;
    default:
        printf("Esse mineral nao existe na amostra.\n");
        break;
    }

}

//função para  pedir ao usuário o número que corresponde ao mineral encontrado.

void set_nome(Mineral* mine){
    printf("Digite o número correspondente ao nome do mineral:\nFERROLITA = 1\n SOLARIUM = 2\n AQUAVITAE = 3\n TERRANITA = 4\n CALARIS = 5\n:");
    scanf("%d", (int*)&mine->Nome);

}

//função para imprimir o nome.
void get_nome(Mineral* mine){
    switch (mine->Nome)
    {
    case 1:
        printf("Nome: FERROLITA\n");
        break;
    case 2:
        printf("Nome: SOLARIUM\n");
        break;
    case 3:
        printf("Nome: AQUAVITAE\n");
        break;
    case 4:
        printf("Nome: TERRANITA\n");
        break;
    default:
        printf("Nome: CALARIS\n");
        break;
    }
}

//função para imprimir dados numéricos.
void get_num_data(Mineral* mine){
    printf("Dureza:%.1f\n", mine->Dureza);
    printf("Reatividade:%.1f\n", mine->Reatividade);
}

//função para imprimir a cor do mineral.

void get_cor(Mineral* mine){
    switch (mine->Cor) {
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
}

//agora imprimir os valores do TAD através do uso de múltiplas funções.

void imprimir_mineral(Mineral* mine){
    get_nome(mine);
    get_num_data(mine);
    get_cor(mine);
}
