#include<stdio.h>
#include<cmath>

int main(){
	int n, count, entrada;
	scanf("%d", &n);
	while(n != 0){
		entrada=n;
		count = 1;
		int i=2, limite = sqrt(n);
		while(n > 1 && limite >= i){
			int c = 0;
			while(n%i == 0){
				n /= i;
				c++;
			}
			if(c > 0) count *= c+1;
			i++;
		}

		if(n>1) count*=2;
		printf("%d : %d\n", entrada, count);
		scanf("%d", &n);
	}
}
