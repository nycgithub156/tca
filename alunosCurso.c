#include <stdio.h>
#include <string.h>

#define C 5
#define TAM 100

typedef struct
{
    char nome[TAM];
    int matricula;
    float notaprova1;
    float notaprova2;
    float notaprova3;
    float mediageral;
} Aluno;

void preencherInformacoes(Aluno alunos[]);
char *maiorNota(Aluno alunos[]);
char *maiorMediaGeral(Aluno alunos[]);
char *menorMediaGeral(Aluno alunos[]);
void verificarAprovacao(Aluno alunos[]);

int main()
{
    Aluno alunos[C];

    preencherInformacoes(alunos);

    printf("**Maior desempenho da prova 1**\n");
    printf("%s\n", maiorNota(alunos));

    printf("**Maior Média Geral**\n");
    printf("%s\n", maiorMediaGeral(alunos));

    printf("**Menor Média Geral**\n");
    printf("%s\n", menorMediaGeral(alunos));

    verificarAprovacao(alunos);

    return 0;
}

void preencherInformacoes(Aluno alunos[])
{
    for (int i = 0; i < C; i++)
    {
        printf("**Informações do aluno %d**:\n", i + 1);
        printf("Nome:\n");
        fgets(alunos[i].nome, TAM, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = 0;

        printf("Número da Matrícula:\n");
        scanf("%d", &alunos[i].matricula);

        printf("Nota na prova 1:\n");
        scanf("%f", &alunos[i].notaprova1);

        while (alunos[i].notaprova1 < 0 || alunos[i].notaprova1 > 10)
        {
            printf("Nota inválida. Digite novamente:\n");
            scanf("%f", &alunos[i].notaprova1);
        }

        printf("Nota da prova 2:\n");
        scanf("%f", &alunos[i].notaprova2);

        while (alunos[i].notaprova2 < 0 || alunos[i].notaprova2 > 10)
        {
            printf("Nota inválida. Digite novamente:\n");
            scanf("%f", &alunos[i].notaprova2);
        }

        printf("Nota da prova 3:\n");
        scanf("%f", &alunos[i].notaprova3);

        while (alunos[i].notaprova3 < 0 || alunos[i].notaprova3 > 10)
        {
            printf("Nota inválida. Digite novamente:\n");
            scanf("%f", &alunos[i].notaprova3);
        }

        alunos[i].mediageral = (alunos[i].notaprova1 + alunos[i].notaprova2 + alunos[i].notaprova3) / 3.0;
        printf("\n");
    }
}

char *maiorNota(Aluno alunos[])
{
    float maiornota = alunos[0].notaprova1;
    static char fodao[TAM];
    strcpy(fodao, alunos[0].nome);

    for (int j = 1; j < C; j++)
    {
        if (alunos[j].notaprova1 > maiornota)
        {
            maiornota = alunos[j].notaprova1;
            strcpy(fodao, alunos[j].nome);
        }
    }
    return fodao;
}

char *maiorMediaGeral(Aluno alunos[])
{
    float maiormedia = alunos[0].mediageral;
    static char maisfodao[TAM];
    strcpy(maisfodao, alunos[0].nome);

    for (int j = 1; j < C; j++)
    {
        if (alunos[j].mediageral > maiormedia)
        {
            maiormedia = alunos[j].mediageral;
            strcpy(maisfodao, alunos[j].nome);
        }
    }
    return maisfodao;
}

char *menorMediaGeral(Aluno alunos[])
{
    float menormedia = alunos[0].mediageral;
    static char maisidiota[TAM];
    strcpy(maisidiota, alunos[0].nome);

    for (int j = 1; j < C; j++)
    {
        if (alunos[j].mediageral < menormedia)
        {
            menormedia = alunos[j].mediageral;
            strcpy(maisidiota, alunos[j].nome);
        }
    }
    return maisidiota;
}

void verificarAprovacao(Aluno alunos[])
{
    printf("\n**Resultados de Aprovação**\n");
    for (int i = 0; i < C; i++)
    {
        if (alunos[i].mediageral >= 6.0)
        {
            printf("%s está APROVADO com média: %.2f\n", alunos[i].nome, alunos[i].mediageral);
        }
        else
        {
            printf("%s está REPROVADO com média: %.2f\n", alunos[i].nome, alunos[i].mediageral);
        }
    }
}
