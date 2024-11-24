#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "headers/rocha_mineral.h"

// Inicializar nova rocha
void inicializar_rocha_mineral(RochaMineral *nova_rocha, int novo_id, float novo_peso, Lista_de_minerais *nova_lista, Localizacao nova_localizacao, char *nova_data_coleta){
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
Localizacao get_localizacao(RochaMineral *nova_rocha){
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
void set_localizacao(RochaMineral *nova_rocha, Localizacao nova_localizacao){
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
        else if (strcmp(nova_lista->Lminerais[i].Nome, "Solarium") == 0) {
            Solarium += 1;
        }
        else if (strcmp(nova_lista->Lminerais[i].Nome, "Aquavitae") == 0) {
            Aquavitae += 1;
        }
        else if (strcmp(nova_lista->Lminerais[i].Nome, "Terranita") == 0) {
            Terranita += 1;
        }
        else if (strcmp(nova_lista->Lminerais[i].Nome, "Calaris") == 0) {
            Calaris += 1;
        }
    }

    if (Ferrolita == 1 && Solarium == 0 && Aquavitae == 0 && Terranita == 0 && Calaris == 0) {
    nova_rocha->categoria = Ferrom;
    }
    else if (Ferrolita == 0 && Solarium == 1 && Aquavitae == 0 && Terranita == 0 && Calaris == 0) {
        nova_rocha->categoria = Solaris;
    }
    else if (Ferrolita == 1 && Solarium == 0 && Aquavitae == 1 && Terranita == 0 && Calaris == 0) {
        nova_rocha->categoria = Aquaferro;
    }
    else if (Ferrolita == 0 && Solarium == 0 && Aquavitae == 0 && Terranita == 1 && Calaris == 1) {
        nova_rocha->categoria = Terrolis;
    }
    else if (Ferrolita == 0 && Solarium == 1 && Aquavitae == 0 && Terranita == 1 && Calaris == 0) {
        nova_rocha->categoria = Terrasol;
    }
    else if (Ferrolita == 0 && Solarium == 0 && Aquavitae == 1 && Terranita == 1 && Calaris == 0) {
        nova_rocha->categoria = Aquaterra;
    }
    else if (Ferrolita == 0 && Solarium == 0 && Aquavitae == 1 && Terranita == 0 && Calaris == 1) {
        nova_rocha->categoria = Calquer;
    }
    else if (Ferrolita == 1 && Solarium == 1 && Aquavitae == 0 && Terranita == 0 && Calaris == 0) {
        nova_rocha->categoria = Solarisfer;
    }
    else if (Ferrolita == 1 && Solarium == 0 && Aquavitae == 0 && Terranita == 1 && Calaris == 0) {
        nova_rocha->categoria = Terralis;
    }
    else if (Ferrolita == 1 && Solarium == 0 && Aquavitae == 1 && Terranita == 0 && Calaris == 1) {
        nova_rocha->categoria = Aquacalis;
    }
}

void preencher_rocha_mineral(FILE *arquivo, RochaMineral *nova_rocha){
    int id = 0;
    float peso = 0;
    Localizacao localizacao;
    char data_coleta[255];  // buffer local para armazenar a data
    Lista_de_minerais nova_lista;

    inicializa_lista(&nova_lista);

    char entrada_dados[255];

    id = rand() % 100;

    // Geração da data de coleta
    time_t t = time(NULL);
    struct tm data_hora_atual = *localtime(&t);

    // Ajuste de horário (se necessário)
    if (data_hora_atual.tm_hour < 3) {
        // Subtraindo 3 horas
        data_hora_atual.tm_hour += 24 - 3;
    }

    // Usando snprintf para formatar a data
    snprintf(data_coleta, sizeof(data_coleta), "Dia: %02d, Mes: %02d, Ano: %d, Hora: %02d:%02d:%02d",
             data_hora_atual.tm_mday,              // Dia
             data_hora_atual.tm_mon + 1,           // Mês
             data_hora_atual.tm_year + 1900,       // Ano
             data_hora_atual.tm_hour,              // Hora
             data_hora_atual.tm_min,               // Minutos
             data_hora_atual.tm_sec);              // Segundos

    printf("Insira os dados da rocha: ");
    fgets(entrada_dados, 255, arquivo);  // Lê tudo em uma única linha

    // Remove a quebra de linha, se houver
    size_t len = strlen(entrada_dados);
    if (len > 0 && entrada_dados[len - 1] == '\n') {
        entrada_dados[len - 1] = '\0';
    }

    // Usando strtok para dividir os dados na linha
    char *token = strtok(entrada_dados, " ");
    
    // Lê a localização (latitude e longitude)
    localizacao.Latitude = atof(token);  // Converte para float
    token = strtok(NULL, " ");
    localizacao.Longitude = atof(token);  // Converte para float
    
    // Lê o peso
    token = strtok(NULL, " ");
    peso = atoi(token);  // Converte para int
    
    // Lê os minerais (assumindo até 3 minerais)
    char *mineral1 = strtok(NULL, " ");
    char *mineral2 = strtok(NULL, " ");
    char *mineral3 = strtok(NULL, " ");

    // Verifica se os minerais foram lidos corretamente
    if (mineral1 != NULL) {
        insere_mineral(&nova_lista, mineral1);
    }
    if (mineral2 != NULL) {
        insere_mineral(&nova_lista, mineral2);
    }
    if (mineral3 != NULL) {
        insere_mineral(&nova_lista, mineral3);
    }

    // Inicializa a rocha mineral com os dados
    inicializar_rocha_mineral(nova_rocha, id, peso, &nova_lista, localizacao, data_coleta);
}

void imprimir_rocha_mineral(RochaMineral *nova_rocha){

    char categoria_imprimir[255];

    switch (nova_rocha->categoria)
    {
    case Ferrom:
        strcpy(categoria_imprimir, "Ferrom");
        break;
    case Solaris:
        strcpy(categoria_imprimir, "Solaris");
        break;
    case Aquaferro:
        strcpy(categoria_imprimir, "Aquaferro");
        break;
    case Terrolis:
        strcpy(categoria_imprimir, "Terrolis");
        break;
    case Terrasol:
        strcpy(categoria_imprimir, "Terrasol");
        break;
    case Aquaterra:
        strcpy(categoria_imprimir, "Aquaterra");
        break;
    case Calquer:
        strcpy(categoria_imprimir, "Calquer");
        break;
    case Solarisfer:
        strcpy(categoria_imprimir, "Solarisfer");
        break;
    case Terralis:
        strcpy(categoria_imprimir, "Terralis");
        break;
    case Aquacalis:
        strcpy(categoria_imprimir, "Aquacalis");
        break;
    default: strcpy(categoria_imprimir, "Erro");
        break;
    }
    printf("ID: %d", nova_rocha->id);
    printf("\nCategoria: %s", categoria_imprimir);
    printf("\nPeso: %f", nova_rocha->peso);
    printf("\nLocalizacao: %f %f", nova_rocha->localizacao.Latitude, nova_rocha->localizacao.Longitude);
    printf("\nData da coleta: %s", nova_rocha->data_coleta);
}