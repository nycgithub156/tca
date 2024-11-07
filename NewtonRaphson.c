#include <stdio.h>

int main()
{
    double x[200];
    double N;
    int terms;
    printf("Qual a raiz procurada:\n");
    scanf("%lf", &N);
    printf("Quantos termos?\n");
    scanf("%d", &terms);
    
    printf("Digite o termo inicial:\n");
    scanf("%lf", &x[0]);
    
    for(int i = 0; i < terms; i++)
    {
        x[i + 1] = x[i] - ((x[i]*x[i]) - N)/(2 * (x[i]));
    }
    printf("O valor aproximado da raiz de %.lf é: %.16lf", N, x[terms - 1]);

    return 0;
}
