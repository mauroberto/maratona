#include<stdio.h>

int linhas[9][9];
int colunas[9][9];
int matrizes[9][9];

int main(){
	int k, n, i, j;
	scanf("%d", &k);
	for( n = 1; n <= k; n++){
		for(i=0; i<9; i++){
			for(j=0; j<9; j++){
				linhas[i][j] = 0;
				colunas[i][j] = 0;
				matrizes[i][j] = 0;
			}
		}
		
		int r = 1, valor;
		for(i=0; i<9; i++){
			for(j=0; j<9; j++){
				scanf("%d", &valor);
				valor--;
				linhas[i][valor]++;
				colunas[j][valor]++;
				if(linhas[i][valor] > 1) r=0;
				if(colunas[j][valor] > 1) r=0;
				
				if(i<3){
					if(j < 3){
						matrizes[0][valor]++;
						if(matrizes[0][valor] > 1) r=0;
					}else if(j<6){
						matrizes[1][valor]++;
						if(matrizes[1][valor] > 1) r=0;
					}else{
						matrizes[2][valor]++;
						if(matrizes[2][valor] > 1) r=0;
					}
				}else if(i<6){
					if(j < 3){
						matrizes[3][valor]++;
						if(matrizes[3][valor] > 1) r=0;
					}else if(j<6){
						matrizes[4][valor]++;
						if(matrizes[4][valor] > 1) r=0;
					}else{
						matrizes[5][valor]++;
						if(matrizes[5][valor] > 1) r=0;
					}
				}else{
					if(j < 3){
						matrizes[6][valor]++;
						if(matrizes[6][valor] > 1) r=0;
					}else if(j<6){
						matrizes[7][valor]++;
						if(matrizes[7][valor] > 1) r=0;
					}else{		
						matrizes[8][valor]++;
						if(matrizes[8][valor] > 1) r=0;
					}
				}
			}
		}


		printf("Instancia %d\n", n);
		if(r) printf("SIM\n");
		else printf("NAO\n");
		printf("\n");
	}
	return 0;
}
