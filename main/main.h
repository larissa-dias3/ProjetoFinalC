typedef struct {
    char nome[50];
    char email[50];
    char telefone[15];
    char cpf[15];
} t_contato; // registro para contato

typedef struct s_elo {
    t_contato contato;
    struct s_elo* proximo;
    struct s_elo* anterior;
} t_elo; // elo da lista

typedef struct {
    struct s_elo* inicio;
    struct s_elo* fim;
    int tamanho;
} t_headerLista; // lista de contatos

// Assinaturas funções

//inicializa com null as posicoes
void inicializar(t_headerLista* lista);

//verifica se a lista está vazia com boolean
int vazia(t_headerLista* lista);

//insere contatos na lista
int insereContato(t_headerLista *lista);

//imprime um contato especifico
int imprimeContato(t_headerLista *lista);

//mostra todos os contatos
int listaContatos();

//remove contato
int removeContato(t_headerLista *lista, t_contato contato, int posicao);

//organiza em oredem alfabetica
// int verificaOrdem(t_headerLista *lista, t_contato contato);

//mostra menu de iteracoes
void menu();
