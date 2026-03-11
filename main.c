#include "agenda.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    contact *agenda[MAX_CONTACTS] = {NULL};
    char name[MAX_NAME], num[MAX_NUMBER];
    int total = 0;

    abrir_arquivo(agenda, &total);

    int opcaomenu;
    char opcaostr[10];

    do {
        printf("\n--- Agenda de contatos ---\n");
        printf("1. Novo contato\n");
        printf("2. Exibir contatos\n");
        printf("3. Sair\n");
        printf("-------------------------------------\n");
        printf("Escolha uma opcao: ");

        fgets(opcaostr, sizeof(opcaostr), stdin);
        opcaostr[strcspn(opcaostr, "\n")] = '\0';
        opcaomenu = atoi(opcaostr);

        switch (opcaomenu){
            case 1:
                printf("Nome: ");
                fgets(name, MAX_NAME, stdin);
                name[strcspn(name, "\n")] = '\0';

                printf("Numero: ");
                fgets(num, MAX_NUMBER, stdin);
                num[strcspn(num, "\n")] = '\0';

                if (total < MAX_CONTACTS) {
                agenda[total] = novo_contato(name, num);
                if (agenda[total] != NULL) {
                    total++;
                    printf("contato adicionado com sucesso\n");
                }
                }
                break;

            case 2:
            exibir_contatos(agenda, total);
            break;

            case 3:
            printf("encerrando o programa, salvando modificações...\n");
            salvar_arquivo(agenda, total);
            break;
        }
    } while (opcaomenu != 3);
    return 0;
}
