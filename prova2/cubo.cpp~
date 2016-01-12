#include <iostream>
#include <queue>
#include <stdio.h>
#include <map>

using namespace std;

enum Direcao {Direita, Esquerda, Cima, Baixo};

pair<int, int> posicaoDestino;
pair<int, int> posicaoInicialBloco;
pair<int, int> posicaoInicialDoPersonagem;

typedef struct estado{
	int nivel;
	int empurroes;
	int origem;
	pair<int,int> posicaoPersonagem;
	pair<int,int> posicaoBloco;

	bool operator< (const estado& e) const;

}Estado;

bool Estado::operator<(const Estado& e)const{
	if(empurroes < e.empurroes){
		return true;
	}else if(empurroes == e.empurroes && nivel < e.nivel){
		return true;
	}else{
		return false;
	}
}

Estado melhorEstadoFinal;

char cubo[22][22];
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, -1, 1};

int n, m;


void bfs(Estado origem){

	queue<Estado> fila;
	
	map <Estado, pair<int, int> > custo;
  	map <Estado, pair<int, int> >::iterator it;
	fila.push(origem);

	while(!fila.empty()){

		Estado estado = fila.front();
		fila.pop();		

		if(estado.posicaoBloco.first == posicaoDestino.first && estado.posicaoBloco.second == posicaoDestino.second && estado < melhorEstadoFinal){
			printf("%d\n",estado.nivel);
			melhorEstadoFinal = estado;
			continue;
		}
		
		if(melhorEstadoFinal < estado){
			continue;
		}
		
		it = custo.find(estado);

		if(it == custo.end()){
		      custo[estado] = make_pair(estado.empurroes, estado.nivel);
		}else{
		      if( estado.empurroes > it->second.first ){
			continue;
		      }else if(estado.empurroes == it->second.first && estado.nivel > it->second.second){
			continue;
		      }else{	
			custo[estado] = make_pair(estado.empurroes, estado.nivel);
		      }
		}

		for(int dir = Direita; dir <= Baixo; dir++){			
			/*if(dir == estado.origem)
				continue;*/

			pair<int, int> posicaoAtual = estado.posicaoPersonagem;
			pair<int, int> novaPosicaoDoPersonagem = make_pair(posicaoAtual.first+x[dir], posicaoAtual.second+y[dir]);

			int posX, posY;
			posX = posicaoAtual.first+x[dir];
			posY = posicaoAtual.second+y[dir];
			char coisaAtual = cubo[posX][posY];
			char coisaAtual2 = cubo[posX+x[dir]][posY+y[dir]];
			

			if(!(coisaAtual == '#' || (estado.posicaoBloco.first == novaPosicaoDoPersonagem.first && estado.posicaoBloco.second == novaPosicaoDoPersonagem.second && coisaAtual2 == '#'))){
				Estado novoEstado;

				novoEstado.posicaoPersonagem = novaPosicaoDoPersonagem;
				if(dir&1){
					novoEstado.origem = dir-1;
				}else{
					novoEstado.origem = dir+1;
				}
				novoEstado.nivel = estado.nivel + 1;
								
				if(estado.posicaoBloco ==  novoEstado.posicaoPersonagem){
					novoEstado.posicaoBloco = make_pair(estado.posicaoBloco.first+x[dir], estado.posicaoBloco.second+y[dir]);
					novoEstado.empurroes = estado.empurroes+1;
				}else{
					novoEstado.posicaoBloco = estado.posicaoBloco;
					novoEstado.empurroes = estado.empurroes;
				}

				fila.push(novoEstado);
			}
	   	 }
	}
}

int main(){
	scanf("%d %d", &n, &m);
	
	while(n != 0 || m != 0){
		melhorEstadoFinal.empurroes = 0x7fffffff;
		melhorEstadoFinal.nivel = 0x7fffffff;

		for(int i=1; i<=n; i++){
			scanf("%s", &cubo[i][1]);
		}

		for(int i=0; i<=n+1; i++){
			cubo[i][0] = '#';
			cubo[i][m+1] = '#';
		}

		for(int i=0; i<=m+1; i++){
			cubo[0][i] = '#';
			cubo[n+1][i] = '#';
		}

		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(cubo[i][j] == 'T'){
					posicaoDestino = make_pair(i, j);
				}else if(cubo[i][j] == 'B'){
					posicaoInicialBloco = make_pair(i, j);
				}else if(cubo[i][j] == 'S'){
					posicaoInicialDoPersonagem = make_pair(i, j);
				}
			}
		}


		/*for(int i=0; i<=n+1; i++){
			for(int j=0; j<=m+1; j++){
				printf("%c", cubo[i][j]);
			}

			printf("\n");
		}*/
	
		Estado origem;
		origem.empurroes = 0;
		origem.nivel = 0;
		origem.posicaoBloco = posicaoInicialBloco;
		origem.posicaoPersonagem = posicaoInicialDoPersonagem;
		origem.origem = -1;
		
		printf("%d %d\n", posicaoInicialDoPersonagem.first, posicaoInicialDoPersonagem.second);

		queue<Estado> fila;
		bfs(origem);

		if(melhorEstadoFinal.empurroes != 0x7fffffff){
			printf("%d %d", melhorEstadoFinal.empurroes, melhorEstadoFinal.nivel);	
		}else{
			printf("Impossível");
		}
	
		printf("\n");

		scanf("%d %d", &n, &m);
	}
	return 0;
}
