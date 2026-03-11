#include "agenda.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Cria novo contato
 * @param char nome do contato
 * @param char numero do telefone (em char para facilitar formatação)
 * @return contact* struct preenchida
 */
contact* novo_contato(char name[MAX_NAME], char num[MAX_NUMBER]){
    contact *novo = malloc(sizeof(contact));
    if (novo != NULL){
        //Copia o nome respeitando o limite do buffer
        strncpy(novo->name, name, MAX_NAME - 1);
        //Garante que a string termine com \0
        novo->name[MAX_NAME - 1] = '\0';
        strncpy(novo->num, num, MAX_NUMBER - 1);
        novo->num[MAX_NUMBER - 1] = '\0';
    }
    return novo;
}
/**
 * Exibe os contatos
 * @param contact* para acessar os valores de name e num
 * @param int para numero total de contatos existentes
 */
void exibir_contatos(contact *contato[], int total){
    //Verifica se existe algum contato
    if (total == 0){
        printf("Agenda vazia\n");
        return;
    }
    //Percorre a memoria e exibe os contatos
    for (int i=0; i<MAX_CONTACTS; i++){
        if(contato[i] != NULL){
            printf("%-15s | %s\n", contato[i]->name, contato[i]->num);
        }
    }
}
/**
 * Abre o arquivo na função de escrita e salva em formato csv
 * @param const contact* para acessar os dados da struct sem alterar
 * @param total para percorrer o numero total de contatos existentes
 */
 void salvar_arquivo(contact *contato[], int total){
     //abre o arquivo na função write
     FILE* arquivo = fopen("contatos.csv", "w");
     if (arquivo == NULL){
         //uso do perror para mais detalhes
         perror("Erro ao salvar o arquivo\n");
         return;
     }
     //loop de escrita no arquivo
     for (int i=0; i<MAX_CONTACTS; i++){ //mesma lógica da exibição
         if (contato[i] != NULL){
             //*lembrar: no csv é comum colocar apenas os dados puros para facilitar leitura posterior
         fprintf(arquivo, "%s;%s\n", contato[i]->name, contato[i]->num);
     }
     }
    //fecha o arquivo
     fclose(arquivo);
     printf("Arquivo salvo com sucesso\n");
 }
/**
 * Abre o arquivo
 * @param contact* para acessar dados da struct
 * @param *total para atualizar os dados na main
 */
 void abrir_arquivo(contact *contato[], int *total){
     FILE* arquivo = fopen("contatos.csv", "r");
     if (arquivo == NULL){
         perror("Erro ao abrir o arquivo\n");
         return;
     }

     char linha[MAX_LINHA_ARQUIVO];
     while(fgets(linha, sizeof(linha), arquivo) != NULL){
         linha[strcspn(linha, "\n")] = '\0';

         char *name = strtok(linha, ";");
         char *num = strtok(NULL, ";");

         if (name && num){
             contato[*total] = novo_contato(name, num);
             (*total)++;
         }
     }
     fclose(arquivo);
 }
