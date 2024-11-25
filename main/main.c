#include <stdio.h>
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
                insereContato(&lista);
                break;
            case 2:
                // removeContato(&lista, contato, posicao);
                break;
            case 3:
                // consultaContato(&lista, contato);
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
    } while(operacao != 5);
     return 0;
}

int listaContatos(t_headerLista *lista){
    printf("Lista de contatos: \n");
    //acessando os campos de contato percorrendo a lista 
    t_elo *acessaElo = lista->inicio;
    //verifica se a lista esta vazia
    if(vazia(lista)){
        printf("Voce nao tem nenhum contato\n");
        return 0;
    }
    
    //se nao estiver printa contatos
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
int insereContato(t_headerLista *lista) {
    t_elo *novo_elo = (t_elo*) malloc(sizeof(t_elo)); // aloca espaço para o novo elo

    if (novo_elo == NULL) { // se não conseguir alocar
        return 0;
    }

    t_contato novo_contato;

    printf("Informe o nome do contato: ");
    fgets(novo_contato.nome, 50, stdin);

    printf("Informe o email do contato: ");
    fgets(novo_contato.email, 50, stdin);

    printf("Informe o telefone do contato: ");
    fgets(novo_contato.telefone, 15, stdin);

    printf("Informe o cpf do contato: ");
    fgets(novo_contato.cpf, 15, stdin);
    
    verificaOrdem(lista, novo_contato);

    novo_elo->contato = novo_contato; // atribui o contato ao novo elo
    novo_elo->proximo = NULL; // o próximo do novo elo é nulo
    novo_elo->anterior = lista->fim; // o anterior do novo elo é o fim da lista

    if (vazia(lista)) {
        lista->inicio = novo_elo;
    } else {
        lista->fim->proximo = novo_elo;
    }

    lista->fim = novo_elo;

    lista->tamanho++;


    return 1;
}

// verifica se o contato está em ordem alfabética pelo cpf
int verificaOrdem(t_headerLista *lista, t_contato contato) {
    // ordenar por cpf de forma decrescente e retornar a lista na ordem correta
    t_elo *acessaElo = lista->inicio;
    while(acessaElo != NULL){
        if (strcmp(acessaElo->contato.cpf, contato.cpf) > 0) {
            // se o cpf do elo atual for maior que o cpf do contato, insere o contato antes do elo atual
            t_elo *novo_elo = (t_elo*) malloc(sizeof(t_elo)); // aloca espaço para o novo elo

            if (novo_elo == NULL) { // se não conseguir alocar
                return 0;
            }

            novo_elo->contato = contato; // atribui o contato ao novo elo
            novo_elo->proximo = acessaElo; // o próximo do novo elo é o elo atual
            novo_elo->anterior = acessaElo->anterior; // o anterior do novo elo é o anterior do elo atual

            if (acessaElo->anterior != NULL) {
                acessaElo->anterior->proximo = novo_elo;
            } else {
                lista->inicio = novo_elo;
            }

            acessaElo->anterior = novo_elo;

            lista->tamanho++;

            return 1;
        }

        acessaElo = acessaElo->proximo;
    }
}

void menu(){
    printf("--Agenda--\n");
    printf("1- Inserir contato\n");
    printf("2- Remover contato\n");
    printf("3- Consultar contato\n");//consulta por indice?
    printf("4- Listar todos os contato\n");
    printf("5- Sair\n");
    printf("-----------\n");

}
