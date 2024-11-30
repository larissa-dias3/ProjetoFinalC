#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

//acessando os campos de contato percorrendo a lista de contatos
void listaContatos(t_headerLista *lista){
    //verifica se a lista esta vazia
    if(vazia(lista)){
        printf("\n** Voce nao tem nenhum contato **\n\n");
        return;
    }

    t_elo *tempElo = lista->inicio; // inicia o elo temporário com o início da lista
    int i = 1;

    printf("=== Lista de contatos ===\n\n");
    
    //se nao estiver printa contatos
    while(tempElo != NULL){
        printf("Contato %d\n", i++);

        // não inclui o \n no printf, pois o fgets já inclui ao ler o enter junto com a string
        printf("- Nome: %s", tempElo->contato.nome);
        printf("- Email: %s", tempElo->contato.email);
        printf("- Telefone: %s", tempElo->contato.telefone);
        printf("- CPF: %s", tempElo->contato.cpf);

        // imprime o endereço de memória do elo e os endereços de memória do elo anterior e próximo
        printf("    * Endereco: %p\n", tempElo);
        printf("      - Proximo: %p\n", tempElo->proximo);
        printf("      - Anterior: %p\n\n", tempElo->anterior);

        tempElo = tempElo->proximo;
    }
}

//verifica se lista esta vazia
int vazia(t_headerLista *lista){
    return (lista->inicio == NULL);
}

// inicializa a lista
void inicializar(t_headerLista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

// le contato
void le_contato(t_contato *novo_contato)
{
    printf("Informe o nome do contato: ");
    fgets(novo_contato->nome, 50, stdin);

    printf("Informe o email do contato: ");
    fgets(novo_contato->email, 50, stdin);

    printf("Informe o telefone do contato: ");
    fgets(novo_contato->telefone, 15, stdin);

    printf("Informe o cpf do contato: ");
    fgets(novo_contato->cpf, 15, stdin);
}

//insere um contato na lista
int insereContato(t_headerLista *lista) {
    t_elo *novo_elo = (t_elo*)malloc(sizeof(t_elo)); // aloca espaço para o novo elo

    if (novo_elo == NULL) { // se não conseguir alocar
        return 0;
    }

    t_elo *tempElo;
    t_contato novo_contato;

    le_contato(&novo_contato); // lê o contato
    
    novo_elo->contato = novo_contato; // atribui o contato ao novo elo

    // verificar lista vazia, se sim, insere no início da lista
    if (vazia(lista)) {
        novo_elo->proximo = NULL;
        novo_elo->anterior = NULL;
        lista->inicio = novo_elo; // o início da lista é o novo elo
        lista->fim = novo_elo; // o fim da lista é o novo elo   

        lista->tamanho++; // incrementa o tamanho da lista
        return 1;
    }

    // verifica se o contato já existe na lista
    if (verifica_contato(lista, novo_contato.cpf)) {
        return -1;
    }
    
    // verifica a posição do novo elo na lista com base no cpf
    tempElo = verificaOrdem(lista, novo_contato.cpf);

    // o novo elo é o fim da lista
    if (tempElo == NULL) {
        novo_elo->proximo = NULL; // o próximo do novo elo é nulo
        novo_elo->anterior = lista->fim; // o anterior do novo elo é o fim da lista atual
        lista->fim->proximo = novo_elo; // o próximo do fim da lista atual é o novo elo
        lista->fim = novo_elo; // o fim da lista é o novo elo

        lista->tamanho++; // incrementa o tamanho da lista
        return 1;
    }

    // o novo elo é o início da lista
    if (tempElo->anterior == NULL) {
        novo_elo->proximo = lista->inicio; // o próximo do novo elo é o início da lista atual
        novo_elo->anterior = NULL; // o anterior do novo elo é nulo
        lista->inicio->anterior = novo_elo; // o anterior do início da lista atual é o novo elo
        lista->inicio = novo_elo; // o início da lista é o novo elo

        lista->tamanho++; // incrementa o tamanho da lista
        return 1;
    }

    // o novo elo é inserido no meio da lista na posição correta
    novo_elo->proximo = tempElo; // o próximo do novo elo é o próximo do elo da posição atual
    novo_elo->anterior = tempElo->anterior; // o anterior do novo elo é o anterior do elo da posição atual
    tempElo->anterior->proximo = novo_elo; // o próximo do anterior do elo da posição atual é o novo elo
    tempElo->anterior = novo_elo; // o anterior do elo da posição atual é o novo elo

    lista->tamanho++; // incrementa o tamanho da lista
    return 1;
}

// verifica se o contato já existe na lista
int verifica_contato(t_headerLista *lista, char *cpf) {
    t_elo *tempElo = lista->inicio; // inicia o elo temporário com o início da lista

    while (tempElo != NULL) {
        // se o cpf do contato for igual ao cpf do elo atual, retorna nulo
        if (strcmp(cpf, tempElo->contato.cpf) == 0) {
            return 1;
        }

        tempElo = tempElo->proximo; // altera o elo atual para o próximo elo
    }

    return 0; // caso não encontre o contato, retorna 0
}

// verifica se o contato está em ordem alfabética pelo cpf
t_elo* verificaOrdem(t_headerLista *lista, char *cpf) {
    t_elo *tempElo = lista->inicio; // inicia o elo temporário com o início da lista

    while (tempElo != NULL) {
        // se o cpf do contato for maior que o cpf do elo atual, retorna o elo atual
        if (strcmp(cpf, tempElo->contato.cpf) > 0) {
            return tempElo;
        }

        tempElo = tempElo->proximo; // altera o elo atual para o próximo elo
    }

    return tempElo; // retorna nulo
}

// imprime um contato específico
void imprimeContato(t_headerLista *lista)
{
    //verifica se a lista esta vazia
    if(vazia(lista)) {
        printf("\n** Voce nao tem nenhum contato **\n\n");
        return;
    }    

    int posicao;
    printf("Informe a posicao do contato que deseja consultar (1 a %d): ", lista->tamanho);
    scanf("%d", &posicao);

    //verifica se a posicao é valida
    if(posicao < 1 || posicao > lista->tamanho) {
        printf("\n** Posicao invalida **\n\n");
        return;
    }
    
    t_elo *temp_elo = lista->inicio; // inicia o elo temporário com o início da lista

    // percorre a lista até encontrar a posição correta do elo
    for (int i = 1; i < posicao; i++) {
        temp_elo = temp_elo->proximo;
    }

    printf("Contato\n");
    // não inclui o \n no printf, pois o fgets já inclui ao ler o enter junto com a string
    printf("- Nome: %s", temp_elo->contato.nome);
    printf("- Email: %s", temp_elo->contato.email);
    printf("- Telefone: %s", temp_elo->contato.telefone);
    printf("- CPF: %s\n", temp_elo->contato.cpf); // inclui o \n no printf para pular linha
}

// verifica qual operação foi realizada
void verifica_operacao(int sucesso, int tipo_operacao)
{
    switch (tipo_operacao)
    {
    case INSERIR:
        verifica_insercao(sucesso);
        break;
    case REMOVER:
        verifica_remocao(sucesso);
        break;
    }
}

// verifica se a operação de inserção foi bem sucedida
void verifica_insercao(int sucesso)
{
    if(sucesso == 1){
        printf("\n** Contato inserido com sucesso **\n\n");
    } else if (sucesso == -1) {
        printf("\n** Contato ja existe na lista **\n\n");
    } else {
        printf("\n** Erro ao inserir contato **\n\n");
    }
}

// verifica se a operação de remoção foi bem sucedida
void verifica_remocao(int sucesso)
{
    if(sucesso){
        printf("\n** Contato removido com sucesso **\n\n");
    }
}

// remove um contato da lista
int removeContato(t_headerLista *lista)
{
    //verifica se a lista esta vazia
    if(vazia(lista)) {
        printf("\n** Voce nao tem nenhum contato **\n\n");
        return 0;
    }

    int posicao;
    printf("Informe a posicao do contato que deseja remover (1 a %d): ", lista->tamanho);
    scanf("%d", &posicao);

    //verifica se a posicao é valida
    if(posicao < 1 || posicao > lista->tamanho) {
        printf("\n** Posicao invalida **\n\n");
        return 0;
    }

    t_elo *temp_elo = lista->inicio; // inicia o elo temporário com o início da lista

    // percorre a lista até encontrar a posição correta do elo
    for (int i = 1; i < posicao; i++) {
        temp_elo = temp_elo->proximo;
    }

    // se o elo a ser removido é o início da lista
    if (temp_elo->anterior == NULL) {
        lista->inicio = temp_elo->proximo; // o início da lista é o próximo elo
    } else {
        temp_elo->anterior->proximo = temp_elo->proximo; // o próximo do elo anterior é o próximo do elo atual
    }

    // se o elo a ser removido é o fim da lista
    if (temp_elo->proximo == NULL) {
        lista->fim = temp_elo->anterior; // o fim da lista é o elo anterior
    } else {
        temp_elo->proximo->anterior = temp_elo->anterior; // o anterior do elo próximo é o anterior do elo atual
    }

    free(temp_elo); // libera o espaço de memória do elo removido

    lista->tamanho--; // decrementa o tamanho da lista
    return 1;
}

// esvazia a lista
void esvazia(t_headerLista *lista) {
    //verifica se a lista esta vazia
    if(vazia(lista)) {
        printf("\n** Voce nao tem nenhum contato **\n\n");
        return;
    }

    t_elo *temp_elo = lista->inicio; // inicia o elo temporário com o início da lista
    t_elo *aux_elo; // cria um elo temporário para o próximo elo

    // percorre a lista até o fim
    while (temp_elo != NULL) {
        aux_elo = temp_elo->proximo; // atribui o próximo elo ao elo temporário "próximo_temp_elo"
        free(temp_elo); // libera o espaço de memória do elo atual
        temp_elo = aux_elo; // atribui o próximo elo ao elo temporário
    }

    lista->inicio = NULL; // o início da lista é nulo
    lista->fim = NULL; // o fim da lista é nulo
    lista->tamanho = 0; // o tamanho da lista é 0

    printf("\n** Lista esvaziada com sucesso **\n\n");
}

//mostra menu de iteracoes
void menu(){
    printf("=== Menu ===\n");
    printf("1- Inserir contato\n");
    printf("2- Remover contato\n");
    printf("3- Consultar contato\n");//consulta por indice?
    printf("4- Listar todos os contato\n");
    printf("5- Esvaziar lista de contatos\n");
    printf("6- Sair\n");
}
