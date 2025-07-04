#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "predefinicoes.h"

int menuProf();
bool validar_cpf_prof(dadosProf Prof);
bool todos_iguais_prof(char cpfProf[12]);
void buscarPorNomeProfessores(dadosProf listaProf[], int qtdProf);
void listarAniversariantesDoMes(dadosProf listaProf[], int qtdProf, int mes);
void buscarPorNomeProfessores(dadosProf listaProf[], int qtdProf);
int cadastrarProf(dadosProf listaProf[], int qtdProf);
void lista_de_Prof(dadosProf listaProf[], int qtdProf);
int atualizarProf(dadosProf listaProf[], int qtdProf);
int excluir_Prof(dadosProf listaProf[], int qtdProf);
void listarProfessoresPorSexo(dadosProf listaProf[], int qtdProf, char sexo);
void listarProfessoresOrdenadosPorDataNascimento(dadosProf listaProf[], int qtdProf);

#endif