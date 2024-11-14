#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> // Necessária para utilizar o português no código
#include <time.h> // Necessária para puxar data e hora atuais para o código

#include "mineral.h"
#include "rocha_mineral.h"
#include "Lista_minerais.h"

// Inicializar nova rocha
void inicializar_rocha_mineral(RochaMineral *nova_rocha, int novo_id, float novo_peso, Lista_de_minerais nova_lista, Categoria nova_categoria, Localizacao_rocha nova_localizacao, char *nova_data_coleta){
    set_id(nova_rocha, novo_id);
    set_peso(nova_rocha, novo_peso);
    set_lista(nova_rocha, nova_lista);
    set_categoria(nova_rocha, nova_categoria);
    set_localizacao(nova_rocha, nova_localizacao);
    set_data_coleta(nova_rocha, nova_data_coleta);
}

// Início dos gets
int get_id(RochaMineral *nova_rocha){
    return(nova_rocha->id);
}
float get_peso(RochaMineral *nova_rocha){
    return(nova_rocha->peso);
}
Lista_de_minerais get_lista(RochaMineral *nova_rocha){
    return(nova_rocha->lista);
}
Categoria get_categoria(RochaMineral *nova_rocha){
    return(nova_rocha->categoria);
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
void set_lista(RochaMineral *nova_rocha, Lista_de_minerais nova_lista){
    nova_rocha->lista = nova_lista;
}
void set_categoria(RochaMineral *nova_rocha, Categoria nova_categoria){
    nova_rocha->categoria = nova_categoria;
}
void set_localizacao(RochaMineral *nova_rocha, Localizacao_rocha nova_localizacao){
    nova_rocha->localizacao = nova_localizacao;
}
void set_data_coleta(RochaMineral *nova_rocha, char *nova_data_coleta){
    strcpy(nova_rocha->data_coleta, nova_data_coleta);
}
// Fim dos sets

void classificar_rocha(RochaMineral *nova_rocha){
    
    int Ferrolita = 0, Solarium = 0, Aquavitae = 0, Terranita = 0, Calaris = 0;

    for (int i = 0; i < 3; i++) {
        if (strcmp(nova_rocha->lista.minerais[i].Nome, "Ferrolita") == 0){
            Ferrolita += 1;
        }
        if (strcmp(nova_rocha->lista.minerais[i].Nome, "Solarium") == 0) {
            Solarium += 1;
        }
        if (strcmp(nova_rocha->lista.minerais[i].Nome, "Aquavitae") == 0) {
            Aquavitae += 1;
        }
        if (strcmp(nova_rocha->lista.minerais[i].Nome, "Terranita") == 0) {
            Terranita += 1;
        }
        if (strcmp(nova_rocha->lista.minerais[i].Nome, "Calaris") == 0) {
            Calaris += 1;
        }
    }

    if (Ferrolita == 1 && Solarium == 0 && Aquavitae == 0 && Terranita == 0 && Calaris == 0) {
        strcpy(nova_rocha->categoria, "Ferrom");
    }
    else if (Solarium == 1 && Ferrolita == 0 && Aquavitae == 0 && Terranita == 0 && Calaris == 0){
        strcpy(nova_rocha->categoria, "Solaris");
    }
    else if (Ferrolita == 1 && Aquavitae == 1 && Solarium == 0 && Terranita == 0 && Calaris == 0){
        strcpy(nova_rocha->categoria, "Aquaferro");
    }
    else if (Terranita == 1 && Calaris == 1 && Ferrolita == 0 && Aquavitae == 0 && Solarium == 0){
        strcpy(nova_rocha->categoria, "Terrolis");
    }
    else if (Terranita == 1 && Solarium == 1 && Ferrolita == 0 && Aquavitae== 0 && Calaris == 0){
        strcpy(nova_rocha->categoria, "Terrasol");
    }
    else if (Aquavitae == 1 && Terranita == 1 && Ferrolita == 0 && Solarium == 0 && Calaris == 0){
        strcpy(nova_rocha->categoria, "Aquaterra");
    }
    else if (Calaris == 1 && Aquavitae == 1 && Ferrolita == 0 && Solarium == 0 && Terranita == 0){
        strcpy(nova_rocha->categoria, "Calquer");
    }
    else if (Solarium == 1 && Ferrolita == 1 && Aquavitae == 0 && Terranita == 0 && Calaris == 0){
        strcpy(nova_rocha->categoria, "Solarisfer");
    }
    else if (Terranita == 1 && Ferrolita == 1 && Aquavitae == 0 && Solarium == 0 && Calaris == 0){
        strcpy(nova_rocha->categoria, "Terralis");
    }
    else if (Aquavitae == 1 && Calaris == 1 && Ferrolita == 1){
        strcpy(nova_rocha->categoria, "Aquacalis");
    }
}

void preencher_rocha_mineral(RochaMineral *nova_rocha){
    int id;
    float peso;
    Lista_de_minerais lista;
    Categoria categoria;
    Localizacao_rocha localizacao;
    char data_coleta[255];

    char mineral_entrada[20];

    srand(time(NULL)); //usado para que o código veja o horário do pc e deixe 
    int id = rand() % 100;

    print("Insira a localizacao: (Latitude e Longitude) ");
    scanf("%f %f", localizacao.Latitude, localizacao.Longitude);
    printf("Insira o peso: ");
    scanf("%f", peso);
    printf("Insira os minerais: ");

    // Lê a linha inteira
    fgets(mineral_entrada, sizeof(mineral_entrada), stdin);
    // Utiliza strtok para dividir a string com base no segundo parâmetro, em até três palavras
    char *mineral1 = strtok(mineral_entrada, " \n");
    char *mineral2 = strtok(NULL, " \n");
    char *mineral3 = strtok(NULL, " \n");

    insere_mineral(nova_rocha->lista.minerais, mineral1);

    /* Verifica e imprime as palavras presentes
    if (nome1 != NULL) {
        printf("Nome 1: %s\n", nome1);
    }
    if (nome2 != NULL) {
        printf("Nome 2: %s\n", nome2);
    }
    if (nome3 != NULL) {
        printf("Nome 3: %s\n", nome3);
    }
    */

    

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

}