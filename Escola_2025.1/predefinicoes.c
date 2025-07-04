#include <stdio.h>
#include "predefinicoes.h"

bool validarData(int dia, int mes, int ano) {
    if (mes < 1 || mes > 12)
        return false;
    if (dia < 1 || dia > 31)
        return false;

    switch (mes) {
        case 4:
        case 6:
        case 9:
        case 11:
            if (dia > 30)
                return false;
            break;
        case 2:
            if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
                if (dia > 29)
                    return false;
            } else {
                if (dia > 28)
                    return false;
            }
            break;
    }
    return true;
}

int menuGeral() {
    int opcao;
    printf("0 - Exit\t\n1 - Menu Alunos\t\n2 - Menu Professores\t\n3 - Menu Disciplinas\t\n");
    scanf("%d", &opcao);
    return opcao;
}
