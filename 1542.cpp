#include<stdio.h>

/*
q*x = p(x-d)
q*x = p*x - p*d
(p-q)*x = p*d
x = (p*d)/(p-q)


*/

int main(){
	float q, d, p;
	
	scanf("%f", &q);
	while(q != 0){
		scanf("%f %f", &d, &p);
		int x = (int)(p*d*q/(p-q));
		if(x < 0){
			x*=-1;
		}
		
		if(x == 1){
			printf("1 pagina\n");
		}else{
			printf("%d paginas\n", x);
		}
		scanf("%f", &q);
	}

	return 0;
}
