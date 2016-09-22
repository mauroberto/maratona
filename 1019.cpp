#include<stdio.h>

int main(){
	int tempo;

	scanf("%d", &tempo);

	int horas = tempo/3600;

	tempo -= 3600*horas;

	int minutos = tempo/60;
	
	tempo -= minutos*60;

	printf("%d:%d:%d\n", horas, minutos, tempo);

	return 0;
}
