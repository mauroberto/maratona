#include<stdio.h>
int posX,posY;
int n, m;
int v[12][12];
int cores[12][12];
int a[] = {1,-1, 0, 0};
int b[] = {0, 0, 1,-1};

int forcaBruta(int x, int y){
	if(v[x][y] == 0) return 1;
	else if(v[x][y] == 1){
		int i;
		cores[x][y] = 1;
		int valor = 9999999;
		for(i=0; i<4; i++){
			int proxX = x+a[i];
			int proxY = y+b[i];
			if(cores[proxX][proxY] == 0 && v[proxX][proxY] != 2){
				int fb = forcaBruta(proxX, proxY);
				if(fb < valor){
					valor = fb;
				}
				cores[proxX][proxY] = 0;
			}
		} 
		return valor+1;
	}
}

int main(){
	int i,j;
	scanf("%d%d", &n, &m);
	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++){
			scanf("%d", &v[i][j]);
			cores[i][j] = 0;
			if(v[i][j] == 3){
				posX = i;
				posY = j;
			}
		}
	}

	for(i=0; i<=m; i++){
		v[0][i] = 2;
		v[n+1][i] = 2;
	}

	for(i=0; i<=n; i++){
		v[i][0] = 2;
		v[i][m+1] = 2;
	}

	printf("%d\n", forcaBruta(posX, posY));
}
