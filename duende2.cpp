#include <stdio.h>
#include <queue>

using namespace std;

typedef pair<int , int> pi;

int cor[12][12];
int matriz[12][12];
int distancia[12][12];
int a[] = {-1, 0, 0,1};
int b[] = { 0,-1, 1,0};
int n, m;

int bfs(pi raiz){
	queue<pi> q;
	cor[raiz.first][raiz.second] = 1;
	q.push(raiz);
	distancia[raiz.first][raiz.second] = 0;
	
	while(!q.empty()){
		pi ve = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){

			int x = ve.first + a[i];
			int y = ve.second + b[i];
			distancia[x][y] = distancia[ve.first][ve.second]+1;

			if(matriz[x][y] == 0) return distancia[x][y];
			else if(matriz[x][y] != 2 && cor[x][y] == 0){
				cor[x][y] = 1;
				pi b(x,y);
				q.push(b);
			}
		}
	}

	return 0;
}

int main(){

	scanf("%d %d", &n, &m);
	int comecoX, comecoY;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int valor;
			scanf("%d",&valor);

			if(valor == 3){
				comecoX = i;
				comecoY = j;
			}

			matriz[i][j] = valor;
			cor[i][j] = 0;
		}
	}

	for(int i = 0; i <= n; i++){
		matriz[i][0] = 2;
		matriz[i][m+1] = 2;
	}

	for(int i = 0; i <= m; i++){
		matriz[0][i] = 2;
		matriz[n+1][i] = 2;
	}
	pi raiz(comecoX,comecoY);
	printf("%d\n", bfs(raiz));

	return 0;
}
