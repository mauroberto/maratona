#include<stdio.h>
#include<vector>
#include<queue>
#include<map>

using namespace std;

char cenario[11][10];

struct Estado{
	int x; 
	int y;
	map<pair<int,int>, int> inimigos;
	map<pair<int,int>, int> destrocos;
	int nivel;

	bool operator< (const Estado& e) const;
	bool operator== (Estado& e);
};

bool Estado::operator<(const Estado& e)const{
	if(nivel < e.nivel){
		return true;
	}else if(nivel == e.nivel && inimigos.size() > e.inimigos.size()){
		return true;
	}
	return false;
}

bool Estado::operator== (Estado& e){
	if(x == e.x && y == e.y && nivel == e.nivel && inimigos.size() == e.inimigos.size() && destrocos.size() == e.destrocos.size()){
		map<pair<int,int>, int>:: iterator it2;
		for(map<pair<int,int>, int>:: iterator it = inimigos.begin(); it!=inimigos.end(); ++it){
			it2 = e.inimigos.find(it->first);
			if(it2 == e.inimigos.end()){
				return false;
			}
		}
		
		return true;
	}
	return false;
}



int mX[8] = { 1,-1,-1, 1, 1,-1, 0, 0};
int mY[8] = {-1, 1,-1, 1, 0, 0,-1, 1};

map<Estado,bool> vis;

bool bfs(){
	queue<Estado> fila;
	int cont = 1;
	Estado origem;
	origem.nivel = 1;

	vis.clear();
	/*for(int i=0; i<11; i++){
		for(int j=0; j<10; j++){
			for(int k=0; k<10; k++){
				vis[i][j][k] = false;
			}
		}
	}*/

	for(int i=1; i<=9; i++){
		for(int j=1; j<=8; j++){
			if(cenario[i][j] == 'E'){
				pair<int, int> p = make_pair(j, i);
				origem.inimigos.insert(make_pair(p, cont));
				cont++;
			}else if(cenario[i][j] == 'S'){
				origem.x = j;
				origem.y = i;
			}
		}
	}
	
	fila.push(origem);
	while(!fila.empty()){
		//printf("Fila %lu\n", fila.size());
		Estado estado = fila.front();
		fila.pop();
		
		//printf("%d\n", estado.nivel);
		
		/*if(vis[estado.y][estado.x][estado.nivel] == true){
			continue;
		}else{
		   	vis[estado.y][estado.x][estado.nivel] = true;
		}*/

		map<Estado, bool>:: iterator it5 = vis.find(estado);

		if(it5 == vis.end()){
			vis.insert(make_pair(estado,true));
		}else{
			continue;
		}

		if(estado.nivel <= 10 && estado.inimigos.size() == 0){
			//printf("size %lu\n", estado.inimigos.size());
			return true;
		}else if(estado.nivel == 10){
			continue;
		}
		
		map<pair<int,int>, int>:: iterator it = estado.inimigos.find(make_pair(estado.x, estado.y));
		
		//if(it != estado.inimigos.end()) continue;

		for(int i=0; i<8; i++){
			int nX = estado.x + mX[i];
			int nY = estado.y + mY[i];
			it = estado.destrocos.find(make_pair(nX, nY));
			map<pair<int,int>, int>:: iterator it2 = estado.inimigos.find(make_pair(nX, nY)); 
			if(cenario[nY][nX] != '#' && it == estado.destrocos.end() && it2 == estado.inimigos.end()){				
				Estado filho;
				filho.nivel = estado.nivel+1;
				filho.x = nX;
				filho.y = nY;
				filho.destrocos = estado.destrocos;
				
				//printf("Jogador %d %d\n", nX, nY);
				for(it = estado.inimigos.begin(); it!=estado.inimigos.end(); ++it){
					int iniY, iniX, inimigo;
					inimigo = it->second;

					if(it->first.first > nX){
						iniX = it->first.first-1;
					}else if(it->first.first < nX){
						iniX = it->first.first+1;	
					}else{
						iniX = it->first.first;
					}

					if(it->first.second > nY){
						iniY = it->first.second-1;
					}else if(it->first.second < nY){
						iniY = it->first.second+1;
					}else{
						iniY = it->first.second;
					}				

					//printf("Inimigo %d %d %d\n", inimigo, iniX, iniY);
					it2 = filho.inimigos.find(make_pair(iniX, iniY)); 
					map<pair<int,int>, int>:: iterator it3 = filho.destrocos.find(make_pair(iniX, iniY)); 
					
					if(it2 == filho.inimigos.end() && it3 == filho.destrocos.end() && cenario[iniY][iniX] != '#'){
						filho.inimigos.insert(make_pair(make_pair(iniX, iniY), inimigo));
						//printf("Adicionando inimigo %d - size %lu\n", inimigo, filho.inimigos.size());
					}else{
						if(it2 != filho.inimigos.end()){
							filho.inimigos.erase(make_pair(iniX,iniY));
							filho.destrocos.insert(make_pair(make_pair(iniX,iniY), inimigo));
							//printf("Removendo inimigo %d- size %lu\n", inimigo, filho.inimigos.size());
						}
						//printf("Inserindo destroços %d - size %lu\n", inimigo, filho.inimigos.size());							
					}
				}
				it = filho.inimigos.find(make_pair(nX,nY));
				it2 = filho.destrocos.find(make_pair(nX,nY));
				if(it == filho.inimigos.end() && it2 == filho.destrocos.end()){
					//printf("ADD FILA %d %d\n", nX, nY);
					fila.push(filho);
				}else{
					//printf("Iterator %d %d\n", it->first.first, it->first.second);
				}
			}
		}
	}

	return false;
}

int main(){
	int k;

	scanf("%d", &k);
	
	for(int i=0; i<=10; i++){
		cenario[i][0] = '#';
		cenario[i][9] = '#';
	}
	
	for(int i=0; i<=9; i++){
		cenario[0][i] = '#';
		cenario[10][i] = '#';
	}	

	while(k--){
		
		for(int i=1; i<=9; i++){
			scanf("%s", &cenario[i][1]);
			cenario[i][9] = '#';
		}

		/*for(int i=0; i<=10; i++){
			for(int j=0; j<=9; j++){
				printf("%c", cenario[i][j]);
			}
			printf("\n");
		}*/
		if(bfs()){
			printf("I'm the king of the Seven Seas!\n");
		}else{
			printf("Oh no! I'm a dead man!\n");
		}
	}
}


