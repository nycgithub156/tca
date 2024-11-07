#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N_NT 4

typedef struct
{
    char *nm_disc;
    float notas[N_NT];
} TDisciplina;

typedef struct
{
    char *nome;
    TDisciplina *grade;
    int numDispl;
} TAluno;

int main(int argc, char const *argv[])
{
    TAluno *info24;
    int numAlunos, i, j, k;
    char strAux[300];

    printf("Digite o numero de alunos: ");
    _fpurge(stdin);
    scanf("%d", &numAlunos);
    _fpurge(stdin);

    if (numAlunos > 0)
    {
        info24 = (TAluno *)malloc(numAlunos * sizeof(TAluno));

        if (!info24)
        {
            printf("Erro de Alocacoa no Aluno!!!\n");
            exit(1);
        }

        for (int i = 0; i < numAlunos; i++)
        {
            printf("Digite o nome do Aluno: ");
            __fpurge(stdin);
            gets(strAux);
            __fpurge(stdin);
            info24[i].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
            strcpy(info24[i].nome, strAux);
            info24[i].numDispl = 0;
            while (info24[i].numDispl <= 0)
            {
                printf("Digite a quantidade de disciplinas: ");
                __fpurge(stdin);
                scanf("%d", &info24[i].numDispl);
                __fpurge(stdin);
            }

            info24[i].grade = (TDisciplina *)malloc(info24[i].numDispl * sizeof(TDisciplina));
            for (j = 0; j < info24[i].numDispl; j++)
            {
                printf("Digite o nome da disciplinas: ");
                __fpurge(stdin);
                gets(strAux);
                __fpurge(stdin);
                info24[i].grade[j].nm_disc = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                strcpy(info24[i].grade[j].nm_disc, strAux);
                puts(info24[i].grade[j].nm_disc);
                for (k = 0; k < N_NT; k++)
                {
                    printf("Digite Note (%d): ", k + 1);
                    __fpurge(stdin);
                    scanf("%f", &info24[i].grade[j].notas[k]);
                    __fpurge(stdin);
                    printf("nota %f\n", info24[i].grade[j].notas[k]);
                }
            }
        }
    }

    return 0;
}
