//https://projecteuler.net/index.php?section=problems&id=018

#include<stdio.h>
#define N 100
int m[N][N];
int mAux[N][N];

int max(int a, int b){return a > b ? a: b;}

int pd(){
	for(int i=0; i<N; i++) mAux[N-1][i] = m[N-1][i]; 
	for(int i=N-2; i>=0; i--){
		for(int j=0; j<=i; j++){
			mAux[i][j] = m[i][j];
			mAux[i][j] += max(mAux[i+1][j], mAux[i+1][j+1]);
		}
	}

	return mAux[0][0];
}

int main(){
	for(int i=0; i<N; i++){
		for(int j=0; j<=i; j++){
			scanf("%d", &m[i][j]);
		}
	}

	printf("%d\n", pd());
}
