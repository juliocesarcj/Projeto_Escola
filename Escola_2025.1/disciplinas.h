#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include <stdbool.h>
#include <string.h>
#include "predefinicoes.h"

#define cad_disc_sucesso -14
#define codigo_disc_invalido -15
#define lista_disc_cheia -16
#define atualizacao_disc_sucesso -17
#define codigo_disc_inexistente -18
#define exclusao_disc_sucesso -19

int menuDisciplina();
void listarDisciplinatoda(int qtdDisc, Disc listaDisc[], int qtdAluno, dados listaAluno[], dadosProf listaProf[]);
int cadastrar_disciplina(Disc listaDisc[], int qtdDisc, dadosProf listaProf[], int qtdProf);
int listarDisc(Disc listaDisc[], int qtdDisc, dadosProf listaProf[], int qtdProf);
int atualizarDisc(Disc listaDisc[], int qtdDisc);
int excluir_disciplina(Disc listaDisc[], int qtdDisc);

#endif