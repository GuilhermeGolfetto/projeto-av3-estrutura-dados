#include "meuh.h"

void exibirAjuda(){
    system("cls");
    printf("Opcao 1 Inserir:\n"
           "nessa opcao tem que digitar os seguintes termos:\n\n"
           "Id: s� podera digitar n�mero\n\n"
           "Nome: Nome do cliente que esta solicitando o chamado\n\n"
           "Telefone: Telefone para entrar em contato com cliente\n\n"
           "Endere�o: Endere�o para que se nao poder resolver pelo telefone encaminhar para um tecnico de campo\n\n"
           "Descri��o: Descri��o da ocorrencia o motivo que o chamado foi aberto\n\n"
    );
   fflush(stdin);
   getchar();
    printf("\n\nOpcao 2 Encerrar\n\n"
           "nessa op��o retira o chamado da fila apois o atendimento concluido\n\n"
           );
   fflush(stdin);
   getchar();
   system("cls");
}
void exibirMensagemListaVazia(){
    printf("A lista de chamados j� est� vazia, precione qualquer tecla para voltar");
    fflush(stdin);
    getchar();
    system("cls");
}

char * exibirBoasVindas(){
    char nomeUsuario[30];
    printf("Bem vindo ao sistema de Atendimento \nDigite seu nome:");
    gets(nomeUsuario);
    printf("\n\nComecaremos os atendimentos para voc�, ");
    puts(nomeUsuario);
    printf("\n\nPrecione qualquer tecla para continuar\n");
    return nomeUsuario;
}
