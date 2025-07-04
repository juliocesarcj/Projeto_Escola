#include <stdio.h>
#include "aluno.h"
#include "professores.h"
#include "disciplinas.h"
#include "predefinicoes.h"
#include <ctype.h>


//Feito por Julio Jesus

int main()
{
    int opcao, qtdAluno = 0, qtdProf = 0, qtdDisc = 0, sair = 0;
    char sexo;
    dados listaAluno[TAM_ALUNO];
    dadosProf listaProf[TAM_PROF];
    Disc listaDisc[TAM_PROF];

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
                    if (retorno == LISTA_CHEIA_ALUNO)
                    {
                        printf("Lista cheia\n");
                    }
                    else if (retorno == MATRICULA_INVALIDA)
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
                    if (retorno == MATRICULA_INVALIDA)
                    {
                        printf("Matricula invalida\n");
                    }
                    else if (retorno == MATRICULA_INEXISTENTE)
                    {
                        printf("Matricula inexistente\n");
                    }
                    else if (retorno == ATUALIZACAO_ALUNO_SUCESSO)
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
                    if (retorno == MATRICULA_INVALIDA)
                    {
                        printf("Matricula invalida\n");
                    }
                    else if (retorno == MATRICULA_INEXISTENTE)
                    {
                        printf("Matricula inexistente\n");
                    }
                    else if (retorno == EXCLUSAO_ALUNO)
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
                    if (retornoProf == LISTA_PROFESSOR_CHEIA)
                    {
                        printf("Lista cheia\n");
                    }
                    else if (retornoProf == MATRICULA_INVALIDA)
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
                    if (retornoProf == MATRICULA_INVALIDA)
                    {
                        printf("Matricula invalida\n");
                    }
                    else if (retornoProf == MATRICULA_INEXISTENTE)
                    {
                        printf("Matricula inexistente\n");
                    }
                    else if (retornoProf == ATUALIZACAO_ALUNO_SUCESSO)
                    {
                        printf("Professor atualizado com sucesso\n");
                    }
                    break;
                }

                case 4:
                {
                    int retornoProf = excluir_Prof(listaProf, qtdProf);
                    if (retornoProf == MATRICULA_INVALIDA)
                    {
                        printf("Matricula invalida\n");
                    }
                    else if (retornoProf == MATRICULA_INEXISTENTE)
                    {
                        printf("Matricula inexistente\n");
                    }
                    else if (retornoProf == EXCLUSAO_PROFESSOR)
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
                    if (retornoDisc == LISTA_DISCIPLINA_CHEIA)
                    {
                        printf("Lista cheia\n");
                    }
                    else if (retornoDisc == CODIGO_DISCIPLINA_INVALIDO)
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
                    if (retornoDisc == CODIGO_DISCIPLINA_INVALIDO)
                    {
                        printf("Codigo invalido\n");
                    }
                    else if (retornoDisc == DISCIPLINA_INEXISTENTE)
                    {
                        printf("Disciplina inexistente\n");
                    }
                    else if (retornoDisc == ATUALIZACAO_DISCIPLINA_SUCESSO)
                    {
                        printf("Disciplina atualizada com sucesso\n");
                    }
                    break;
                }

                case 4:
                {
                    int retornoDisc = excluir_disciplina(listaDisc, qtdDisc);
                    if (retornoDisc == CODIGO_DISCIPLINA_INVALIDO)
                    {
                        printf("Codigo invalido\n");
                    }
                    else if (retornoDisc == DISCIPLINA_INEXISTENTE)
                    {
                        printf("Disciplina inexistente\n");
                    }
                    else if (retornoDisc == EXCLUSAO_DISCIPLINA)
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
