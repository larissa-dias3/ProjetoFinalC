#include <stdio.h>
#include "main.h"

int main(){
    int operacao;
    t_contato contato; // provalvemente não é aqui que vai ser declarado
    t_headerLista lista;

    inicializar(&lista);
    //mostra menu
    menu();
    printf("Informe o numero da operacao que deseja executar: ");
    scanf("%d", &operacao);

    switch (operacao){
    case 1:
        insereContato(contato);
        break;
    
    default:    
        break;
    }
    return 0;
}
//funcoes
void inicializar (t_headerLista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

int vazia(t_headerLista *lista){
    return (lista->inicio == NULL);
}

int insereContato(t_contato contato){

    printf("Informe o nome do contato: ");
    gets(contato.nome);

    printf("Informe o email do contato: ");
    gets(contato.nome);

    printf("Informe o telefone do contato: ");
    scanf("%s", &contato.telefone);

    printf("Informe o cpf do contato: ");
    scanf("%s", &contato.cpf);

}
void menu(){
    printf("--Menu de interações--");
    printf("1- Inserir contato");
}
