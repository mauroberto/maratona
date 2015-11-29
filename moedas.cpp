#include<stdio.h>

int v[50001];
int matriz[50001];

using namespace std;

int min(int a, int b) {
	return a > b ? b : a;
}

int moedas(int n, int w){
	matriz[0] = 0;
	for(int i=1; i<=w; i++) matriz[i] = -1;
	for(int i=0; i<n; i++){
		for(int j=0; j<=w; j++){
			if(matriz[j] > -1 && j+v[i] <= w){
				if(matriz[j+v[i]] == -1) matriz[j+v[i]] = 1 + matriz[j];
				else matriz[j+v[i]] = min(matriz[j+v[i]], matriz[j] + 1);   
			}
		}
	}

	return matriz[w];	
}

int main(){
	int m, n;
	
	scanf("%d %d", &m, &n);

	while(m != 0){
		for(int i=0; i<n; i++){
			scanf("%d", &v[i]);
		} 
		int v = moedas(n, m);
		if(v != -1) printf("%d\n", v);
		else printf("Impossivel\n");
		scanf("%d %d", &m, &n);
	}
	return 0;
}
