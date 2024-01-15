#ifndef REGISTRO_H
#define REGISTRO_H



typedef struct{

    char nome[50];
    int matricula;
    float notas[7];
    int faltas;
    float media;

}Alunos;

typedef struct {
//  Alunos *alunos;
  int quantAlunos;
  int id;

} turma;

int armazenarDados();
int inserirInicio();
int inserirFim();
int remover();
void listagemTodos();

#endif
