#include <stdio.h>
#include "disciplinas.h"
#include "professores.h"
#define Professor_H
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
#define lista_Cheia -20
#define atualizacao_Disc_sucesso -21
#define disciplina_inexistente -22
#define exclusao_Disc -23


int menuDisciplina() {
    int opcaoDisc;
    printf("0 - Exit\t\n1 - Cadastrar disciplina\t\n2 - Listar disciplina\t\n3 - Atualizar disciplina\t\n4 - Excluir disciplina\t\n5 - Para listar turmas lotadas\t\n6 - pesquisa aluno\t\n");
    scanf("%d", &opcaoDisc);
    return opcaoDisc;
}

int cadastrar_disciplina(Disc listaDisc[], int qtdDisc, dadosProf listaProf[], int qtdProf) { 
    printf("Cadastrar Disciplina\n");
    if (qtdDisc == tam_Prof) {
        return lista_Cheia;
    }

    printf("Nome da disciplina: ");
    scanf(" %[^\n]", listaDisc[qtdDisc].nome);

    printf("Semestre: ");
    scanf("%d", &listaDisc[qtdDisc].semestre);

    printf("Código da disciplina: ");
    scanf("%d", &listaDisc[qtdDisc].codigo);

    int codProf;
    printf("matricula do professor: ");
    scanf("%d", &codProf);
    listaDisc[qtdDisc].professor = codProf;
    listaProf[qtdProf].ativoProf = 1;
    return CAD_Disc_sucesso;
}


int listarDisc(Disc listaDisc[], int qtdDisc, dadosProf listaProf[], int qtdProf) {
    printf("Listar Disciplinas\n");
    if (qtdDisc == 0) {
        printf("Lista de disciplinas vazia\n");
    } else {
        for (int i = 0; i < qtdDisc; i++) {
            if (listaDisc[i].ativo) {
                int encontrou = 0;
                for (int j = 0; j < qtdProf; j++) {
                    if (listaProf[j].matriculaProf == listaDisc[i].professor && listaProf[j].ativoProf) {
                        printf("Professor: %s", listaProf[j].nomeProf);
                        encontrou = 1;
                        break;
                    }
                }
                if (!encontrou) {
                    printf("Professor: N/A\n");
                }
                
                printf("Nome: %s\n", listaDisc[i].nome);
                printf("Codigo: %d\n", listaDisc[i].codigo);
                printf("Semestre: %d\n", listaDisc[i].semestre);
                printf("-------------\n");
            }
        }
    }
    return 0; 
}

int atualizarDisc(Disc listaDisc[], int qtdDisc) {
    printf("Atualizar Disciplina\n");
    printf("Digite o codigo da disciplina: ");
    int codigo;
    scanf("%d", &codigo);
getchar();
    if (codigo < 0) {
        return disciplina_invalida;
    }

    for (int i = 0; i < qtdDisc; i++) {
        if (listaDisc[i].codigo == codigo && listaDisc[i].ativo) {
            printf("Digite o novo nome da disciplina: ");
            fgets(listaDisc[i].nome, tam_nome, stdin);

            printf("Digite o numero do semestre: ");
            scanf("%d", &listaDisc[i].semestre);

            printf("Digite o novo codigo do professor: ");
            scanf("%d", &listaDisc[i].professor);

            return atualizacao_Disc_sucesso;
        }
    }

    return disciplina_inexistente;
}

int excluir_disciplina(Disc listaDisc[], int qtdDisc) {
    printf("Excluir Disciplina\n");
    printf("Digite o codigo da disciplina: ");
    int codigo;
    scanf("%d", &codigo);

    if (codigo < 0) {
        return disciplina_invalida;
    }

    for (int i = 0; i < qtdDisc; i++) {
        if (listaDisc[i].codigo == codigo && listaDisc[i].ativo) {
            listaDisc[i].ativo = 0;
            return exclusao_Disc;
        }
    }

    return disciplina_inexistente;
}
void listarDisciplinatoda(int qtdDisc, Disc listaDisc[], int qtdAluno, dados listaAluno[], dadosProf listaProf[]){
    int temp, i=0, j=0, k=0, verificador=0;
    printf("Qual o código da disciplina que deve ser listada?\n");
    scanf("%d",&temp);
    for(i=0;i<qtdDisc;i++){
        if(temp==listaDisc[i].codigo){
            verificador=1;
            break;
        }
    }
    if(verificador == 1){
        printf("Disciplina: %s\n"
        "Semestre: %d\n"
        "Código: %d\n"
        "Professor de matrícula: %d\n", listaDisc[i].nome, listaDisc[i].semestre, listaDisc[i].codigo, listaProf[i].matriculaProf);
        printf("Os seguintes alunos estão matriculados na disciplina: \n");
        for(j=0; j<qtdAluno; j++){
            while(listaAluno[j].disciplinasMatriculadas[k] != 0){
                if(listaAluno[j].disciplinasMatriculadas[k] == temp){
                    printf("%s\n", listaAluno[j].nome);
                    break;
                }
                k++;
            }
            k=0;
        } 
    }else{
        printf("Disciplina não registrada!\n");
    }
   
}
