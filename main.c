#include <stdio.h>
#include "main.h"

int main(){
    int operacao;
    //mostra menu
    menu();
    printf("Informe o numero da operacao que deseja executar: ");
    scanf("%d", &operacao);

    switch (operacao){
    case 1:
        insereContato();
        break;
    
    default:    
        break;
    }
    return 0;
}
//funcoes
void insereContato(){
    printf("Informe o nome do contato: ");
    
}
void menu(){
    printf("--Menu de interações--");
    printf("1- Inserir contato");
}
