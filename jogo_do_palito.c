#include<stdio.h>
#define MAX 1000000

int n, m;
int matriz[MAX][2];

int min(int a, int b){ 
	return b > a ? a : b;
}
int max(int a, int b){ 
	return b < a ? a : b;
}

int jogo(int modo, int no){
	if(matriz[no][modo] != -1) return matriz[no][modo];
	if(no <= m){
		return modo;
	}

	int valor = 0;
	if (modo == 0) valor = 1;
	int i;
	for(i=1; i<=m; i++){
		if(modo == 1){
			valor = max(valor, jogo(0, no-i));
		}else{
			valor = min(valor, jogo(1, no-i));
		}
	} 
	matriz[no][modo] = valor;
	return valor;
}

int main(){
	scanf("%d %d", &n, &m);
	int i, j;
	for(i=0; i<MAX; i++){
		for(j=0; j<2; j++){
			matriz[i][j] = -1;
		}
	}
	if(jogo(1, n)) printf("Primeiro Jogador\n");
	else printf("Segundo Jogador\n");
}
