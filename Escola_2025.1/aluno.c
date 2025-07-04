#include <stdio.h>
#include "aluno.h"
#include "predefinicoes.h"
#include <ctype.h>
#include "disciplinas.h"

// hub para os caminhos do menu aluno
int menuAluno()
{
    int opcaoAluno;
    printf("0 - Exit\t\n"
        "1 - Cadastrar Aluno\t\n"
        "2 - Listar Aluno\t\n"
        "3 - Atualizar Aluno\t\n"
        "4 - Excluir Aluno\t\n"
        "5 - Matricular Aluno na Disciplina\t\n"
    );
    scanf("%d", &opcaoAluno);
    return opcaoAluno;
}

// cadastra o aluno
int cadastrarAluno(dados listaAluno[], int qtdAluno)
{
    printf("Cadastrar Aluno\n");
    if (qtdAluno == TAM_ALUNO)
    {
        return LISTA_ALUNO_CHEIA;
    }

    int matricula;
    printf("Digite a matricula: ");
    scanf("%d", &matricula);

    if (matricula < 0)
    {
        return MATRICULA_INVALIDA;
    }

    listaAluno[qtdAluno].matricula = matricula;
    listaAluno[qtdAluno].ativo = 1;

    while (getchar() != '\n');
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
        return CPF_INVALIDO;
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
        return MATRICULA_INVALIDA;
    }

    return CADASTRO_ALUNO_SUCESSO;
}

//printa tudo de aluno
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

//substitui dados ja declarados por novo dados solicitados
int atualizarAluno(dados listaAluno[], int qtdAluno)
{
    printf("Atualizar Aluno\n");
    printf("Digite a matricula: ");
    int matricula;
    scanf("%d", &matricula);

    if (matricula < 0)
    {
        return MATRICULA_INVALIDA;
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
                return MATRICULA_INVALIDA;
            }

            listaAluno[i].matricula = novaMatricula;
            return ATUALIZACAO_ALUNO_SUCESSO;
        }
    }

    return MATRICULA_ALUNO_INEXISTENTE;
}

//deleta um cadastro
int excluir_Aluno(dados listaAluno[], int qtdAluno)
{
    printf("Excluir Aluno\n");
    printf("Digite a matricula: ");
    int matricula;
    scanf("%d", &matricula);

    if (matricula < 0)
    {
        return MATRICULA_INVALIDA;
    }

    for (int i = 0; i < qtdAluno; i++)
    {
        if (listaAluno[i].matricula == matricula && listaAluno[i].ativo)
        {
            listaAluno[i].ativo = 0;
            return EXCLUSAO_ALUNO;
        }
    }

    return MATRICULA_ALUNO_INEXISTENTE;
}

//ordena por sexo
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

//ordena por nome
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

//ordena por idade
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

//testa se o CPF recebido eh valido
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

//devolve quantas disciplinas cada aluno tem
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

//procura quantos alunos esta vinculado a menos de 3 disciplinas
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

//procura alunos pelo nome da entrada com no minimo 3 letras 
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

//vincula a matricula do aluno digitada com o id da disciplina 
void adicionarAlunoDisciplina(dados listaAluno[], int qtdAluno, Disc listaDisc[], int qtdDisc){
    int i, j=0, qtdMatriculas=0;
    int temp = -1;
    for(int i=0; i<MAX_DISCIPLINAS; i++){
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
                if(qtdMatriculas<MAX_DISCIPLINAS){
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