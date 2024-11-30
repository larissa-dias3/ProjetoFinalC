#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

int main(){
    int operacao;
    t_headerLista lista;

    inicializar(&lista);
    do {
        //mostra menu
        menu();
        printf("Informe o numero da operacao que deseja executar: ");
        scanf("%d", &operacao); getchar();
        
        switch (operacao){
            case 1:
                system("clear");
                verifica_operacao(insereContato(&lista), INSERIR);
                break;
            case 2:
                system("clear");
                verifica_operacao(removeContato(&lista), REMOVER);
                break;
            case 3:
                system("clear");
                imprimeContato(&lista);
                break;
            case 4:
                system("clear");
                listaContatos(&lista);
                break;
            case 5:
                system("clear");
                esvazia(&lista);
                break;
            case 6:
                printf("\nSaindo...\n\n");
                break;
            default:    
                break;
            }
    } while(operacao != 6);
     return 0;
}

