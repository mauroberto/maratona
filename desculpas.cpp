#include<stdio.h>

int p[50];
int v[50];
int matriz[1001][51];

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int m(int n, int w){
	int r = matriz[w][n];
	if(r != -1) return r;
	if(w <= 0) return 0;
	if(n < 0) return 0;
	int aux;
	if(p[n] <= w){
		aux = max(m(n-1,w), m(n-1, w-p[n])+v[n]);
	}else{
		aux = m(n-1, w);
	}
	matriz[w][n] = aux;
	return aux;	
}

int main(){
	int n, w, cont=1, i, j;
	scanf("%d %d", &w, &n);
	while(n != 0 && w != 0){
		for(i=0; i<n; i++){
			scanf("%d %d", &p[i], &v[i]);
		}
		
		for(i=0; i<=n; i++){
			for(j=0; j<=w; j++){
				matriz[j][i] = -1;
			}		
		}		
		
		printf("Teste %d\n", cont);
		printf("%d\n", m(n-1, w));
		printf("\n");
		cont ++;
		scanf("%d %d", &w, &n);
	}

	return 0;
}
