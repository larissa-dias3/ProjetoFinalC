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
void inicializar(t_headerLista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

int vazia(t_headerLista *lista){
    return (lista->inicio == NULL);
}

void insereContato(t_headerLista *fila, t_contato contato){
    t_elo *novo_elo = (t_elo*) malloc(sizeof(t_elo)); // aloca espaço para o novo elo

    if (novo_elo == NULL) { // se não conseguir alocar
        return 0;
    }

    // t_contato novo_contato;

    // printf("Informe o nome do contato: ");
    // gets(novo_contato.nome);

    // printf("Informe o email do contato: ");
    // gets(novo_contato.email);

    // printf("Informe o telefone do contato: ");
    // gets(novo_contato.telefone);

    // printf("Informe o cpf do contato: ");
    // gets(novo_contato.cpf);

    novo_elo->contato = contato;
    novo_elo->anterior = fila->fim;
    

    return 1;
}
void menu(){
    printf("--Menu de interações--");
    printf("1- Inserir contato");
}
