#include <stdio.h>
#include "registro.h"
#include "registro.c"

int main(){

    int opcao = 1;

    while(opcao != -1 ){

       printf("\n");
       printf("Digite a opcao desejada: \n");
       printf("\n");

       // Pedindo ao usuario o que ele quer fazer.

       printf("01 - Inserir aluno no fim. \n02 - Inserir aluno no inicio. \n03 - Inserir aluno em posicao especifica.\n04 - listar todos os alunos\n05 - "
             "Remover aluno. \n-1 - Sair ");
              scanf("%d", &opcao);
              getchar();

        switch(opcao){

            case 1:
                 inserirFim();
                 break;

            case 2:

                 break;

            case 3:

              break;

            case 4:
                listagemTodos();
                break;
            case 5:

                break;
      }
    }
    return 0;
 }

