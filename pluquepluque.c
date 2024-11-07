#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *rua;
    char *numero;
    char *complemento;
    char *bairro;
    char *cep;
    char *cidade;
    char *estado;
    char *pais;
} Endereco;

typedef struct {
    char ddd[3];
    char num[10];
} Telefone;

typedef struct {
    int dia;
    int mes;
    int ano;
} Aniversario;

typedef struct {
    char *nome;
    char *email;
    Endereco endereco;
    Telefone tel;
    Aniversario data;
} Informacoes;

void preencherLista(Informacoes *phonelist, int q);
void printarInformacoes(Informacoes *info);
void buscaPrimeiroNome(Informacoes *phonelist, int q);
void buscaMesAniversario(Informacoes *phonelist, int q);
void buscaDiaeMes(Informacoes *phonelist, int q);

int main() {
    int q;
    printf("Qual o tamanho da lista?\n");
    scanf("%d", &q);
    while (q > 100) {
        printf("A capacidade máxima da lista é de 100 pessoas. Redefina a quantidade:\n");
        scanf("%d", &q);
    }

    Informacoes *phoneList;    
    phoneList = (Informacoes *)malloc(q * sizeof(Informacoes));

    preencherLista(phoneList, q);
    
    int op;
    do {
        printf("\n***Menu de opções***\n");
        printf("1 - Buscar pelo primeiro nome;\n");
        printf("2 - Buscar por mês de nascimento;\n");
        printf("3 - Buscar por dia e mês de nascimento;\n");
        printf("4 - Sair do programa.\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);
        
        switch(op) {
            case 1:
                buscaPrimeiroNome(phoneList, q);
                break;
            case 2:
                buscaMesAniversario(phoneList, q);
                break;
            case 3:
                buscaDiaeMes(phoneList, q);
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Por favor, escolha novamente.\n");
        }
    } while (op != 4);

    for (int i = 0; i < q; i++) {
        free(phoneList[i].nome);
        free(phoneList[i].email);
        free(phoneList[i].endereco.rua);
        free(phoneList[i].endereco.numero);
        free(phoneList[i].endereco.complemento);
        free(phoneList[i].endereco.bairro);
        free(phoneList[i].endereco.cep);
        free(phoneList[i].endereco.cidade);
        free(phoneList[i].endereco.estado);
        free(phoneList[i].endereco.pais);
    }
    free(phoneList);

    return 0;
}

void preencherLista(Informacoes *phonelist, int q)
{
    for (int i = 0; i < q; i++)
    {
        char strAux[400];
        printf("/*Pessoa %d/*\n", i + 1);
        
        printf("Nome Completo:\n");
        __fpurge(stdin);
        gets(strAux);
        __fpurge(stdin);
        phonelist[i].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(phonelist[i].nome, strAux);
        
        printf("Email:\n");
        __fpurge(stdin);
        gets(strAux);
        __fpurge(stdin);
        phonelist[i].email = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(phonelist[i].email, strAux);
        
        printf("Endereço da pessoa %d\n", i + 1);
        
        printf("Rua:\n");
        __fpurge(stdin);
        gets(strAux);
        __fpurge(stdin);
        phonelist[i].endereco.rua = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(phonelist[i].endereco.rua, strAux);
        
        printf("Número da residência:\n");
        __fpurge(stdin);
        gets(strAux);
        __fpurge(stdin);
        phonelist[i].endereco.numero = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(phonelist[i].endereco.numero, strAux);
        
        printf("Complemento:\n");
        __fpurge(stdin);
        gets(strAux);
        __fpurge(stdin);
        phonelist[i].endereco.complemento = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(phonelist[i].endereco.complemento, strAux);
        
        printf("Bairro:\n");
        __fpurge(stdin);
        gets(strAux);
        __fpurge(stdin);
        phonelist[i].endereco.bairro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(phonelist[i].endereco.bairro, strAux);
        
        printf("CEP:\n");
        __fpurge(stdin);
        gets(strAux);
        __fpurge(stdin);
        phonelist[i].endereco.cep = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(phonelist[i].endereco.cep, strAux);
        
        printf("Cidade:\n");
        __fpurge(stdin);
        gets(strAux);
        __fpurge(stdin);
        phonelist[i].endereco.cidade = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(phonelist[i].endereco.cidade, strAux);
        
        printf("Estado:\n");
        __fpurge(stdin);
        gets(strAux);
        __fpurge(stdin);
        phonelist[i].endereco.estado = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(phonelist[i].endereco.estado, strAux);
        
        printf("País:\n");
        __fpurge(stdin);
        gets(strAux);
        __fpurge(stdin);
        phonelist[i].endereco.pais = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(phonelist[i].endereco.pais, strAux);
        
        printf("Aniversário da pessoa %d\n", i + 1);
        
        printf("Mês:\n");
        scanf("%d", &phonelist[i].data.mes);
        while (phonelist[i].data.mes < 1 || phonelist[i].data.mes > 12)
        {
            printf("Mês inválido!\n");
            scanf("%d", &phonelist[i].data.mes);
        }
        
        printf("Ano:\n");
        scanf("%d", &phonelist[i].data.ano);
        while (phonelist[i].data.ano < 0 || phonelist[i].data.ano > 2024)
        {
            printf("Ano inválido!\n");
            scanf("%d", &phonelist[i].data.ano);
        }
        
        printf("Dia:\n");
        scanf("%d", &phonelist[i].data.dia);
        while ((phonelist[i].data.mes == 2 && phonelist[i].data.ano % 4 != 0 && phonelist[i].data.dia > 28) ||
               (phonelist[i].data.mes == 2 && phonelist[i].data.ano % 4 == 0 && phonelist[i].data.dia > 29) ||
               ((phonelist[i].data.mes == 4 || phonelist[i].data.mes == 6 || phonelist[i].data.mes == 9 || phonelist[i].data.mes == 11) && phonelist[i].data.dia > 30))
        {
            printf("Esse dia não existe!\n");
            scanf("%d", &phonelist[i].data.dia);
        }
        
        printf("Telefone da pessoa %d\n", i + 1);
        
        printf("Digite o DDD:\n");
        __fpurge(stdin);
        gets(phonelist[i].tel.ddd);
        __fpurge(stdin);
        
        printf("Número de Telefone:\n");
        __fpurge(stdin);
        gets(phonelist[i].tel.num);
        __fpurge(stdin);
    }
}

void printarInformacoes(Informacoes *info) 
{
    printf("Nome: %s\n", (*info).nome);
    printf("Email: %s\n", (*info).email);
    printf("Endereço:\n");
    printf("  Rua: %s\n", (*info).endereco.rua);
    printf("  Número: %s\n", (*info).endereco.numero);
    printf("  Complemento: %s\n", (*info).endereco.complemento);
    printf("  Bairro: %s\n", (*info).endereco.bairro);
    printf("  CEP: %s\n", (*info).endereco.cep);
    printf("  Cidade: %s\n", (*info).endereco.cidade);
    printf("  Estado: %s\n", (*info).endereco.estado);
    printf("  País: %s\n", (*info).endereco.pais);
    printf("Aniversário: %02d/%02d/%04d\n", (*info).data.dia, (*info).data.mes, (*info).data.ano);
    printf("Telefone: (%s) %s\n", (*info).tel.ddd, (*info).tel.num);
    printf("\n");
}

void buscaPrimeiroNome(Informacoes *phonelist, int q)
{
    char aux[50];
    char *nome_Busc;
    
    printf("Digite o primeiro nome da pessoa buscada:\n");
    __fpurge(stdin);
    gets(aux);
    __fpurge(stdin);
    
    nome_Busc = (char *)malloc((strlen(aux) + 1) * sizeof(char));
    strcpy(nome_Busc, aux);
    
    printf("Pessoas chamadas %s:\n\n", nome_Busc);
    
    for (int i = 0; i < q; i++)
    {
        char prime_Nome[50]; 
        int j;
        for (j = 0; phonelist[i].nome[j] != ' '; j++)
        {
            prime_Nome[j] = phonelist[i].nome[j];
        }

        if (strcmp(prime_Nome, nome_Busc) == 0)
        {
            printarInformacoes(&phonelist[i]); 
        }
    }

    free(nome_Busc);

}

void buscaMesAniversario(Informacoes *phonelist, int q)
{
    int m_Busc;

    printf("Digite o mês de aniversário da pessoa buscada(1-12):\n");
    scanf("%d", &m_Busc);
    while(m_Busc < 1 || m_Busc > 12)
    {
        printf("Mês inválido!!!\n");
        scanf("%d", &m_Busc);
    }
    
    printf("Pessoas que nasceram no mês %d", m_Busc);
    for(int i = 0; i < q;i++)
    {
        if(phonelist[i].data.mes == m_Busc)
        {
            printarInformacoes(&phonelist[i]);
        }
    }
}

void buscaDiaeMes(Informacoes *phonelist, int q)
{
    int d,m;

    printf("Digite o Mês:\n");
    scanf("%d", &m);
    while(m < 1 || m > 12)
    {
        printf("Mês inválido!!!\n");
        scanf("%d", &m);
    }

    printf("Digite o Dia:\n");
    scanf("%d", &d);
    while((m == 2 && d > 29 || d < 1) || 
    (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12 && d > 31 || d < 1) || 
    (m == 4 || m == 6 || m == 7 || m == 9 || m == 11 && d < 1 || d > 30 ))
    {
        printf("Dia inexistente!!!\n");
        scanf("%d", &d);
        system("clear");
    }
    
    for(int i = 0; i < q; i++)
    {
        if(phonelist[i].data.dia == d && phonelist[i].data.mes == m)
        {
            printarInformacoes(&phonelist[i]);
        }
    }
}
