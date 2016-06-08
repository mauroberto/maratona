#include <stdio.h>
#include <queue>

using namespace std;

int grafo[101][101];	
int distancia[101];
int cores[101];
int n;
int pai[101];


void BFS(int s){
	for(int i=0; i<=n; i++) cores[i] = 0;
	distancia[s] = 0;
	cores[s] = 1;
	pai[s] = s;
	queue <int> q;
	q.push(s);

	while(!q.empty()){
		int v = q.front();q.pop();
		
		for(int i=1; i<=n; i++){
			if(grafo[v][i] == 1 && cores[i] == 0){
				q.push(i);
				pai[i] = v;
				cores[i] = 1;
				distancia[i] = distancia[v]+1;
			}
		}

		cores[v] = 2;
	}
}

int main(){
	int k = 1;
	scanf("%d", &n);
	while(n != 0){
		for(int i=0; i<=n; i++){
			for(int j=0; j<=n; j++){
				grafo[i][j] = 0;
			}
			distancia[i] = 0;
		}
		
		int x, y;
		for(int i=0; i<n-1; i++){
			scanf("%d %d", &x, &y);
			grafo[x][y] = grafo[y][x] = 1;
		}
		printf("Teste %d\n", k);
		k++;
		BFS(1);
		
		int max = 1;
		for(int i=1; i<=n; i++){
			if(distancia[i] > distancia[max]) max = i;
		}

		//printf("max %d\n", max);

		BFS(max);	
		
		int max2 = max;
		for(int i=1; i<=n; i++){
			if(distancia[i] > distancia[max2]) max2 = i;
		}	
		//printf("max %d\n", max2);		
		
		//printf("distancia %d\n", distancia[max]);
		int v = max2;
		while(v != max){
			if(distancia[v] == (distancia[max2]/2)){
				printf("%d\n", v);
				break;
			}
			v = pai[v];
		}

		if(v == max) printf("%d\n", max);
		
		printf("\n");
		scanf("%d", &n);
	}

	return 0;
}
