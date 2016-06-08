#include<stdio.h>

int matriz[2002][2002];
int cores[2002];
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
	scanf("%d", &n);
	while(n != 0){
		scanf("%d", &a);
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				matriz[i][j] = 0;
			}
		}
		
		for(int i=1; i<=n; i++){
			cores[i] = 0;
		}
	
		int x, y, z;
		while(a--){
			scanf("%d %d %d", &x, &y, &z);
			if(z == 1){
				matriz[x][y] = 1;
			}else{
				matriz[x][y] = matriz[y][x] = 1;
			}
		}
		int j;
    		for(j=1; j<=n; j++){
			dfs(j);
			int i;
			for(i=1; i<=n; i++){
				if(cores[i] == 0)
					break;
			}

			if(i != n+1){
				printf("0\n");
				break;
			}

			for(int i=1; i<=n; i++){
				cores[i] = 0;
			}
		}
		if(j == n+1){
			printf("1\n");
		}
		scanf("%d", &n);
	}
	return 0;
}
