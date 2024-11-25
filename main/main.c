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
        insereContato(&lista, contato);
        break;
    
    default:    
        break;
    }
    return 0;
}


int vazia(t_headerLista *lista){
    return (lista->inicio == NULL);
}


//funcoes
void inicializar(t_headerLista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

int insereContato(t_headerLista *lista, t_contato contato) {
    t_elo *novo_elo = (t_elo*) malloc(sizeof(t_elo)); // aloca espaço para o novo elo

    if (novo_elo == NULL) { // se não conseguir alocar
        return 0;
    }

    novo_elo->contato = contato; // atribui o contato ao novo elo
    novo_elo->proximo = NULL; // o próximo do novo elo é nulo
    novo_elo->anterior = lista->fim; // o anterior do novo elo é o fim da lista

    if (vazia(lista)) {
        lista->inicio = novo_elo;
    } else {
        lista->fim->proximo = novo_elo;
    }

    lista->fim = novo_elo;

    lista->tamanho++;

    t_contato novo_contato;

    printf("Informe o nome do contato: ");
    gets(novo_contato.nome);

    printf("Informe o email do contato: ");
    gets(novo_contato.email);

    printf("Informe o telefone do contato: ");
    gets(novo_contato.telefone);

    printf("Informe o cpf do contato: ");
    gets(novo_contato.cpf);

    
    verificaOrdem(&lista, novo_contato);


    

    return 1;
}

// verifica se o contato está em ordem alfabética pelo cpf


void menu(){
    printf("--Agenda--");
    printf("1- Inserir contato");
    printf("2- Remover contato");
    printf("3- Consultar contato");
    printf("4- Listar todos os contato");
    printf("5- Sair");
    printf("-----------");

}
