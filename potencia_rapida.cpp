#include<stdio.h>

int potencia(int a, int b, int m){
	if(b == 0) return 1;
	int d = b/2;
	int r = potencia(a, d, m);
	if(b&1){
		return r*r*a;
	}else{
		return r*r;
	}
}

int main(){
	printf("%d\n", potencia(10,7,1));
}
