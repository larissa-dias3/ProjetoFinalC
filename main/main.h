typedef struct {
    char nome[50];
    char email[50];
    char telefone[15];
    char cpf[15];
} t_contato; // registro para contato

typedef struct {
    t_contato contato;
    struct t_elo* proximo;
    struct t_elo* anterior;
} t_elo; // elo da lista

typedef struct {
    t_elo* inicio;
    t_elo* fim;
    int tamanho;
} t_headerLista; // lista de contatos

// Assinaturas funções
void inicializar(t_headerLista* lista);
int vazia(t_headerLista* lista);
void menu();
void insereContato();
