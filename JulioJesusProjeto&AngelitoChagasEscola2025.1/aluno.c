#include <stdio.h>
#include "aluno.h"
#include "predefinicoes.h"
#include <ctype.h>
#include "disciplinas.h"
#define cpf_invalido -15
#define CAD_Aluno_sucesso -1
#define matricula_aluno_invalida -2
#define lista_aluno_cheia -3
#define atualizacao_aluno_sucesso -4
#define matricula_aluno_inexistente -5
#define exclusao_aluno_sucesso -6
#define matricula_invalida -24
#define lista_Cheia_aluno -25
#define matricula_inexistente -26
#define exclusao_Aluno -27
#define MAX_ALUNOS 90
#define MATRICULA_SUCESSO -37
#define TURMA_LOTADA -38
#define ALUNO_NAO_ENCONTRADO -42
#define ALUNO_JA_MATRICULADO -43
#define DISCIPLINA_NAO_ENCONTRADA -44
#define LISTA_CHEIA -45
#define MAX_DISCIPLINAS 20
int menuAluno()
{
    int opcaoAluno;
    printf("0 - Exit\t\n1 - Cadastrar Aluno\t\n2 - Listar Aluno\t\n3 - Atualizar Aluno\t\n4 - Excluir Aluno\t\n5 - Matricular Aluno na Disciplina\t\n");
    scanf("%d", &opcaoAluno);
    return opcaoAluno;
}

int cadastrarAluno(dados listaAluno[], int qtdAluno)
{
    printf("Cadastrar Aluno\n");
    if (qtdAluno == tam_aluno)
    {
        return lista_Cheia_aluno;
    }

    int matricula;
    printf("Digite a matricula: ");
    scanf("%d", &matricula);

    if (matricula < 0)
    {
        return matricula_invalida;
    }

    listaAluno[qtdAluno].matricula = matricula;
    listaAluno[qtdAluno].ativo = 1;

    while (getchar() != '\n')
        ;

    listaAluno[qtdAluno].matricula = matricula;
    listaAluno[qtdAluno].ativo = 1;

    printf("O nome do aluno: ");
    fgets(listaAluno[qtdAluno].nome, 250, stdin);

    printf("o cpf do Aluno: ");
    fgets(listaAluno[qtdAluno].cpf, 12, stdin);
    listaAluno[qtdAluno].cpf[strcspn(listaAluno[qtdAluno].cpf, "\n")] = '\0';
    if (!validar_cpf(listaAluno[qtdAluno]))
    {
        printf("CPF invalido!\n");
        return cpf_invalido;
    }

    printf("Digite o sexo (M/F): ");
    scanf(" %c", &listaAluno[qtdAluno].sexoAluno);

    printf("Digite o dia de nascimento: ");
    scanf("%d", &listaAluno[qtdAluno].dia_Nasc);

    printf("Digite o mes de nascimento: ");
    scanf("%d", &listaAluno[qtdAluno].mes_Nasc);

    printf("Digite o ano de nascimento: ");
    scanf("%d", &listaAluno[qtdAluno].ano_Nasc);

    if (!validarData(listaAluno[qtdAluno].dia_Nasc, listaAluno[qtdAluno].mes_Nasc, listaAluno[qtdAluno].ano_Nasc))
    {
        printf("Data de nascimento invalida!\n");
        return matricula_invalida;
    }

    return CAD_Aluno_sucesso;
}

void listar(dados listaAluno[], int qtdAluno)
{
    printf("Listar Aluno\n");
    if (qtdAluno == 0)
    {
        printf("Lista de alunos vazia\n");
    }
    else
    {
        for (int i = 0; i < qtdAluno; i++)
        {
            if (listaAluno[i].ativo)
            {
                printf("Matricula: %d\n", listaAluno[i].matricula);
                printf("Nome: %s", listaAluno[i].nome);
                printf("CPF: ");
                for (int j = 0; j < 11; j++)
                {
                    printf("%c", listaAluno[i].cpf[j]);
                }
                printf("\n");
                printf("Sexo: %c", listaAluno[i].sexoAluno);
                printf("\n");
                printf("Data de Nascimento: %02d/%02d/%04d\n", listaAluno[i].dia_Nasc, listaAluno[i].mes_Nasc, listaAluno[i].ano_Nasc);
                printf("-------------\n");
            }
        }
    }
}

int atualizarAluno(dados listaAluno[], int qtdAluno)
{
    printf("Atualizar Aluno\n");
    printf("Digite a matricula: ");
    int matricula;
    scanf("%d", &matricula);

    if (matricula < 0)
    {
        return matricula_invalida;
    }

    for (int i = 0; i < qtdAluno; i++)
    {
        if (listaAluno[i].matricula == matricula && listaAluno[i].ativo)
        {
            printf("Digite a nova matricula: ");
            int novaMatricula;
            scanf("%d", &novaMatricula);

            if (novaMatricula < 0)
            {
                return matricula_invalida;
            }

            listaAluno[i].matricula = novaMatricula;
            return atualizacao_aluno_sucesso;
        }
    }

    return matricula_inexistente;
}

int excluir_Aluno(dados listaAluno[], int qtdAluno)
{
    printf("Excluir Aluno\n");
    printf("Digite a matricula: ");
    int matricula;
    scanf("%d", &matricula);

    if (matricula < 0)
    {
        return matricula_invalida;
    }

    for (int i = 0; i < qtdAluno; i++)
    {
        if (listaAluno[i].matricula == matricula && listaAluno[i].ativo)
        {
            listaAluno[i].ativo = 0;
            return exclusao_Aluno;
        }
    }

    return matricula_inexistente;
}

void listarAlunosPorSexo(dados listaAluno[], int qtdAluno, char sexo)
{
    printf("Listar Alunos por Sexo (%c)\n", sexo);
    for (int i = 0; i < qtdAluno; i++)
    {
        if (listaAluno[i].ativo && listaAluno[i].sexoAluno == sexo)
        {
            printf("Matricula: %d\n", listaAluno[i].matricula);
            printf("Nome: %s\n", listaAluno[i].nome);
            printf("Sexo: %c\n", listaAluno[i].sexoAluno);
            printf("\nData de Nascimento: %02d/%02d/%04d\n", listaAluno[i].dia_Nasc, listaAluno[i].mes_Nasc, listaAluno[i].ano_Nasc);
            printf("-------------\n");
        }
    }
}

void listarAlunosOrdenadosPorNome(dados listaAluno[], int qtdAluno)
{
    printf("Listar Alunos Ordenados por Nome\n");
    for (int i = 0; i < qtdAluno - 1; i++)
    {
        for (int j = 0; j < qtdAluno - i - 1; j++)
        {
            if (strcmp(listaAluno[j].nome, listaAluno[j + 1].nome) > 0)
            {
                dados temp = listaAluno[j];
                listaAluno[j] = listaAluno[j + 1];
                listaAluno[j + 1] = temp;
            }
        }
    }
    listar(listaAluno, qtdAluno);
}

void listarAlunosOrdenadosPorDataNascimento(dados listaAluno[], int qtdAluno)
{
    printf("Listar Alunos Ordenados por Data de Nascimento\n");
    for (int i = 0; i < qtdAluno - 1; i++)
    {
        for (int j = 0; j < qtdAluno - i - 1; j++)
        {
            if (listaAluno[j].ano_Nasc > listaAluno[j + 1].ano_Nasc ||
                (listaAluno[j].ano_Nasc == listaAluno[j + 1].ano_Nasc && listaAluno[j].mes_Nasc > listaAluno[j + 1].mes_Nasc) ||
                (listaAluno[j].ano_Nasc == listaAluno[j + 1].ano_Nasc && listaAluno[j].mes_Nasc == listaAluno[j + 1].mes_Nasc && listaAluno[j].dia_Nasc > listaAluno[j + 1].dia_Nasc))
            {
                dados temp = listaAluno[j];
                listaAluno[j] = listaAluno[j + 1];
                listaAluno[j + 1] = temp;
            }
        }
    }
    listar(listaAluno, qtdAluno);
}
bool validar_cpf(dados aluno)
{
    char cpf[12];
    strcpy(cpf, aluno.cpf);
    int soma = 0, resto, digito1, digito2;
    bool todos_iguais = true;
    for (int i = 1; i < 11; i++)
    {
        if (cpf[i] != cpf[0])
        {
            todos_iguais = false;
            break;
        }
    }
    if (todos_iguais)
        return false;
    soma = 0;
    for (int i = 0; i < 9; i++)
    {
        soma += (cpf[i] - '0') * (10 - i);
    }
    resto = soma % 11;
    digito1 = (resto < 2) ? 0 : 11 - resto;
    soma = 0;
    for (int i = 0; i < 10; i++)
    {
        soma += (cpf[i] - '0') * (11 - i);
    }
    resto = soma % 11;
    digito2 = (resto < 2) ? 0 : 11 - resto;
    return (digito1 == (cpf[9] - '0') && digito2 == (cpf[10] - '0'));
}
int contarDisciplinasPorAluno(Disc listaDisc[], int qtdDisc, int matriculaAluno) {
    int contador = 0;
    for (int j = 0; j < qtdDisc; j++) {
        if (!listaDisc[j].ativo) continue;
        for (int i = 0; i < listaDisc[j].vagasOcupadas; i++) {
            if (listaDisc[j].alunosMatriculados[i] == matriculaAluno) {
                contador++;
                break;
            }
        }
    }
    return contador;
}
void listarAlunosPoucasDisciplinas(dados listaAluno[], Disc listaDisc[], int qtdAluno, int qtdDisc) {
    printf("Os alunos matriculados em menos de 3 disciplinas são: \n");
    for(int i=0; i<qtdAluno; i++){
        int qtdMatriculas=0, j=0;
        while(listaAluno[i].disciplinasMatriculadas[j] != 0){
            qtdMatriculas++;
            j++;
        }
        if(qtdMatriculas<3){
            printf("%s\n", listaAluno[i].nome);
        }
    }
}
void pesquisa_aluno(dados listaAluno[], int qtdAluno)
{
    char busca[100];
    printf("Digite pelo menos 3 letras para buscar: ");
    scanf(" %99[^\n]", busca);
    getchar();
    if (strlen(busca) < 3)
    {
        printf("Por favor, digite pelo menos 3 caracteres.\n");
        return;
    }
    printf("\nResultados da busca por '%s'\n", busca);
    printf("\nAlunos:\n");
    int countAlunos = 0;
    for (int i = 0; i < qtdAluno; i++)
    {
        if (listaAluno[i].ativo && strstr(listaAluno[i].nome, busca) != NULL)
        {
            printf("- %s (Matrícula: %d)\n", listaAluno[i].nome, listaAluno[i].matricula);
            countAlunos++;
        }
    }
    if (countAlunos == 0)
        printf("Nenhum aluno encontrado.\n");
}
void adicionarAlunoDisciplina(dados listaAluno[], int qtdAluno, Disc listaDisc[], int qtdDisc){
    int i, j=0, qtdMatriculas=0;
    int temp = -1;
    for(int i=0; i<maxDisciplinas; i++){
    listaAluno[qtdAluno].disciplinasMatriculadas[i] = 0;
    }
    while(temp != 0){
        int verificador=0;
        printf("Qual codigo da disciplina que o aluno deve ser matriculado? (Insira 0 para encerrar)\n");
        scanf("%d", &temp);
        if(temp == 0){
            break;
        }else{
            for(int i=0; i<qtdDisc; i++){
                if(temp==listaDisc[i].codigo){
                    verificador = 1;
                    break;
                }
            }
            if(verificador == 1){                
                if(qtdMatriculas<maxDisciplinas){
                    int jaMatriculado=0;
                    for(i=0; i<qtdMatriculas; i++){
                        if(temp == listaAluno[qtdAluno].disciplinasMatriculadas[i]){
                            jaMatriculado = 1;
                            break;
                        }
                    }
                    if(jaMatriculado == 1){
                        printf("Aluno já matriculado na disciplina!\n");
                    }else{
                    listaAluno[qtdAluno].disciplinasMatriculadas[qtdMatriculas] = temp;
                    qtdMatriculas++;
                    }
                }else{
                    printf("Limite de disciplinas atingido\n");
                }
            }else{
                printf("A disciplina não existe!\n");
            }
        }
    }
    printf("Aluno matriculado nas seguintes disciplinas: ");
    for(i=0; i<qtdMatriculas; i++){
        printf("%d ",listaAluno[qtdAluno].disciplinasMatriculadas[i]);
    }
};