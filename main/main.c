#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(){
    int posicao;//precisa?
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
    case 2:
        removeContato(&lista, contato, posicao);
        break;
    case 3:
        consultaContato(&lista, contato);
        break;
    case 4:
        listaContatos(&lista);
        break;
    case 5:
        printf("Saindo...");
        break;
    default:    
        break;
    }
     return 0;
}
int listaContatos(t_headerLista *lista){
    printf("Lista de contatos: ");
    //acessando os campos de contato percorrendo a lista 
    t_elo *acessaElo = lista->inicio;
    while(acessaElo != NULL){
        printf("Nome: %s\n", acessaElo->contato.nome);
        printf("Email: %s\n", acessaElo->contato.email);
        printf("Telefone: %s\n", acessaElo->contato.telefone);
        printf("CPF: %s\n", acessaElo->contato.cpf);
       acessaElo = acessaElo->proximo;
    }

    return 1;

}
//verifica se lista esta vazia
int vazia(t_headerLista *lista){
    return (lista->inicio == NULL);
}


//funcoes
void inicializar(t_headerLista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

//insere um contato na lista
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
    fgets(novo_contato.nome, 50, stdin);

    printf("Informe o email do contato: ");
    fgets(novo_contato.email, 50, stdin);

    printf("Informe o telefone do contato: ");
    fgets(novo_contato.telefone, 15, stdin);

    printf("Informe o cpf do contato: ");
    fgets(novo_contato.cpf, 15, stdin);

    
    // verificaOrdem(&lista, novo_contato);

    return 1;
}

// verifica se o contato está em ordem alfabética pelo cpf


void menu(){
    printf("--Agenda--\n");
    printf("1- Inserir contato\n");
    printf("2- Remover contato\n");
    printf("3- Consultar contato\n");//consulta por indice?
    printf("4- Listar todos os contato\n");
    printf("5- Sair\n");
    printf("-----------\n");

}
