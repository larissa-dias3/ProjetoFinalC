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

//inicializa com null as posicoes
void inicializar(t_headerLista* lista);
//verifica se a lista está vazia com boolean
int vazia(t_headerLista* lista);
//insere contatos na lista
int insereContato(t_headerLista *lista, t_contato contato, int posicao);
//mostra dados
int imprimeFila(t_headerLista *lista);
//remove contato
int removeContato(t_headerLista *lista, t_contato contato, int posicao);
//mostra menu de iteracoes
void menu();
