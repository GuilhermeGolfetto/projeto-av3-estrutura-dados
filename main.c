#include "meuh.h"
#define MAX 50

int main(){
    setlocale(LC_ALL, "Portuguese");
	ListaChamados *lista = construirListaLigada();
    int opcao, cont = 0;
    char nomeusuario[30];
    strcpy(nomeusuario, exibirBoasVindas());
    getchar();
    system("cls");
	for( ; ; ){
        printf("Olá "); puts(nomeusuario);
        printf("O Número de chamados na lista: %d\n\n", cont);
        printf("(1) Inserir \n"
               "(2) Encerrar \n"
               "(3) Ajuda \n"
               "(0) Sair \n\n"
               "Selecionado:  ");
        scanf("%d",&opcao);
        if(opcao == 0){
            printf("Saindo do sistema...");
            break;
        }
		switch (opcao){
            case 1:
                system("cls");
                inserirChamados(lista);
                cont++;
                break;
            case 2:
                system("cls");
                if(! estaVaziaListaChamados(lista)){
                    cont = removerListaLigada(lista, cont);
                } else{
                    exibirMensagemListaVazia();
                }
                break;
            case 3:
                exibirAjuda();
                break;
		}
	}
	system("pause>>log");
}

