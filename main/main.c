#include <stdio.h>
#include "main.h"

int main(){
    int operacao;
    contato c;
    headerLista lista;

    inicializar(&lista);
    //mostra menu
    menu();
    printf("Informe o numero da operacao que deseja executar: ");
    scanf("%d", &operacao);

    switch (operacao){
    case 1:
        insereContato(c);
        break;
    
    default:    
        break;
    }
    return 0;
}
//funcoes
void inicializar (headerLista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}
void insereContato(contato c){

    printf("Informe o nome do contato: ");
    gets(c.nome);

    printf("Informe o email do contato: ");
    gets(c.nome);

    printf("Informe o telefone do contato: ");
    scanf("%s", &contato.telefone);

    printf("Informe o cpf do contato: ");
    scanf("%s", &contato.cpf);

}
void menu(){
    printf("--Menu de interações--");
    printf("1- Inserir contato");
}
