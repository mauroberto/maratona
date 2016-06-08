#include<stdio.h>


int p, n;
int matriz[21][31];
int nP[21], w[21];

int max(int a, int b){return a > b ? a : b;};

int main(){
	scanf("%d", &n);
	while(n != 0){
		scanf("%d", &p);
		for(int i=1; i<=n; i++){
			scanf("%d %d", &nP[i], &w[i]);
		}
		
		for(int i=0; i<=p; i++) matriz[0][i] = 0;
		
		for(int i=1; i<=n; i++){
			for(int j=0; j<=p; j++){
				if(w[i] > j){
					matriz[i][j] = matriz[i-1][j]; 
				}else{
					matriz[i][j] = max(matriz[i-1][j], matriz[i-1][j-w[i]] + nP[i]);
				}
			}
		}

		/*for(int i=0; i<=n; i++){
			for(int j=0; j<=p; j++){
				printf("%d ", matriz[i][j]);
			}
			printf("\n");
		}*/

		printf("%d min.\n", matriz[n][p]);
		scanf("%d", &n);
	}
	return 0;
}
