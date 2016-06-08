#include<stdio.h>
#include<queue>

using namespace std;

int grafo[52][52];	
int distancia[52];
int cores[52];
int n;

void BFS(int s, int k){
	distancia[s] = 0;
	cores[s] = 1;
	queue <int> q;
	q.push(s);

	while(!q.empty()){
		int v = q.front();q.pop();
		
		if(distancia[v] == k) return;

		for(int i=1; i<=n; i++){
			if(grafo[v][i] == 1 && cores[i] == 0){
				q.push(i);
				cores[i] = 1;
				distancia[i] = distancia[v]+1;
			}
		}

		cores[v] = 2;
	}
}


int main(){
	int C, E, L, P;

	int teste = 1;
	scanf("%d %d %d %d", &C, &E, &L, &P);
	while(C != 0 || E != 0 || L != 0 || P != 0){
		n = C;
		for(int i=0; i<=n; i++){
			for(int j=0; j<=n; j++){
				grafo[i][j] = 0;
			}
			cores[i] = 0;
			distancia[i] = -1;
		}
		
		while(E--){
			int x, y;
			scanf("%d %d", &x, &y);
			grafo[x][y] = grafo[y][x] = 1;
		}
		
		BFS(L, P);
		
		printf("Teste %d\n", teste);
		teste++;
		bool primeiro = true;
		for(int i=1; i<=n; i++){
			if(i != L && distancia[i] != -1 && distancia[i] <= P && primeiro){
				printf("%d", i);
				primeiro = !primeiro;
			}else if(i != L && distancia[i] != -1 && distancia[i] <= P){
				printf(" %d", i);
			}
		}
		printf("\n\n");

		scanf("%d %d %d %d", &C, &E, &L, &P);
	}
	return 0;
}


