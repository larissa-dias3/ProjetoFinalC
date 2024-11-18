#include <stdio.h>
typedef struct {
    char nome[50];
    char email[50];
    char telefone[15];
    char cpf[15];
} contato; //registro pra contato

typedef struct {
    contato contatos;
    struct elo* proximo;
    struct elo* anterior;
} elo; //elo de contato 

typedef struct {
    elo* inicio;
    elo* fim;
    int tamanho;
} lista; // lista de contatos

// Funções
void menu(){
    printf("--Menu de interações--");
    printf("1- Inserir contato");

}
void insereContato(){
    printf("Informe o nome do contato: ");
    // scanf("%d", contato.nome);
}
