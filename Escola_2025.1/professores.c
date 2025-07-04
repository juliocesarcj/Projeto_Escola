#include <stdio.h>
#include "professores.h"
#include "predefinicoes.h"
#include <stdbool.h>
#include <ctype.h>
#include "aluno.h"
int menuProf() {
    int opcaoProf;
    printf("0 - Exit\t\n1 - Cadastrar professor\t\n2 - Listar professor\t\n3 - Atualizar professor\t\n4 - Excluir professor\t\n5 - Aniversariante do mes\n");
    scanf("%d", &opcaoProf);
    return opcaoProf;
}

int cadastrarProf(dadosProf listaProf[], int qtdProf) {
    printf("Cadastrar Professor\n");
    if (qtdProf == TAM_PROF) {
        return LISTA_PROFESSOR_CHEIA;
    }

    int matriculaProf;
    printf("Digite a matricula: \n");
    scanf("%d", &matriculaProf);

    if (matriculaProf < 0) {
        return MATRICULA_PROFESSOR_INVALIDA;
    }
    while (getchar() != '\n');
    listaProf[qtdProf].matriculaProf = matriculaProf;
    listaProf[qtdProf].ativoProf = 1;


    printf("o nome do Professor: \n");
    fgets(listaProf[qtdProf].nomeProf, 250, stdin);

    printf("o cpf do professor: \n");
    fgets(listaProf[qtdProf].cpfProf, 12, stdin);

    printf("Digite o sexo (M/F): \n");
    scanf(" %c", &listaProf[qtdProf].sexoProf);

    printf("Digite o dia de nascimento: \n");
    scanf("%d", &listaProf[qtdProf].dia_NascProf);

    printf("Digite o mes de nascimento: \n");
    scanf("%d", &listaProf[qtdProf].mes_NascProf);

    printf("Digite o ano de nascimento: \n");
    scanf("%d", &listaProf[qtdProf].ano_NascProf);

    if (!validarData(listaProf[qtdProf].dia_NascProf, listaProf[qtdProf].mes_NascProf, listaProf[qtdProf].ano_NascProf)) {
        printf("Data de nascimento invalida!\n");
        return MATRICULA_INVALIDA;
    }

    return CADASTRO_PROFESSOR_SUCESSO;
}

void lista_de_Prof(dadosProf listaProf[], int qtdProf) {
    printf("Listar Professor\n");
    if (qtdProf == 0) {
        printf("Lista de professores vazia\n");
    } else {
        for (int i = 0; i < qtdProf; i++) {
            if (listaProf[i].ativoProf) {
                printf("Matricula: %d\n", listaProf[i].matriculaProf);
                printf("nome: %s", listaProf[i].nomeProf);
                printf("CPF: ");
                for (int j = 0; j < 11; j++) {
                    printf("%c", listaProf[i].cpfProf[j]);
                }
                printf("\n");
                printf("Sexo: %c\n", listaProf[i].sexoProf);
                printf("Data de Nascimento: %02d/%02d/%04d\n", listaProf[i].dia_NascProf, listaProf[i].mes_NascProf, listaProf[i].ano_NascProf);
                printf("-------------\n");
            }
        }
    }
}

int atualizarProf(dadosProf listaProf[], int qtdProf) {
    printf("Atualizar Professor\n");
    printf("Digite a matricula: \n");
    int matriculaProf;
    scanf("%d", &matriculaProf);

    if (matriculaProf < 0) {
        return MATRICULA_INVALIDA;
    }

    for (int i = 0; i < qtdProf; i++) {
        if (listaProf[i].matriculaProf == matriculaProf && listaProf[i].ativoProf) {
            printf("Digite a nova matricula: \n");
            int novaMatriculaProf;
            scanf("%d", &novaMatriculaProf);

            if (novaMatriculaProf < 0) {
                return MATRICULA_INVALIDA;
            }

            listaProf[i].matriculaProf = novaMatriculaProf;
            return CADASTRO_ALUNO_SUCESSO;
        }
    }

    return MATRICULA_INEXISTENTE;
}

int excluir_Prof(dadosProf listaProf[], int qtdProf) {
    printf("Excluir Professor\n");
    printf("Digite a matricula: \n");
    int matriculaProf;
    scanf("%d", &matriculaProf);

    if (matriculaProf < 0) {
        return MATRICULA_INVALIDA;
    }

    for (int i = 0; i < qtdProf; i++) {
        if (listaProf[i].matriculaProf == matriculaProf && listaProf[i].ativoProf) {
            listaProf[i].ativoProf = 0;
            return EXCLUSAO_PROFESSOR;
        }
    }

    return MATRICULA_INEXISTENTE;
}

void listarProfessoresPorSexo(dadosProf listaProf[], int qtdProf, char sexo) {
    printf("Listar Professores por Sexo (%c)\n", sexo);
    for (int i = 0; i < qtdProf; i++) {
        if (listaProf[i].ativoProf && listaProf[i].sexoProf == sexo) {
            printf("Matricula: %d\n", listaProf[i].matriculaProf);
            printf("Nome: %s\n", listaProf[i].nomeProf);
            printf("Sexo: %c\n", listaProf[i].sexoProf);
            printf("Data de Nascimento: %02d/%02d/%04d\n", listaProf[i].dia_NascProf, listaProf[i].mes_NascProf, listaProf[i].ano_NascProf);
            printf("-------------\n");
        }
    }
}

void listarProfessoresOrdenadosPorNome(dadosProf listaProf[], int qtdProf) {
    printf("Listar Professores Ordenados por Nome\n");
    for (int i = 0; i < qtdProf - 1; i++) {
        for (int j = 0; j < qtdProf - i - 1; j++) {
            if (strcmp(listaProf[j].nomeProf, listaProf[j + 1].nomeProf) > 0) {
                dadosProf temp = listaProf[j];
                listaProf[j] = listaProf[j + 1];
                listaProf[j + 1] = temp;
            }
        }
    }
    lista_de_Prof(listaProf, qtdProf);
}

void listarProfessoresOrdenadosPorDataNascimento(dadosProf listaProf[], int qtdProf) {
    printf("Listar Professores Ordenados por Data de Nascimento\n");
    for (int i = 0; i < qtdProf - 1; i++) {
        for (int j = 0; j < qtdProf - i - 1; j++) {
            if (listaProf[j].ano_NascProf > listaProf[j + 1].ano_NascProf ||
                (listaProf[j].ano_NascProf == listaProf[j + 1].ano_NascProf && listaProf[j].mes_NascProf > listaProf[j + 1].mes_NascProf) ||
                (listaProf[j].ano_NascProf == listaProf[j + 1].ano_NascProf && listaProf[j].mes_NascProf == listaProf[j + 1].mes_NascProf && listaProf[j].dia_NascProf > listaProf[j + 1].dia_NascProf)) {
                    dadosProf temp = listaProf[j];
                listaProf[j] = listaProf[j + 1];
                listaProf[j + 1] = temp;
            }
        }
    }
    lista_de_Prof(listaProf, qtdProf);
}
bool validar_cpf_prof(dadosProf Prof) {
    char cpf[12];
    strcpy(cpf, Prof.cpfProf);
    int soma, resto, digito1, digito2;

    if (strlen(cpf) != 11 || todos_iguais_prof(cpf)) {
        return false;
    }

    soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }
    resto = soma % 11;
    
    if (resto < 2) {
        digito1 = 0;
    } else {
        digito1 = 11 - resto;
    }

    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }
    resto = soma % 11;
    
    if (resto < 2) {
        digito2 = 0;
    } else {
        digito2 = 11 - resto;
    }

    if (digito1 != (cpf[9] - '0')) {
        return false;
    }
    
    if (digito2 != (cpf[10] - '0')) {
        return false;
    }
    
    return true;
}

bool todos_iguais_prof(char cpfProf[12]) {
    for (int i = 1; i < 11; i++) {
        if (cpfProf[i] != cpfProf[0]) {
            return false;
        }
    }
    return true;
}
void listarAniversariantesDoMes(dadosProf listaProf[], int qtdProf, int mes) {
    if(mes < 1 || mes > 12) {
        printf("Mês inválido! Digite um valor entre 1 e 12.\n");
        return;
    }

    printf("\nAniversariantes do mês %d:\n", mes);
    int encontrados = 0;
    
    for(int i = 0; i < qtdProf; i++) {
        if(listaProf[i].ativoProf && listaProf[i].mes_NascProf == mes) {
            printf("- %s (Dia: %d)\n", 
                  listaProf[i].nomeProf, 
                  listaProf[i].dia_NascProf);
            encontrados++;
        }
    }
    
    if(encontrados == 0) {
        printf("Nenhum professor faz aniversário neste mês.\n");
    }
}
void buscarPorNomeProfessores(dadosProf listaProf[], int qtdProf) {
    char busca[100];
    printf("Digite pelo menos 3 letras para buscar: \n");
    scanf(" %99[^\n]", busca);
    getchar();
    if (strlen(busca) < 3) {
        printf("Por favor, digite pelo menos 3 caracteres.\n");
        return;
    }
    printf("\nResultados da busca por '%s' \n", busca);
    printf("\nProfessores:\n");
    int countProfs = 0;
    for (int i = 0; i < qtdProf; i++) {
        if (listaProf[i].ativoProf && strstr(listaProf[i].nomeProf, busca) != NULL) {
            printf("- %s (Matrícula: %d)\n", listaProf[i].nomeProf, listaProf[i].matriculaProf);
            countProfs++;
        }
    }
    if (countProfs == 0) printf("Nenhum professor encontrado.\n");
}