#include "meuh.h""
Chamado* construirChamado(int id, char nome[], char telefone[], char endereco[], char ocorrencia[]){
	Chamado *novoChamado = malloc( sizeof(Chamado) );
	novoChamado->id = id;
	strcpy(novoChamado->nome,nome);
	strcpy(novoChamado->telefone,telefone);
	strcpy(novoChamado->endereco,endereco);
	strcpy(novoChamado->ocorrencia,ocorrencia);
	return novoChamado;
}

Celula* construirCelula(){
	Celula *celula = malloc( sizeof(Celula) );
	celula->proximo = NULL;
	celula->anterior = NULL;
	return celula;
}

Celula *inserirCelula (Celula *raboCelula, Chamado *chamado) {
	Celula *novaCelula = construirCelula( );
    raboCelula->proximo = novaCelula;
    novaCelula->anterior = raboCelula;
	novaCelula->chamado = chamado;
	return novaCelula;
}


Celula *removerCelula(Celula *cabecaCelula) {
	Celula *cabecaNova = cabecaCelula->proximo;
	if(cabecaNova != NULL){
		cabecaNova->anterior = NULL;
		cabecaCelula->proximo = NULL;
	}
	free (cabecaCelula);
	return cabecaNova;
}


ListaChamados* construirListaLigada(){
	ListaChamados *lista = malloc( sizeof(ListaChamados) );
	lista->cabecaLista = lista->raboLista = NULL;
	lista->tamanho = 0;
	return lista;
}

void inserirChamado (ListaChamados *lista, Chamado *chamado) {
	if(lista->tamanho == 0){
		Celula *celula = construirCelula();
		celula->chamado = chamado;
		lista->cabecaLista = lista->raboLista = celula;
		lista->tamanho = 1;
	}else{
		lista->tamanho += 1;
		lista->raboLista = inserirCelula(lista->raboLista, chamado);
	}
}

int estaVaziaListaChamados(ListaChamados *lista){
	return lista->tamanho == 0;
}

int removerListaLigada(ListaChamados *lista, int cont) {
	Chamado *chamado = NULL;
	if(! estaVaziaListaChamados(lista) ){
		chamado = lista->cabecaLista->chamado;
		int opcao;
        printf("Chamado número: %d será removido, deseja confirmar? [1/0]:",chamado->id);
        fflush(stdin);
        scanf("%d",&opcao);
        if(opcao == 1){
            lista->cabecaLista = removerCelula(lista->cabecaLista);
            lista->tamanho -= 1;
            cont--;
        } else{
            printf("Voltando para o Sistema...\n");
        }
	}
	system("cls");
    return cont;
}

void inserirChamados (ListaChamados* lista){
    int id;
    char nome[30], telefone[15], endereco[50],ocorrencia[100];
    printf("Digite o Id do chamado: ");
    scanf("%d", &id);
    getchar();
    printf("\nDigite o nome do cliente: ");
    gets(nome);
    printf("Digite o telefone do cliente: ");
    gets(telefone);
    printf("Digite o endereco do cliente: ");
    gets(endereco);
    printf("Digite a ocorrencia: ");
    gets(ocorrencia);
    Chamado *obj = construirChamado(id, nome, telefone, endereco, ocorrencia);
    inserirChamado(lista, obj);
    printf("\n");
    printf("** Confirme as informacoes e aperte Enter **");
    fflush(stdin);
    getchar();
    system("cls");
}
