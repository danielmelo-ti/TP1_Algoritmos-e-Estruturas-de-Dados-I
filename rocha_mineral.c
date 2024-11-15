#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "rocha_mineral.h"

// Inicializar nova rocha
void inicializar_rocha_mineral(RochaMineral *nova_rocha, int novo_id, float novo_peso, Lista_de_minerais *nova_lista, Localizacao_rocha nova_localizacao, char *nova_data_coleta){
    set_id(nova_rocha, novo_id);
    set_peso(nova_rocha, novo_peso);
    set_localizacao(nova_rocha, nova_localizacao);
    set_data_coleta(nova_rocha, nova_data_coleta);
    classificar_rocha(nova_rocha, nova_lista);
}

// Início dos gets
int get_id(RochaMineral *nova_rocha){
    return(nova_rocha->id);
}
float get_peso(RochaMineral *nova_rocha){
    return(nova_rocha->peso);
}
Localizacao_rocha get_localizacao(RochaMineral *nova_rocha){
    return(nova_rocha->localizacao);
}
char *get_data_coleta(RochaMineral *nova_rocha){
    return(nova_rocha->data_coleta);
}
// Fim dos gets

// Início dos sets
void set_id(RochaMineral *nova_rocha, int novo_id){
    nova_rocha->id = novo_id;
}
void set_peso(RochaMineral *nova_rocha, float novo_peso){
    nova_rocha->peso = novo_peso;
}
void set_localizacao(RochaMineral *nova_rocha, Localizacao_rocha nova_localizacao){
    nova_rocha->localizacao = nova_localizacao;
}
void set_data_coleta(RochaMineral *nova_rocha, char *nova_data_coleta){
    strcpy(nova_rocha->data_coleta, nova_data_coleta);
}
// Fim dos sets

void classificar_rocha(RochaMineral *nova_rocha, Lista_de_minerais *nova_lista){
    
    int Ferrolita = 0, Solarium = 0, Aquavitae = 0, Terranita = 0, Calaris = 0;

    for (int i = 0; i < 3; i++) {
        if (strcmp(nova_lista->Lminerais[i].Nome, "Ferrolita") == 0){
            Ferrolita += 1;
        }
        if (strcmp(nova_lista->Lminerais[i].Nome, "Solarium") == 0) {
            Solarium += 1;
        }
        if (strcmp(nova_lista->Lminerais[i].Nome, "Aquavitae") == 0) {
            Aquavitae += 1;
        }
        if (strcmp(nova_lista->Lminerais[i].Nome, "Terranita") == 0) {
            Terranita += 1;
        }
        if (strcmp(nova_lista->Lminerais[i].Nome, "Calaris") == 0) {
            Calaris += 1;
        }
    }

    if (Ferrolita == 1 && Solarium == 0 && Aquavitae == 0 && Terranita == 0 && Calaris == 0) {
        nova_rocha->categoria = Ferrom;
    }
    else if (Solarium == 1 && Ferrolita == 0 && Aquavitae == 0 && Terranita == 0 && Calaris == 0){
        nova_rocha->categoria = Solaris;
    }
    else if (Ferrolita == 1 && Aquavitae == 1 && Solarium == 0 && Terranita == 0 && Calaris == 0){
        nova_rocha->categoria = Aquaferro;
    }
    else if (Terranita == 1 && Calaris == 1 && Ferrolita == 0 && Aquavitae == 0 && Solarium == 0){
        nova_rocha->categoria = Terrolis;
    }
    else if (Terranita == 1 && Solarium == 1 && Ferrolita == 0 && Aquavitae== 0 && Calaris == 0){
        nova_rocha->categoria = Terrasol;
    }
    else if (Aquavitae == 1 && Terranita == 1 && Ferrolita == 0 && Solarium == 0 && Calaris == 0){
        nova_rocha->categoria = Aquaterra;
    }
    else if (Calaris == 1 && Aquavitae == 1 && Ferrolita == 0 && Solarium == 0 && Terranita == 0){
        nova_rocha->categoria = Calquer;
    }
    else if (Solarium == 1 && Ferrolita == 1 && Aquavitae == 0 && Terranita == 0 && Calaris == 0){
        nova_rocha->categoria = Solarisfer;
    }
    else if (Terranita == 1 && Ferrolita == 1 && Aquavitae == 0 && Solarium == 0 && Calaris == 0){
        nova_rocha->categoria = Terralis;
    }
    else if (Aquavitae == 1 && Calaris == 1 && Ferrolita == 1){
        nova_rocha->categoria = Aquacalis;
    }
}

void preencher_rocha_mineral(RochaMineral *nova_rocha, Lista_de_minerais *nova_lista){
        int id = 0;
        float peso = 0;
        Localizacao_rocha localizacao;
        char data_coleta[255];

        char mineral_entrada[255];

        id = rand() % 100;

        printf("Insira a localizacao: (Latitude e Longitude) ");
        scanf("%f %f", &localizacao.Latitude, &localizacao.Longitude);
        printf("Insira o peso: ");
        scanf("%f", &peso);

        //data

        time_t t = time(NULL);
        struct tm data_hora_atual = *localtime(&t);

        if (data_hora_atual.tm_hour - 3 < 0) {
            int aux = data_hora_atual.tm_hour;
            data_hora_atual.tm_hour = 24 + aux - 3;
        } else {
        sprintf(data_coleta, "Dia: %02d, Mes: %02d, Ano: %d, Hora: %02d:%02d:%02d", data_hora_atual.tm_mday - 1, 
                data_hora_atual.tm_mon + 1, data_hora_atual.tm_year + 1900, data_hora_atual.tm_hour, 
                data_hora_atual.tm_min, data_hora_atual.tm_sec);
        }

        //Lê a linha inteira
        fgetc(stdin);
        fgets(mineral_entrada, 255, stdin);
        //Utiliza strtok para dividir a string com base no segundo parâmetro, em até três palavras
        char *mineral1 = strtok(mineral_entrada, " ");
        char *mineral2 = strtok(NULL, " ");
        char *mineral3 = strtok(NULL, " ");

        insere_mineral(nova_lista, mineral1);
        insere_mineral(nova_lista, mineral2);
        insere_mineral(nova_lista, mineral3);

        inicializar_rocha_mineral(nova_rocha, id, peso, nova_lista, localizacao, data_coleta);

}

void imprimir_rocha_mineral(RochaMineral *nova_rocha){
    printf("ID: %d", nova_rocha->id);
    printf("\nCategoria: %s", nova_rocha->categoria);
    printf("\nPeso: %f", nova_rocha->peso);
    printf("\nLocalizacao: %f %f", nova_rocha->localizacao.Latitude, nova_rocha->localizacao.Longitude);
    printf("\nData da coleta: %s", nova_rocha->data_coleta);
}