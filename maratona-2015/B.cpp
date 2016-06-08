#include<stdio.h>
int matriz[10001][10001];
int vetor[10001];
int n, c;

int max(int a, int b){ return a > b ? a : b;}

int main(){
	scanf("%d %d", &n, &c);
	for(int i=1; i<=n; i++){
		scanf("%d", &vetor[i]);
	}
	for(int i=0; i<=n; i++) matriz[i][0] = 0;
	
	//for(int i=1; i<=n; i++) matriz[i][i] = 0;

	for(int i=1; i<=n; i++){
		for(int j = i; j<=n; j++){
			int p = max(vetor[j]-vetor[i]-c, 0);
			matriz[j][i] = max(matriz[i-1][i-1]+p, max(matriz[j][i-1], matriz[j-1][i]));
		}
	}

	/*printf("    ");
	for(int i=0; i<=n; i++){
		if(vetor[i] < 10) printf("  ");
		else if(vetor[i] < 100) printf(" ");			
		printf("%d ", vetor[i]);
	}
	printf("\n");

	for(int i=0; i<=n; i++){
		if(vetor[i] < 10) printf("  ");
		else if(vetor[i] < 100) printf(" ");
		printf("%d ", vetor[i]);
		for(int j=0; j<=n; j++){
			if(matriz[i][j] < 10) printf("  ");
			else if(matriz[i][j] < 100) printf(" ");
			printf("%d ", matriz[i][j]);	
		}
		printf("\n");
	}*/

	printf("%d\n", matriz[n][n-1]);
	
	return 0;
}
