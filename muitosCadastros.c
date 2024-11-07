#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char *rua;
    char *bairro;
    char *cidade;
    char *estado;
    char *cep;
} Endereco;

typedef struct
{
    char *nome;
    char cpf[12];
    char rg[12];
    char telefone[10];
    char sexo;
    int idade;
    int estadocivil;
    float salario;
    Endereco endereco;
} Registro;

void preencherRegistros(Registro *cadastro, int p);
void maisVelha(Registro *cadastro, int p);
void osHomens(Registro *cadastro, int p);
void salarioMaiorQueMil(Registro *cadastro, int p);
void informacoesBuscadas(Registro *cadastro, int p);
void liberarMemoria(Registro *cadastro, int q);

int main()
{
    int p;

    printf("Digite o número de pessoas a serem cadastradas:\n");
    __fpurge(stdin);
    scanf("%d", &p);
    __fpurge(stdin);

    Registro *cadastro;

    cadastro = (Registro *)malloc(p * sizeof(Registro));

    preencherRegistros(cadastro, p);
    printf("\n\n");
    maisVelha(cadastro, p);
    printf("\n\n");
    osHomens(cadastro, p);
    printf("\n\n");
    salarioMaiorQueMil(cadastro, p);
    printf("\n\n");
    informacoesBuscadas(cadastro, p);

    liberarMemoria(cadastro, p);

    free(cadastro);

    return 0;
}

void preencherRegistros(Registro *cadastro, int p)
{
    for (int i = 0; i < p; i++)
    {
        char strAux[100];

        printf("/* Pessoa %d */\n", i + 1);

        printf("Nome:\n");
        __fpurge(stdin);
        gets(strAux);
        __fpurge(stdin);
        cadastro[i].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(cadastro[i].nome, strAux);

        printf("/* Endereço da pessoa %d */\n", i + 1);
        printf("Rua: ");
        __fpurge(stdin);
        gets(strAux);
        __fpurge(stdin);
        cadastro[i].endereco.rua = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(cadastro[i].endereco.rua, strAux);

        printf("Bairro: ");
        __fpurge(stdin);
        gets(strAux);
        __fpurge(stdin);
        cadastro[i].endereco.bairro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(cadastro[i].endereco.bairro, strAux);

        printf("Cidade: ");
        __fpurge(stdin);
        gets(strAux);
        __fpurge(stdin);
        cadastro[i].endereco.cidade = (char *)malloc((strlen(strAux + 1)) * sizeof(char));
        strcpy(cadastro[i].endereco.cidade, strAux);

        printf("Estado: ");
        __fpurge(stdin);
        gets(strAux);
        __fpurge(stdin);
        cadastro[i].endereco.estado = (char *)malloc((strlen(strAux + 1)) * sizeof(char));
        strcpy(cadastro[i].endereco.estado, strAux);

        printf("CEP: ");
        __fpurge(stdin);
        gets(strAux);
        __fpurge(stdin);
        cadastro[i].endereco.cep = (char *)malloc((strlen(strAux + 1)) * sizeof(char));
        strcpy(cadastro[i].endereco.cep, strAux);

        printf("Salário recebido: ");
        while (scanf("%f", &cadastro[i].salario) != 1 || cadastro[i].salario < 0)
        {
            printf("Por favor, insira um salário válido (não negativo): ");
        }

        printf("RG:\n");
        __fpurge(stdin);
        gets(cadastro[i].rg);
        __fpurge(stdin);
        while (strlen(cadastro[i].rg) != 11)
        {
            printf("Digite o rg completo\n");
            __fpurge(stdin);
            gets(cadastro[i].rg);
            __fpurge(stdin);
        }

        printf("CPF:\n");
        __fpurge(stdin);
        gets(cadastro[i].cpf);
        __fpurge(stdin);
        while(strlen(cadastro[i].cpf) != 11)
        {
            printf("Digite o cpf completo\n");
            __fpurge(stdin);
            gets(cadastro[i].cpf);
            __fpurge(stdin);
        }


        printf("/* Estado civil */\n");
        printf("1_Casado\n2_Separado\n3_Divorciado\n4_Solteiro\n");
        while (scanf("%d", &cadastro[i].estadocivil) != 1 || cadastro[i].estadocivil < 1 || cadastro[i].estadocivil > 4)
        {
            printf("Digite uma das opções disponíveis:\n");
        }

        printf("Telefone: ");
        __fpurge(stdin);
        gets(cadastro[i].telefone);
        __fpurge(stdin);

        printf("Idade: ");
        while (scanf("%d", &cadastro[i].idade) != 1 || cadastro[i].idade < 0 || cadastro[i].idade > 112)
        {
            printf("Digite uma idade plausível:\n");
        }

        printf("Sexo (m para masculino, f para feminino): ");
        while (scanf(" %c", &cadastro[i].sexo) != 1 || (cadastro[i].sexo != 'm' && cadastro[i].sexo != 'f'))
        {
            printf("Digite m para masculino e f para feminino:\n");
        }
    }
}

void maisVelha(Registro *cadastro, int p)
{
    int maioridade = -1;
    Registro informacoes;

    for (int i = 0; i < p; i++)
    {
        if (cadastro[i].idade > maioridade)
        {
            maioridade = cadastro[i].idade;
            informacoes = cadastro[i];
        }
    }

    printf("Pessoa mais velha: %s, Idade: %d\n", informacoes.nome, informacoes.idade);
}

void osHomens(Registro *cadastro, int p)
{
    printf("Homens cadastrados:\n");

    for (int i = 0; i < p; i++)
    {
        if (cadastro[i].sexo == 'm')
        {
            printf("%s\n", cadastro[i].nome);
        }
    }
}

void salarioMaiorQueMil(Registro *cadastro, int p)
{
    printf("Pessoas com salário maior que 1000:\n");

    for (int i = 0; i < p; i++)
    {
        if (cadastro[i].salario > 1000)
        {
            printf("%s\n", cadastro[i].nome);
        }
    }
}

void informacoesBuscadas(Registro *cadastro, int p)
{
    char rgBuscado[12];

    printf("Digite o RG da pessoa que procura:\n");
    __fpurge(stdin);
    gets(rgBuscado);
    __fpurge(stdin);

    int encontrado = 0;
    for (int i = 0; i < p; i++)
    {
        if (strcmp(cadastro[i].rg, rgBuscado) == 0)
        {
            printf("Dados da pessoa encontrada:\n");
            printf("Nome: %s\n", cadastro[i].nome);
            printf("CPF: %s\n", cadastro[i].cpf);
            printf("Telefone: %s\n", cadastro[i].telefone);
            printf("Idade: %d\n", cadastro[i].idade);
            printf("Sexo: %c\n", cadastro[i].sexo);
            printf("Salário: %.2f\n", cadastro[i].salario);
            printf("Endereço: %s, %s, %s, %s, %s\n",
                   cadastro[i].endereco.rua,
                   cadastro[i].endereco.bairro,
                   cadastro[i].endereco.cidade,
                   cadastro[i].endereco.estado,
                   cadastro[i].endereco.cep);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Pessoa não encontrada.\n");
    }
}

void liberarMemoria(Registro *cadastro, int q)
{
    int a,b,c,d,e;

    for(a = 0; a < q;a++)
    {
        free(cadastro[a].endereco.rua);
    }

    for(b = 0; b < q; b++)
    {
        free(cadastro[b].endereco.bairro);
    }

    for(c = 0; c < q;c++)
    {
        free(cadastro[c].endereco.cidade);
    }

    for(d = 0; d < q; d++)
    {
        free(cadastro[d].endereco.estado);
    }

    for(e = 0; e < q;e++)
    {
        free(cadastro[e].endereco.cep);
    }
}
