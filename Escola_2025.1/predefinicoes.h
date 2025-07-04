#ifndef PREDEFINICOES_H
#define PREDEFINICOES_H
#include <stdbool.h>
#include <string.h>
// ===== LIMITES GERAIS =====
#define MAX_VAGAS 50
#define MAX_MATRICULAS 1000
#define MAX_ALUNOS_POR_VAGA 45
#define MAX_ALUNOS 90
#define MAX_DISCIPLINAS 20
#define MAX_DISCIPLINAS_POR_ALUNO 5  // antigo: maxDisciplinas

// ===== TAMANHOS DE STRINGS =====
#define TAM_ALUNO 100
#define TAM_NOME 255
#define TAM_PROF 255

// ===== CÓDIGOS DE RETORNO - ALUNO =====
#define CADASTRO_ALUNO_SUCESSO         -1
#define MATRICULA_ALUNO_INVALIDA       -2
#define LISTA_ALUNO_CHEIA              -3
#define ATUALIZACAO_ALUNO_SUCESSO      -4
#define MATRICULA_ALUNO_INEXISTENTE    -5
#define EXCLUSAO_ALUNO_SUCESSO         -6
#define CPF_INVALIDO                   -15
#define LISTA_CHEIA_ALUNO              -25
#define EXCLUSAO_ALUNO                 -27
#define MATRICULA_SUCESSO              -37
#define TURMA_LOTADA                   -38
#define ALUNO_NAO_ENCONTRADO           -42
#define ALUNO_JA_MATRICULADO           -43
#define lista_Cheia_aluno -40


// ===== CÓDIGOS DE RETORNO - DISCIPLINA =====
#define CADASTRO_DISCIPLINA_SUCESSO    -14
#define CODIGO_DISCIPLINA_INVALIDO     -15
#define LISTA_DISCIPLINA_CHEIA         -16
#define ATUALIZACAO_DISCIPLINA_SUCESSO -17
#define CODIGO_DISCIPLINA_INEXISTENTE  -18
#define EXCLUSAO_DISCIPLINA_SUCESSO    -19
#define ATUALIZACAO_DISCIPLINA_DUPLO   -21
#define DISCIPLINA_INEXISTENTE         -22
#define EXCLUSAO_DISCIPLINA            -23
#define DISCIPLINA_NAO_ENCONTRADA      -44

// ===== CÓDIGOS DE RETORNO - PROFESSOR =====
#define CADASTRO_PROFESSOR_SUCESSO     -7
#define MATRICULA_PROFESSOR_INVALIDA   -8
#define LISTA_PROFESSOR_CHEIA          -9
#define ATUALIZACAO_PROFESSOR_SUCESSO  -10
#define MATRICULA_PROFESSOR_INEXISTENTE -11
#define EXCLUSAO_PROFESSOR_SUCESSO     -12
#define CPF_PROFESSOR_INVALIDO         -13
#define EXCLUSAO_PROFESSOR             -33
#define PROFESSOR_INEXISTENTE          -24

// ===== CÓDIGOS DE ERRO GERAIS =====
#define MATRICULA_INVALIDA            -30
#define MATRICULA_INEXISTENTE            -39


typedef struct {
    int dia_Nasc;
    int mes_Nasc;
    int ano_Nasc;
    int matricula;
    char sexoAluno;
    int ativo;
    char nome[TAM_NOME];
    char cpf[12];
    int disciplinasMatriculadas[MAX_DISCIPLINAS];
} dados;

typedef struct {
    int dia_NascProf;
    int mes_NascProf;
    int ano_NascProf;
    int matriculaProf;
    char sexoProf;
    int ativoProf;
    char nomeProf[TAM_NOME];
    char cpfProf[12];
} dadosProf;

typedef struct {
    char nome[TAM_NOME];
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