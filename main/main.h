#define INSERIR 1 // define a operação de inserção
#define REMOVER 2 // define a operação de remoção

// registro para contato
typedef struct s_contato {
    char nome[50];
    char email[50];
    char telefone[15];
    char cpf[15];
} t_contato;

// elo da lista
typedef struct s_elo {
    t_contato contato;
    struct s_elo* proximo;
    struct s_elo* anterior;
} t_elo;

// lista de contatos
typedef struct s_headerLista {
    struct s_elo* inicio;
    struct s_elo* fim;
    int tamanho;
} t_headerLista;

//inicializa com null as posicoes
void inicializar(t_headerLista* lista);

//verifica se a lista está vazia com boolean
int vazia(t_headerLista* lista);

// le os dados do contato
void le_contato(t_contato *novo_contato);

//insere contatos na lista
int insereContato(t_headerLista *lista);

//imprime um contato especifico
void imprimeContato(t_headerLista *lista);

//mostra todos os contatos
void listaContatos(t_headerLista *lista);

//remove contato
int removeContato(t_headerLista *lista);

//organiza em oredem alfabetica
t_elo* verificaOrdem(t_headerLista *lista, char *cpf);

//verifica se o contato ja existe
int verifica_contato(t_headerLista *lista, char *cpf);

// esvasia a lista
void esvazia(t_headerLista *lista);

// verifica se a operação de inserção foi bem sucedida
void verifica_operacao(int sucesso, int tipo_operacao);
void verifica_insercao(int sucesso);
void verifica_remocao(int sucesso);

//mostra menu de iteracoes
void menu();
