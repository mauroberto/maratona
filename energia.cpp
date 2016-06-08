#include<stdio.h>

int matriz[101][101];
int cores[101];
int n, a;

void dfs(int s){
	cores[s] = 1;
	for(int i=1; i<=n; i++){
		if(matriz[s][i] == 1 && cores[i] == 0)
			dfs(i);
	}
	cores[s] = 2;
}

int main(){
	scanf("%d %d", &n, &a);
	int c = 1;
	while(n != 0 || a != 0){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				matriz[i][j] = 0;
			}
		}
		
		for(int i=1; i<=n; i++){
			cores[i] = 0;
		}
	
		int x, y;
		while(a--){
			scanf("%d %d", &x, &y);
			matriz[x][y] = matriz[y][x] = 1;
		}

		dfs(1);
		int i;
		for(i=1; i<=n; i++){
			if(cores[i] == 0)
				break;
		}
		
		printf("Teste %d\n", c);
		c++;
		if(i == n+1){
			printf("normal\n");
		}else{
			printf("falha\n");
		}
		printf("\n");
		scanf("%d %d", &n, &a);
	}
	return 0;
}
