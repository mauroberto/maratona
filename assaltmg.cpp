#include<stdio.h>
#include<iostream>
unsigned int v[21];

using namespace std;

typedef struct soma {
	int existe;
	int qtdNum;
	unsigned int mask;
}soma;

int n, w;

int min(int a, int b){ return a < b ? a : b;}

soma matriz[21][33];

soma m(int n, unsigned int st){
	for (int i=0;i<=n;i++){
		for (int j=0;j<=st;j++){
			if(j == 0){
				matriz[i][j].existe = 1;
				matriz[i][j].qtdNum = 0;
			}else{
				matriz[i][j].existe = 0;
			}
			matriz[i][j].mask = 0;
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=st; j>=0; j--){
			matriz[i][j] = matriz[i-1][j];
			if(matriz[i][j].existe){
				unsigned int bits = matriz[i][j].mask|v[i];
				int qtdBits = __builtin_popcount(bits);
				if(qtdBits <= st && matriz[i-1][qtdBits].existe){
					matriz[i][qtdBits].existe = 1;
					matriz[i][qtdBits].qtdNum = min(matriz[i-1][qtdBits].qtdNum, matriz[i][j].qtdNum + 1);
					matriz[i][qtdBits].mask = bits;
				}else if(qtdBits <= st){
					matriz[i][qtdBits].existe = 1;
					matriz[i][qtdBits].qtdNum = matriz[i][j].qtdNum + 1;
					matriz[i][qtdBits].mask = bits;
				}
			}
		}
	}
	
	soma menor;
	menor.existe = 0;
	menor.qtdNum = n+1;
	for(int i=w; i<=st; i++){
		if(matriz[n][i].existe && matriz[n][i].qtdNum < menor.qtdNum){
			menor = matriz[n][i];
		}
	}
	return menor;	
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		unsigned int s = 0;
		scanf("%d %d", &w, &n);
		for(int i = 1; i <= n; i++){
			int qtd, c;
			unsigned chaves = 0;
			scanf("%d", &qtd);
			v[i] = qtd;
			for(int j=0; j<qtd; j++){
				scanf("%d", &c);
				chaves|=1u<<c;
			}	
			v[i] = chaves;			
			s |= v[i];
		}
		soma soma = m(n,__builtin_popcount(s));

		if(soma.existe) printf("%d\n", soma.qtdNum);
		else printf("Desastre!\n");
	}
}
