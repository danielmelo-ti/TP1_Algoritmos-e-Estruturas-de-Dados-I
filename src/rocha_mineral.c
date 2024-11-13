#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> // Necessária para utilizar o português no código
#include <time.h> // Necessária para puxar data e hora atuais para o código

#include "mineral.h"
#include "rocha_mineral.h"
#include "lista_minerais.h"

setlocale(LC_ALL, "pt_BR.UTF-8"); // Configura o programa para usar a localidade portuguesa

// Inicializar nova rocha
void inicializar_rocha_mineral(RochaMineral *nova_rocha, int novo_id, float novo_peso, ListaMinerais nova_lista, Categoria nova_categoria, float nova_localizacao, char *nova_data_coleta){
    set_id(nova_rocha, novo_id);
    set_peso(nova_rocha, novo_peso);
    set_lista(nova_rocha, nova_lista);
    set_categoria(nova_rocha, nova_categoria);
    set_localizacao(nova_rocha, nova_localizacao);
    set_data_coleta(nova_rocha, nova_data_coleta);
}

// Início dos gets
char get_id(RochaMineral *nova_rocha){
    return(nova_rocha->id);
}
float get_peso(RochaMineral *nova_rocha){
    return(nova_rocha->peso);
}
ListaMinerais get_lista(RochaMineral *nova_rocha){
    return(nova_rocha->lista);
}
Categoria get_categoria(RochaMineral *nova_rocha){
    return(nova_rocha->categoria);
}
float get_localizacao(RochaMineral *nova_rocha){
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
void set_lista(RochaMineral *nova_rocha, ListaMinerais nova_lista){
    nova_rocha->lista = nova_lista;
}
void set_categoria(RochaMineral *nova_rocha, Categoria nova_categoria){
    nova_rocha->categoria = nova_categoria;
}
void set_localizacao(RochaMineral *nova_rocha, float nova_localizacao){
    nova_rocha->localizacao = nova_localizacao;
}
void set_data_coleta(RochaMineral *nova_rocha, char *nova_data_coleta){
    nova_rocha->data_coleta = nova_data_coleta;
}
// Fim dos sets 

// Função para preencher as informações do TAD RochaMineral
void preencher_rocha_mineral(RochaMineral *nova_rocha){
    float localizacao[2];

    float peso;

    char total_minerais[255];
    int Ferrolita = 0, Solarium = 0, Aquavitae = 0, Terranita = 0, Calaris = 0;

    srand(time(NULL)); //usado para que o código veja o horário do pc e 
    int id = rand() % 100;

    ListaMinerais lista;

    char data_coleta[255];

    printf("O ID da rocha mineral é: %d", id);
    printf("Insira a latitude e a longitude: ");
    scanf("%f %f", &localizacao[0], &localizacao[1]);
    printf("Insira o peso da rocha mineral: ");
    scanf("%f", &peso);
    printf("Insira os minerais presentes na rocha: ");

    /* colocar aqui o scanf para pegar os minerais e mandalos para a lista presente no TAD RochaMineral */

    for (int i = 0; i < 3; i++) {
        if (scanf("%19s", nova_rocha->lista[i]) == EOF) break;
    }

    for (int i = 0; i < 3; i++){
        if (strcmp(nova_rocha->lista[i], "Ferrolita") == 0){
            Ferrolita += 1;
        }
        if (strcmp(nova_rocha->lista[i], "Solarium") == 0){
            Solarium += 1;
        }
        if (strcmp(nova_rocha->lista[i], "Aquavitae") == 0){
            Aquavitae += 1;
        }
        if (strcmp(nova_rocha->lista[i], "Terranita") == 0){
            Terranita += 1;
        }
        if (strcmp(nova_rocha->lista[i], "Calaris") == 0){
            Calaris += 1;
        }
    }

    if (Ferrolita && !Solarium && !Aquavitae && !Terranita && !Calaris){
        strcpy(nova_rocha->categoria, "Ferrom");
    }
    if (Solarium && !Ferrolita && !Aquavitae && !Terranita && !Calaris){
        strcpy(nova_rocha->categoria, "Solaris");
    }
    if (Ferrolita && Aquavitae && !Solarium && !Terranita && !Calaris){
        strcpy(nova_rocha->categoria, "Aquaferro");
    }
    if (Terranita && Calaris && !Ferrolita && !Aquavitae && !Solarium){
        strcpy(nova_rocha->categoria, "Terrolis");
    }
    if (Terranita && Solarium && !Ferrolita && !Aquavitae && !Calaris){
        strcpy(nova_rocha->categoria, "Terrasol");
    }
    if (Aquavitae && Terranita && !Ferrolita && !Solarium && !Calaris){
        strcpy(nova_rocha->categoria, "Aquaterra");
    }
    if (Calaris && Aquavitae && !Ferrolita && !Solarium && !Terranita){
        strcpy(nova_rocha->categoria, "Calquer");
    }
    if (Solarium && Ferrolita && !Aquavitae && !Terranita && !Calaris){
        strcpy(nova_rocha->categoria, "Solarisfer");
    }
    if (Terranita && Ferrolita && !Aquavitae && !Solarium && !Calaris){
        strcpy(nova_rocha->categoria, "Terralis");
    }
    if (Aquavitae && Calaris && Ferrolita){
        strcpy(nova_rocha->categoria, "Aquacalis");
    }


    // Usado para definir data e hora que a rocha foi encontrada
    time_t t = time(NULL);
    struct tm *data_hora_atual = localtime(&t);

    if (data_hora_atual->tm_hour - 3 < 0) {
        int aux = data_hora_atual->tm_hour;
        data_hora_atual->tm_hour = 24 + aux - 3;
    }

    sprintf(data_coleta, "Dia: %02d, Mês: %02d, Ano: %d, Hora: %02d:%02d:%02d", data_hora_atual->tm_mday - 1, 
            data_hora_atual->tm_mon + 1, data_hora_atual->tm_year + 1900, data_hora_atual->tm_hour, 
            data_hora_atual->tm_min, data_hora_atual->tm_sec);

    inicializar_rocha_mineral(nova_rocha,/*colocar outras infos*/);
}

void imprimir_rocha_mineral(RochaMineral *nova_rocha){
    printf("ID: %d\n", nova_rocha->id);
    printf("PESO: %s\n", get_peso(nova_rocha));
    printf("LISTA: %s\n", get_lista(nova_rocha));
    printf("CATEGORIA: %s\n", get_categoria(nova_rocha));
    printf("LOCALIZACAO: %d", get_localizacao(nova_rocha));
    printf("DATA DA COLETA: %d", get_data_coleta(nova_rocha));
}