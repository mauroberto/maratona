#include<stdio.h>
#define N 7

int x[8] = {-1, 1,-1, 1,-2,-2, 2, 2};
int y[8] = {-2,-2, 2, 2,-1, 1,-1, 1};
int encontrou = 0;
int tab[N][N];
int sub=0;

void imprimir(){
	int i, j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%d ",tab[i][j]);
		}
		printf("\n");
	}
}
void cavalo(int i, int j, int k){
	sub++;
	if(k > (N*N)) {
		encontrou = 1;
		imprimir();
		return;
	}
	if(i<0 || i>=N || j<0 || j>=N) return;
	if(tab[i][j] != 0) return;
		
	tab[i][j] = k;
	int l;
	for(l=0; l<8; l++){
		cavalo(i+x[l], j+y[l], k+1);
		if(encontrou) return;
	}	

	tab[i][j] = 0;
}


int main(){
	int i, j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			tab[i][j] = 0;
		}
	}	
	cavalo(0, 0, 1);
	if(encontrou) printf("Encontrou\n");	
	printf("%d\n", sub);
}
