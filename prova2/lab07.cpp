#include<queue>
#include<stdio.h>

using namespace std;

typedef struct estado{
	int x;
	int y;
	int turno;
}Estado; 

int matriz[51][51];

int mX[5] = {0, 1,-1, 0, 0};
int mY[5] = {0, 0, 0,-1, 1};

int N, M;
int resultado;
bool vis[51][51][10];

void bfs(){
	queue<Estado> fila;
	Estado origem;
	origem.x = 1;
	origem.y = 1;
	origem.turno = 0;
	fila.push(origem);
	
	

	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			for(int l=0; l<=9; l++){
				vis[i][j][l] = false;
			}
		}
	}
	while(!fila.empty()){
		Estado estado = fila.front();
		fila.pop();
		
		if(vis[estado.y][estado.x][estado.turno%10] == true){
			continue;
		}else{
		   	vis[estado.y][estado.x][estado.turno%10] = true;
		}

		if(estado.x == M && estado.y == N && resultado > estado.turno){
			resultado = estado.turno;
			break;
		}

		for(int i=0; i<5; i++){
			int nX = estado.x + mX[i];
			int nY = estado.y + mY[i];
			int hProx = (matriz[nY][nX]+estado.turno)%10;
			int h = (matriz[estado.y][estado.x]+estado.turno)%10;
			
			if(nY <= N && nX <= M && nY > 0 && nX > 0 && hProx <= h+1){				
				Estado filho;
				filho.turno = estado.turno+1;
				filho.x = nX;
				filho.y = nY;
				fila.push(filho);
			}
		}
	}
}


int main(){
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			scanf("%d", &matriz[i][j]);
		}
	}

	resultado = 0x7FFFFFFF;
	bfs();
	printf("%d\n", resultado);			
	return 0;
}
