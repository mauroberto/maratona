#include<stdio.h>
#include<queue>
#include<strings.h>

using namespace std;

char grafo[101][101];
int d[101][101];
int c[101][101];
int n;
int x[4] = {1, -1, 0, 0};
int y[4] = {0,  0, 1,-1};
int caminho[101][101];

char converterCase(int letra){
	if(letra >= 65 && letra <= 90){
		return letra+32;
	}else{
		return letra-32;
	}
}

int adicionarLetra(int lista, char letra){
	int pos;

	if(letra >= 65 && letra <= 90){
		pos = letra-65;
	}else{
		pos = letra-87;
	}
	
	lista |= 1<<pos;

	return lista;
}


bool caminhoValido(int caminho, char letra){
	int pos;
	if(letra >= 65 && letra <= 90){
		pos = letra-55;
	}else{
		pos = letra-97;
	}

	if(caminho & (1<<pos)){
		return false;
	}
	return true;
}

int BFS(){
	int origem = grafo[1][1];
	int destino = grafo[n][n];
	int lista = 0;
	
	queue<pair<int, int> > q;
	q.push(make_pair(1, 1));
	d[1][1] = 1;
	
	
	lista = adicionarLetra(lista, origem);
	lista = adicionarLetra(lista, destino);

	caminho[1][1] = lista;

	
	for(int i=1; i<=n; i++){ 
		for(int j=1; j<=n; j++){
			c[i][j] = 0;
		}
	}
	
	c[1][1] = 1;
	while(!q.empty()){
			
		pair<int, int> p = q.front();
		q.pop();
		
		for(int i=0; i<4; i++){
			int posX = p.first + x[i];
			int posY = p.second + y[i];
			int novoCaminho = adicionarLetra(caminho[p.first][p.second], grafo[posX][posY]);
			if(caminhoValido(novoCaminho, grafo[posX][posY])){
				pair<int, int> p2 = make_pair(posX, posY);
				q.push(p2);
				d[posX][posY] = 1+d[p.first][p.second];
				if(posX == n && posY == n){
					return d[posX][posY];
				}
				caminho[posX][posY] = novoCaminho;
			}
		}				
		c[p.first][p.second] = 2;	
	}

	return d[n][n];		
}


int main(){
	scanf("%d", &n);
	int i, j;
	for(i=1; i<=n; i++){
		scanf("%s", &grafo[i][1]);
	}

	char aux = converterCase(grafo[n][n]);

	for(i=0; i<=n+1; i++){
		grafo[0][i] =  aux;
		grafo[n+1][i] = aux;
	}

	for(i=0; i<=n+1; i++){
		grafo[i][0] = aux;
		grafo[i][n+1] = aux;
	}
	
	for(int i=0; i<=n+1; i++){
		for(int j=0; j<=n+1; j++){
			printf("%c",grafo[i][j]);
		}	
		printf("\n");
	}

	int r = BFS();
	printf("%d\n", r);
	if(c[n][n] == 0) printf("-1\n");
	else printf("%d\n", r);	

	printf("\n");
	return 0;
}

