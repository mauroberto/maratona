#include<stdio.h>
#include<cmath>

int v[101];
int matriz[10050][101];

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int m(int n, int w){
	if(n < 0) return 0;
	int r = matriz[w][n];
	if(r != -1) return r;
	int aux;
	if(v[n] <= w){
		aux = max(m(n-1,w), m(n-1, w-v[n])+v[n]);
	}else{
		aux = m(n-1, w);
	}
	matriz[w][n] = aux;
	return aux;	
}

int main(){
	int s1, x, y, n, i, j, cont=1;
	
	scanf("%d %d %d", &x, &y, &n);

	while(x != 0 || y != 0 || n != 0){
		int t=0;		
		
		for(i=0; i<n; i++){
			scanf("%d", &v[i]);
			t += v[i];
		}
			
		int sub;
		sub = y-x;
		if(sub < 0) sub *= -1;
		s1 = (sub+t)/2;

		for(i=0; i<=n; i++){
			for(j=0; j<=s1; j++){
				matriz[j][i] = -1;
			}		
		}		
		 
		printf("Teste %d\n", cont);
		if((s1*2 == sub+t && m(n-1, s1) == s1)) printf("S\n");
		else printf("N\n");
		printf("\n");
		scanf("%d %d %d", &x, &y, &n);
		cont++;
	}
	return 0;
}
