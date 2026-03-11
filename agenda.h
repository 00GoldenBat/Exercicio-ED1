#ifndef AGENDA_H
#define AGENDA_H

#define MAX_CONTACTS 100
#define MAX_NAME 129
#define MAX_NUMBER 33
#define MAX_LINHA_ARQUIVO 512

typedef struct{
    char name[MAX_NAME];
    char num[MAX_NUMBER];
} contact;

/**
 * Cria novo contato
 * @param char nome do contato
 * @param char numero do telefone (em char para facilitar formatação)
 * @return contact* struct preenchida
 */
contact* novo_contato(char[], char[]);
/**
 * Exibe os contatos
 * @param contact* para acessar os valores de name e num
 * @param int para numero total de contatos existentes
 */
void exibir_contatos(contact* [], int);
/**
 * Abre o arquivo na função de escrita e salva em formato csv
 * @param const contact* para acessar os dados da struct sem alterar
 * @param total para percorrer o numero total de contatos existentes
 */
void salvar_arquivo(contact* [], int);
/**
 * Abre o arquivo
 * @param contact* para acessar dados da struct
 * @param *total para atualizar os dados na main
 */
void abrir_arquivo(contact *contato[], int *total);

#endif
