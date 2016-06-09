typedef struct {
	int id;
	char nome[30], telefone[15], endereco[50], ocorrencia[100];
}Chamado;

typedef struct{
	Chamado *chamado;
	struct EstruturaCelula *proximo;
	struct EstruturaCelula *anterior;
}Celula;

typedef struct{
	int tamanho;
	Celula *cabecaLista;
	Celula *raboLista;
}ListaChamados;

Chamado* construirChamado(int id, char nome[], char telefone[], char endereco[], char ocorrencia[]);

Celula* construirCelula();

Celula *inserirCelula (Celula *raboCelula, Chamado *chamado);

Celula *removerCelula(Celula *cabecaCelula);

ListaChamados* construirListaLigada();

void inserirChamado (ListaChamados *lista, Chamado *chamado);

int estaVaziaListaChamados(ListaChamados *lista);

int removerListaLigada(ListaChamados *lista, int cont) ;

void inserirChamados (ListaChamados* lista);

