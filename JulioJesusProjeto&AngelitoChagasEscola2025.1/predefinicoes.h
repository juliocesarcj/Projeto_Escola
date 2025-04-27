#ifndef PREDEFINICOES_H
#define PREDEFINICOES_H
#include <stdbool.h>
#include <string.h>
#define MAX_ALUNOS_POR_VAGA 45
#define MAX_VAGAS 50
#define MAX_MATRICULAS 1000
#define tam_aluno 100
#define tam_nome 255
#define tam_prof 255
#define MAX_ALUNOS_POR_VAGA 45
#define maxDisciplinas 5
typedef struct {
    int dia_Nasc;
    int mes_Nasc;
    int ano_Nasc;
    int matricula;
    char sexoAluno;
    int ativo;
    char nome[tam_nome];
    char cpf[12];
    int disciplinasMatriculadas[maxDisciplinas];
} dados;

typedef struct {
    int dia_NascProf;
    int mes_NascProf;
    int ano_NascProf;
    int matriculaProf;
    char sexoProf;
    int ativoProf;
    char nomeProf[tam_nome];
    char cpfProf[12];
} dadosProf;

typedef struct {
    char nome[tam_nome];
    int semestre;
    int professor;
    int codigo;
    int ativo;
    int vagas;
    int qtd;
    int vagasOcupadas;
    int totalMatriculas;
    int capacidade;
    int alunosMatriculados[MAX_ALUNOS_POR_VAGA];
    char disciplina[50];
} Disc;

bool validarData(int dia, int mes, int ano);
int menuGeral();

#endif