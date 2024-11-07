#include <stdio.h>

void ehPrimo(int p);
void divisores(int p);

int main()
{
    int p;
    printf("Digite um número para se determinar se ele é primo:\n");
    scanf("%d",&p);
    
    ehPrimo(p);

    return 0;
}

void ehPrimo(int p)
{
    int div = 0;
    for(int i = 1;i <= p;i++)
    {
        if(p % i == 0)
        {
            div++;
        }
    }
    if(div == 2)
    {
        printf("%d é primo!",p);
        return;
    }
    else if(div != 2)
    {
        printf("%d não é primo!\n",p);
        divisores(p);
    }
    
}
void divisores(int p)
{
    int divsres[p], t = 0;
    for(int j = 1; j <= p; j++)
    {
        if(p % j == 0)
        {
            divsres[t] = j;
            t++;
        }
    }
    printf("Seus divisores são:\n");
    for(int l = 0; l < t;l++)
    {
        printf("%d\n",divsres[l]);
    }
}