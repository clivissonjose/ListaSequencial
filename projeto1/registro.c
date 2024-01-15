#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "registro.h"


int armazenarDados(Alunos *dados){

    FILE *file = fopen("arquivo_alunos.txt", "a");

    if(file){
        int i=0;
        int tam = 10;
        dados = malloc(sizeof(Alunos)*tam);
        int faltas=0;
        while(fscanf(file,"%d %f %f %f %f %f %f %f %d %f %[^\n]",&dados[i].matricula, &dados[i].notas[0], &dados[i].notas[1],
                      &dados[i].notas[2], &dados[i].notas[3], &dados[i].notas[4], &dados[i].notas[5], &dados[i].notas[6],
                       &dados[i].faltas, &dados[i].media, &dados[i].nome)== 11){
                        i++;
                        if(i > 9){
                           realloc(dados, sizeof(Alunos)*(tam+1));
                        }
                        printf("Teste While\n");
       }

       printf("%d", dados[0].notas[3]);

       return i;
    }else{
       printf("Erro ao abrir arquivo! \n");
       fclose(file);
    }

    fclose(file);
}


int inserirFim(){

   FILE *file = fopen("arquivo_alunos.txt", "a");

   if(file){

       Alunos *dados;

       int pos = armazenarDados(dados);
       fgets(dados[pos].nome, 50, stdin);
       dados[pos].nome[strcspn(dados[pos].nome, "\n")] = '\0';

       printf("Digite a matricula: %d", &dados[pos].matricula);
       getchar();

       int faltas, qtd_faltas, soma=0,i;
       float media;
       printf("Digite a suas notas e faltas nas disciplinas: \n");
       for(i=0;i<7;i++){
         scanf("%f", dados[pos].notas[i]);
         scanf("%d", &faltas);
         faltas = qtd_faltas + faltas;
         soma += dados[pos].notas[i];
       }
       media = soma /  7;

       fprintf(file, "%d %f %f %f %f %f %f %f %d %f %[^\n]",dados[pos].matricula, dados[pos].notas[0], dados[pos].notas[1],
               dados[pos].notas[2], dados[pos].notas[3], dados[pos].notas[4],dados[pos].notas[5],dados[pos].notas[6], qtd_faltas, media, dados[pos].nome);



   }else{

       printf("Erro ao  abrir arquivo!\n");
       return -1;
   }

   return 0;
}

void listagemTodos(){

   FILE *arq = fopen("arquivo_alunos.txt", "r");

   if(arq){
        int matricula, faltas;
        float notas[7], media;
        char nome[50];

        printf("\nLista de Alunos:\n");
        printf("\n");


        while (fscanf(arq,"%d %f %f %f %f %f %f %f %d %f %[^\n]", &matricula,&notas[0], &notas[1],
            &notas[2], &notas[3], &notas[4], &notas[5], &notas[6], &faltas, &media, &nome) != EOF) {


            printf("Matricula: %d\n", matricula);
            printf("Nome: %s\n", nome);
            printf("Media: %.2f\n", media);
            printf("Faltas: %d\n", faltas);
            printf("Notas: %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n\n",notas[0],notas[1],notas[2],notas[3],notas[4],notas[5],notas[6]);

        }

   }else{
       printf("Erro ao abrir arquivo!\n");
        fclose(arq);
   }
  fclose(arq);
}
/*
int listagemTodos(){

    FILE *file = fopen("arquivo_alunos.txt", "r");

    if(file){
      char nome[50];
      float notas[7], media;
      int matricula, faltas;

      while(fscanf(file,"%[^\n] %d %f %f %f %f %f %f %f %d %f", &nome, &matricula,&notas[0], &notas[1],
            &notas[2], &notas[3], &notas[4], &notas[5], &notas[6], &faltas, &media)== 11){

            printf("Nome: %s\n");
            printf("Matricula: %d\n");
            printf("Notas: %f %f %f %f %f %f %f \n", notas[0],notas[1],notas[2],notas[3],notas[4], notas[5], notas[6]);
            printf("Media: %.2f\n", media);
            printf("Faltas: %d\n", faltas);

    }


    }else{

        printf("Erro ao abrir arquivo!\n");
        fclose(file);
        return -1;
    }

    fclose(file);
    return 0;
}
*/
/*
void inserirFim(){

    FILE *file = fopen("arquivo.txt", "a");
    int i, j,quantFaltas = 0;
    float media, soma =0;
    if(file){

        // Array previamente com capacidade para 10 registros, como pedido
         Alunos dados[10];

         for(i=0; i <1;i++){
            printf("Digite o seu nome: \n");
            fgets(dados[i].nome, 50, stdin);
            dados[i].nome[strcspn(dados[i].nome, "\n")] = '\0';
            printf("Digite o numero da matricula: \n");
            scanf("%d", &dados[i].matricula);
            printf("Digite o codigo  da turma: \n");
            scanf("%d", &dados[i].codigo);
            getchar();

            for(j=0; j< 7;j++){
                //scanf("%f", &dados[i].notas[j]);   // valores aleatorias para facilitar o teste
                dados[i].notas[j] = rand() % 10;
                soma += dados[i].notas[j];
                //printf("Digite a quantidade de faltas na %d disciplina  ", j+1);
                //scanf("%d", &dados[i].faltas[j]);
                // getchar();
                 dados[i].faltas[j] = rand() % 10;
                 quantFaltas += dados[i].faltas[j];
            }

            media = soma / 7;
            dados[i].media =  media;
            fprintf(file, " Nome: %s Matricula: %d Codigo da turma: %d Media: %.2f Faltas: %d\n",
            dados[i].nome, dados[i].matricula, dados[i].codigo, dados[i].media, quantFaltas);


         }

         fclose(file);

    }else{
        printf("Erro ao abrir arquivo \n");
    }


}

int inserirInicio(){

    FILE *arquivo = fopen("arquivo.txt", "r+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    Alunos usuarios[10];
    int i = 0;

    // Ler usuarios existentes
    while (fscanf(arquivo,"%s %d %d %.2f %d", usuarios[i].nome, &usuarios[i].matricula, &usuarios[i].codigo, &usuarios[i].media, &usuarios[i].faltas) == 5) {
        i++;
    }

    // Inserir novo usu�rio no in�cio do array
    Alunos novoUsuario;
/*
    printf("Digite o nome do novo usu�rio: ");
    scanf("%s", novoUsuario.nome);
    printf("Digite a idade do novo usu�rio: ");
    scanf("%d", &novoUsuario.idade);
    */ /*

    // Mover usuarios existentes para frente no array
    for (int j = i; i > 0; j--) {
        usuarios[i] = usuarios[j - 1];
    }

    // Inserir novo usuario no inicio do array
    usuarios[0] = novoUsuario;
    i++;

    // Posicionar o ponteiro no in�cio do arquivo
    rewind(arquivo);

    // Escrever usuarios de volta no arquivo
    for (int j = 0; j < i; j++) {
        fprintf(arquivo, "%s %d\n", usuarios[j].nome, usuarios[j].matricula);
    }

    fclose(arquivo);

    return 0;
}



//
void remocao(){}

int listagem(){

    // Abra o arquivo em modo de leitura ("r")
    FILE *arquivo;
    arquivo = fopen("arquivo.txt", "r");

    // Verifique se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1; // Encerre o programa com um código de erro
    }
    int opcao;
    printf("Qual lista voce deseja ver?");
    printf("1 - Todos os alunos.\n");
    printf("2 - Alunos aprovados. \n");
    printf("3 - Alunos reprovados. \n");
    scanf("%d", &opcao);


    // Leia o conteúdo do arquivo e imprima na tela
    char caracter;

    // A função fgetc() lê um caractere por vez até atingir o final do arquivo (EOF)
    while ((caracter = fgetc(arquivo)) != EOF) {
        printf("%c", caracter);
    }

    // Feche o arquivo após a leitura
    fclose(arquivo);

    return 0; // Encerre o programa com sucesso
}

void funcaoTeste(){

    Alunos dados[10];
    FILE *file = fopen("arquivo.txt", "r");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    int i = 0;
    while (fscanf(file, "%s %d %d %f %d", dados[i].nome, &dados[i].matricula, &dados[i].codigo, &dados[i].media, &dados[i].faltas) == 5) {
        i++;
        if (i >= 10) {
            break;  // Avoid reading more than 10 records to prevent buffer overflow
        }
    }

    fclose(file);

    // Print the name of the third student (index 2 in the array)
    printf("Nome 3: %s\n", dados[2].nome);
}

// void arquivoTexto(){}
*/
