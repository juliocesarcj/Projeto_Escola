#ifndef ALUNO_H
#define ALUNO_H

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "predefinicoes.h"

int menuAluno();
int cadastrarAluno(dados listaAluno[], int qtdAluno);
int atualizarAluno(dados listaAluno[], int qtdAluno);
int excluir_Aluno(dados listaAluno[], int qtdAluno);
int contarDisciplinasPorAluno(Disc listaDisc[], int qtdDisc, int matriculaAluno);

bool validar_cpf(dados aluno);

void adicionarAlunoDisciplina(dados listaAluno[], int qtdAluno, Disc listaDisc[], int qtdDisc);
void pesquisa_aluno(dados listaAluno[], int qtdAluno);
void listar(dados listaAluno[], int qtdAluno);
void listarAlunosPoucasDisciplinas(dados listaAluno[], Disc listaDisc[], int qtdAluno, int qtdDisc);
void pesquisa_aluno(dados listaAluno[], int qtdAluno);
void listarAlunosPorSexo(dados listaAluno[], int qtdAluno, char sexo);
void listarAlunosOrdenadosPorNome(dados listaAluno[], int qtdAluno);
void listarAlunosOrdenadosPorDataNascimento(dados listaAluno[], int qtdAluno);
#endif