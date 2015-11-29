#include<stdio.h>

int n, m;
char matriz[82][52];
int a[] = {-1,-1,-1, 0, 0, 1, 1, 1}; 
int b[] = {-1, 0, 1, 1,-1, 1, 0,-1};

void destruirConstrucao(int x, int y){
	if(matriz[x][y] == '0') return;
	int i;
	matriz[x][y] = '0';
	for(i=0; i<8; i++){
		destruirConstrucao(x + a[i], y + b[i]);
	}
}

int procurarConstrucao(){
	int i, j, cont=0;
	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++){
			if(matriz[i][j] != '0') {
				destruirConstrucao(i, j);
				cont++;
			}
		}
	}

	return cont;
}

int main(){
	scanf("%d%d", &n, &m);
	int i, j;
	for(i=1; i<=n; i++){
		scanf("%s", &matriz[i][1]);
	}

	for(i=0; i<=m; i++){
		matriz[0][i] = '0';
		matriz[n+1][i] = '0';
	}

	for(i=0; i<=n; i++){
		matriz[i][0] = '0';
		matriz[i][m+1] = '0';
	}


	printf("%d\n", procurarConstrucao());
}
