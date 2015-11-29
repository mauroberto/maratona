#include<stdio.h>

int i;
int n = 10;
int p[10];
int qtd = 0;
int marc[11];

void permute(int k, int j){
	int i;
	if(k > 0){
		for(i=1; i <= k; i++){
			p[j] = i;
			permute(k-i, j+1);
		}
	}else{
		printf("[");
		for(i=0; i<j; i++)
			printf("%d ", p[i]);
		printf("]\n");
		j=0;
		qtd++;
	}
}

int main(){
	permute(5,0);
	printf("%d", qtd);
	return 0;
}
