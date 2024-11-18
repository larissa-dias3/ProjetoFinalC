#include <stdio.h>
typedef struct {
    char nome[50];
    char email[50];
    char telefone[15];
    char cpf[15];
} contato; //registro pra contato

typedef struct {
    contato *contatos;
    int prox;
    int ant;
} elo; //elo de contato 


// Funções
void menu(){
    printf("--Menu de interações--");
    printf("1- Inserir contato");

}
void insereContato(){
    printf("Informe o nome do contato: ");
    // scanf("%d", contato.nome);
}
