#include<stdio.h>
#include<string.h>

int main(){
	char nome[200];
	double salario, vendas;
	scanf("%s", nome);
	scanf("%lf", &salario);
	scanf("%lf", &vendas);

	printf("TOTAL = R$ %.2lf\n", salario+(0.15*vendas));
	return 0;
}
