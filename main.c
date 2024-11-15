#include <stdio.h>
#include <stdlib.h>
#include "sonda.h"

int main(){

    int qnt_operacoes;
    int qnt_sondas;
    Sonda sonda1;
    Localizacao l1; // loc sonda
    EstaLigada modo1;

    l1.Latitude = 0.000;
    l1.Longitude = 0.000;

    modo1 = 0;

    printf("Quantidade de sondas: ");
    scanf("%d", &qnt_sondas);

    for(int j = 0; j < qnt_sondas; j++){

        Inicializar(&sonda1, 100, 50, 200, l1, modo1);
    }

    printf("Digite a quantidade de opercoes a serem realizadas: ");
    scanf("%d", &qnt_operacoes);

    // preencher nova rocha mineral

    for (int i = 0; i < qnt_operacoes; i++){
        scanf("%s", )
    }
}

/*
    

        inicializa_lista_mineral();

        int id;
        float peso;
        Localizacao_rocha localizacao;
        char data_coleta[255];

        char mineral_entrada[20];

        srand(time(NULL)); //usado para que o código veja o horário do pc e deixe 
        id = rand() % 100;

        printf("Insira a localizacao: (Latitude e Longitude) ");
        scanf("%f %f", &localizacao.Latitude, &localizacao.Longitude);
        printf("Insira o peso: ");
        scanf("%f", &peso);

        //data

        time_t t = time(NULL);
        struct tm *data_hora_atual = localtime(&t);

        if (data_hora_atual->tm_hour - 3 < 0) {
            int aux = data_hora_atual->tm_hour;
            data_hora_atual->tm_hour = 24 + aux - 3;
        } else {
        sprintf(data_coleta, "Dia: %02d, Mês: %02d, Ano: %d, Hora: %02d:%02d:%02d", data_hora_atual->tm_mday - 1, 
                data_hora_atual->tm_mon + 1, data_hora_atual->tm_year + 1900, data_hora_atual->tm_hour, 
                data_hora_atual->tm_min, data_hora_atual->tm_sec);
        }

        //Lê a linha inteira
        fgets(mineral_entrada, sizeof(mineral_entrada), stdin);
        //Utiliza strtok para dividir a string com base no segundo parâmetro, em até três palavras
        char *mineral1 = strtok(mineral_entrada, " \n");
        char *mineral2 = strtok(NULL, " \n");
        char *mineral3 = strtok(NULL, " \n");
*/