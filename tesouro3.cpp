#include<stdio.h>

int v[101];
int matriz[10051];

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int m(int n, int w){
	matriz[0] = 1;
	for(int i=1; i<=w; i++) matriz[i] = 0;
	for(int i=0; i<n; i++){
		for(int j=w; j>=0; j--){
			if(matriz[j] == 1 && j+v[i] <= w){
				matriz[j+v[i]] = 1;
			}
		}
	}

	return matriz[w];	
}

int main(){
	int s1, x, y, n, i, j, cont=1;
	
	scanf("%d %d %d", &x, &y, &n);

	while(x != 0 || y != 0 || n != 0){
		int t = 0;		
		
		for(i=0; i<n; i++){
			scanf("%d", &v[i]);
			t += v[i];
		}
			
		int maior = max(x,y);

		int s2 = t+y+x;
		s1 = (s2)/2;
		s1 -= maior;
		 
		printf("Teste %d\n", cont);
		if(s2%2==0 && m(n, s1) == 1) printf("S\n");
		else printf("N\n");
		printf("\n");
		scanf("%d %d %d", &x, &y, &n);
		cont++;
	}
	return 0;
}
