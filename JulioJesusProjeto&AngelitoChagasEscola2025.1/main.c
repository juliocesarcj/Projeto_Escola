#include <stdio.h>
#include "aluno.h"
#include "professores.h"
#include "disciplinas.h"
#include "predefinicoes.h"
#include <ctype.h>


//Feito por Julio Jesus e Angelito Chagas 



#define MATRICULA_SUCESSO -50
#define TURMA_LOTADA -51
#define ALUNO_NAO_ENCONTRADO -52
#define ALUNO_MATRICULADO -53
#define DISCIPLINA_NAO_ENCONTRADA -53
#define ALUNO_JA_MATRICULADO -54
#define tam_Prof 255
#define cad_prof_sucesso -7
#define matricula_prof_invalida -8
#define lista_prof_cheia -9
#define atualizacao_prof_sucesso -10
#define matricula_prof_inexistente -11
#define exclusao_prof_sucesso -12
#define cpf_prof_invalido -13
#define lista_Cheia -29
#define CAD_Prof_sucesso -31
#define atualizacao_aluno_sucesso -32
#define exclusao_Prof -33
#define matricula_inexistente -34
#define tam_Prof 255
#define disciplina_invalida -19
#define CAD_Disc_sucesso 1
#define professor_inexistente -19
#define cad_disc_sucesso -14
#define codigo_disc_invalido -15
#define lista_disc_cheia -16
#define atualizacao_disc_sucesso -17
#define codigo_disc_inexistente -18
#define exclusao_disc_sucesso -19
#define atualizacao_Disc_sucesso -21
#define disciplina_inexistente -22
#define exclusao_Disc -23
#define cpf_invalido -15
#define CAD_Aluno_sucesso -1
#define matricula_aluno_invalida -2
#define lista_aluno_cheia -3
#define matricula_aluno_inexistente -5
#define exclusao_aluno_sucesso -6
#define matricula_invalida -24
#define lista_Cheia_aluno -25
#define exclusao_Aluno -27
#define Aluno_ja_matriculado -40
int main(void)
{
    int opcao, qtdAluno = 0, qtdProf = 0, qtdDisc = 0, sair = 0;
    char sexo;
    dados listaAluno[tam_aluno];
    dadosProf listaProf[tam_Prof];
    Disc listaDisc[tam_Prof];

    while (!sair)
    {
        opcao = menuGeral();

        switch (opcao)
        {
        case 0:
            sair = 1;
            break;

        case 1:
            printf("Modulo aluno\n");
            int sairAluno = 0;
            int opcaoAluno;
            while (!sairAluno)
            {
                opcaoAluno = menuAluno();
                switch (opcaoAluno)
                {
                case 0:
                    sairAluno = 1;
                    break;

                case 1:
                {
                    int retorno = cadastrarAluno(listaAluno, qtdAluno);
                    if (retorno == lista_Cheia)
                    {
                        printf("Lista cheia\n");
                    }
                    else if (retorno == matricula_invalida)
                    {
                        printf("Matricula invalida\n");
                    }
                    else
                    {
                        printf("Cadastrado com sucesso\n");
                        qtdAluno++;
                    }
                    break;
                }

                case 2:
                {
                    listar(listaAluno, qtdAluno);
                    char opcaolistar;
                    printf("Listar Alunos: \n");
                    scanf(" %c", &opcaolistar);
                    int sairLista = 0;
                    int opcaoLista1;
                    while (!sairLista)
                    {
                        printf("\n0 - Para sair\n1 - Lista por sexo\n2 - Lista por nome\n3 - Lista por data de nascimento\n4 - Listar alunos com poucas disciplinas\n5 - Pesquisa\t\n");
                        printf("Escolha uma opcao: ");
                        scanf(" %d", &opcaoLista1);

                        switch (opcaoLista1)
                        {
                        case 0:
                            sairLista = 1;
                            break;
                        case 1:
                        {
                            char sexo;
                            printf("Digite o sexo (M/F): ");
                            scanf(" %c", &sexo);
                            listarAlunosPorSexo(listaAluno, qtdAluno, sexo);
                            break;
                        }
                        case 2:
                        {
                            listarAlunosOrdenadosPorNome(listaAluno, qtdAluno);
                            break;
                        }
                        case 3:
                        {
                            listarAlunosOrdenadosPorDataNascimento(listaAluno, qtdAluno);
                            break;
                        }
                        case 4:
                        {
                            listarAlunosPoucasDisciplinas(listaAluno, listaDisc, qtdAluno, qtdDisc);
                            break;
                        }
                        case 5:
                        {
                            pesquisa_aluno(listaAluno, qtdAluno);
                            break;
                        }

                        default:
                            printf("Opcao invalida!\n");
                            break;
                        }
                    }
                    break;
                }

                case 3:
                {
                    int retorno = atualizarAluno(listaAluno, qtdAluno);
                    if (retorno == matricula_invalida)
                    {
                        printf("Matricula invalida\n");
                    }
                    else if (retorno == matricula_inexistente)
                    {
                        printf("Matricula inexistente\n");
                    }
                    else if (retorno == atualizacao_aluno_sucesso)
                    {
                        printf("Aluno atualizado com sucesso\n");
                    }
                    break;
                }

                case 4:
                {
                    int retorno = excluir_Aluno(listaAluno, qtdAluno);
                    int matricula;
                    printf("Digite a matrícula do aluno: ");
                    scanf("%d", &matricula);
                    if (retorno == matricula_invalida)
                    {
                        printf("Matricula invalida\n");
                    }
                    else if (retorno == matricula_inexistente)
                    {
                        printf("Matricula inexistente\n");
                    }
                    else if (retorno == exclusao_Aluno)
                    {
                        printf("Aluno excluido com sucesso\n");
                        qtdAluno--;
                    }
                    break;
                }
                case 5:
                {
                    adicionarAlunoDisciplina(listaAluno, qtdAluno, listaDisc, qtdDisc);
                    break;
                }
                default:
                    printf("Escolha invalida\n");
                    break;
                }
            }
            break;

        case 2:
            printf("Modulo professor\n");
            int sairProf = 0;
            int opcaoProf;
            while (!sairProf)
            {
                opcaoProf = menuProf();
                switch (opcaoProf)
                {
                case 0:
                    sairProf = 1;
                    break;

                case 1:
                {
                    int retornoProf = cadastrarProf(listaProf, qtdProf);
                    if (retornoProf == lista_Cheia)
                    {
                        printf("Lista cheia\n");
                    }
                    else if (retornoProf == matricula_invalida)
                    {
                        printf("Matricula invalida\n");
                    }
                    else
                    {
                        printf("Cadastrado com sucesso\n");
                        qtdProf++;
                    }
                    break;
                }

                case 2:
                    lista_de_Prof(listaProf, qtdProf);
                    int opcaolistar;
                    printf("Listar professores: ");
                    scanf("%d", &opcaolistar);
                    while (getchar() != '\n')
                        ;

                    int opcaoLista;
                    while (!sairProf)
                    {
                        printf("\n0 - Para sair\n1 - Lista por sexo\n2 - Lista por nome\n3 - Lista por data de nascimento\n");
                        printf("Escolha uma opcao: ");
                        scanf("%d", &opcaoLista);
                        switch (opcaoLista)
                        {
                        case 0:
                            sairProf = 1;
                            break;
                        case 1:
                            do
                            {
                                printf("Digite o sexo (M/F): \n");
                                scanf(" %c", &sexo);
                                while (getchar() != '\n')
                                    ;
                                sexo = toupper(sexo);
                            } while (sexo != 'M' && sexo != 'F');

                            listarProfessoresPorSexo(listaProf, qtdProf, sexo);
                            break;

                        case 2:

                        buscarPorNomeProfessores(listaProf, qtdProf);
                            break;

                        case 3:
                            listarProfessoresOrdenadosPorDataNascimento(listaProf, qtdProf);
                            break;
                        default:
                            printf("Opcao invalida!\n");
                            break;
                        }
                    }

                    break;

                case 3:
                {
                    int retornoProf = atualizarProf(listaProf, qtdProf);
                    if (retornoProf == matricula_invalida)
                    {
                        printf("Matricula invalida\n");
                    }
                    else if (retornoProf == matricula_inexistente)
                    {
                        printf("Matricula inexistente\n");
                    }
                    else if (retornoProf == atualizacao_aluno_sucesso)
                    {
                        printf("Professor atualizado com sucesso\n");
                    }
                    break;
                }

                case 4:
                {
                    int retornoProf = excluir_Prof(listaProf, qtdProf);
                    if (retornoProf == matricula_invalida)
                    {
                        printf("Matricula invalida\n");
                    }
                    else if (retornoProf == matricula_inexistente)
                    {
                        printf("Matricula inexistente\n");
                    }
                    else if (retornoProf == exclusao_Prof)
                    {
                        printf("Professor excluido com sucesso\n");
                        qtdProf--;
                    }
                    break;
                }
                case 5:
                {
                    int mes;
                    printf("Digite o mês atual (1-12): \n");
                    scanf("%d", &mes);
                    listarAniversariantesDoMes(listaProf, qtdProf, mes);
                    break;
                }
                case 6:
                {
                    buscarPorNomeProfessores(listaProf, qtdProf);
                    break;
                }

                default:
                    printf("Escolha invalida\n");
                    break;
                }
            }
            break;

        case 3:
            printf("Modulo disciplina\n");
            int sairDisc = 0;
            int opcaoDisc;
            while (!sairDisc)
            {
                opcaoDisc = menuDisciplina();
                switch (opcaoDisc)
                {
                case 0:
                    sairDisc = 1;
                    break;

                case 1:
                {
                    int retornoDisc = cadastrar_disciplina(listaDisc, qtdDisc, listaProf, qtdProf);
                    if (retornoDisc == lista_Cheia)
                    {
                        printf("Lista cheia\n");
                    }
                    else if (retornoDisc == disciplina_invalida)
                    {
                        printf("Codigo invalido\n");
                    }
                    else
                    {
                        printf("Cadastrado com sucesso\n");
                        qtdDisc++;
                    }
                    break;
                }

                case 2:
                {
                    printf("\nLISTA DE DISCIPLINAS\n");

                    if (qtdDisc == 0)
                    {
                        printf("\nNenhuma disciplina cadastrada.\n");
                    }
                    else
                    {
                        printf("\nDisciplinas cadastradas: %d\n", qtdDisc);

                        for (int i = 0; i < qtdDisc; i++)
                        {
                            printf("\nAnalisando disciplina %d...", i);

                            if (listaDisc[i].ativo)
                            {
                                printf("\nCódigo: %d", listaDisc[i].codigo);
                                printf("\nNome: %s", listaDisc[i].nome);
                                printf("\nSemestre: %d", listaDisc[i].semestre);

                                int professorEncontrado = 0;
                                for (int j = 0; j < qtdProf; j++)
                                {
                                    if (listaProf[j].matriculaProf == listaDisc[i].professor && listaProf[j].ativoProf)
                                    {
                                        printf("\nProfessor: %s\n", listaProf[j].nomeProf);
                                        professorEncontrado = 1;
                                        break;
                                    }
                                }
                                if (!professorEncontrado)
                                {
                                    printf("\nProfessor: Não atribuído\n");
                                }
                                printf("\n----------------------------\n");
                            }
                            else
                            {
                                printf("\nDisciplina %d inativa\n", i);
                            }
                        }
                    }
                    printf("\n\n0 - Exit\n");
                    break;
                }
                case 3:
                {
                    int retornoDisc = atualizarDisc(listaDisc, qtdDisc);
                    if (retornoDisc == disciplina_invalida)
                    {
                        printf("Codigo invalido\n");
                    }
                    else if (retornoDisc == disciplina_inexistente)
                    {
                        printf("Disciplina inexistente\n");
                    }
                    else if (retornoDisc == atualizacao_Disc_sucesso)
                    {
                        printf("Disciplina atualizada com sucesso\n");
                    }
                    break;
                }

                case 4:
                {
                    int retornoDisc = excluir_disciplina(listaDisc, qtdDisc);
                    if (retornoDisc == disciplina_invalida)
                    {
                        printf("Codigo invalido\n");
                    }
                    else if (retornoDisc == disciplina_inexistente)
                    {
                        printf("Disciplina inexistente\n");
                    }
                    else if (retornoDisc == exclusao_Disc)
                    {
                        printf("Disciplina excluida com sucesso\n");
                        qtdDisc--;
                    }
                    break;
                }
                case 5:
                {
                    listarDisciplinatoda(qtdDisc, listaDisc, qtdAluno, listaAluno, listaProf);
                    break;
            }
                case 6:
                {
                    pesquisa_aluno(listaAluno, qtdAluno);
                    break;
                }
                default:
                    printf("Escolha invalida\n");
                    break;
                }
            }
            break;

        default:
            printf("Escolha invalida\n");
            break;
        }
    }

    return 0;
}
