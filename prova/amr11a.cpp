#include<stdio.h>

int s[501][501],pdm[501][501], c, r;

int min(int a, int b){return a > b ? b : a;}

int max(int a, int b){return a < b ? b : a;}

int ab(int a){ return a < 0 ? a*-1: a;}

int rec(int i, int j){
	if(i == r-1 && j == c-1){
		return 1;
	}else{
		int chamada1 = 0x7FFFFFFF;
		int chamada2 = 0x7FFFFFFF;
		if(i+1 < r)		
			chamada1 = max(rec(i+1, j)-s[i][j], 1);
		if(j+1 < c)
			chamada2 = max(rec(i, j+1)-s[i][j], 1);

		return min(chamada1, chamada2);
	}
}

int pd(){
	pdm[r-1][c-1] = 1;

	for(int i=c-2; i>=0; i--){
		if(pdm[r-1][i+1] - s[r-1][i] > 0){
			pdm[r-1][i] = pdm[r-1][i+1]-s[r-1][i];		
		}else{
			pdm[r-1][i] = 1;
		}
	}
	
	for(int i=r-2; i>=0; i--){
		if(pdm[i+1][c-1] - s[i][c-1] > 0){
			pdm[i][c-1] = pdm[i+1][c-1]-s[i][c-1];
		}else{
			pdm[i][c-1] = 1;
		}
	}
	
	for(int i=r-2; i>=0; i--){
		for(int j=c-2; j>=0; j--){
			int menor = min(pdm[i+1][j], pdm[i][j+1]);
			if(menor-s[i][j] > 0){
				pdm[i][j] = menor-s[i][j];
			}else{
				pdm[i][j] = 1;
			}
		}
	}

	return pdm[0][0];
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &r, &c);
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				scanf("%d", &s[i][j]);
			}
		}
		printf("%d\n", pd());
	}
}
