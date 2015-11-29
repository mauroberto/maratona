#include<stdio.h>

int v[100];
int t = 0;
int m;
int x, y, n, i, cont=1;

int subset(int a, int b, int i){
	if(i<n){
		if(a > m || b > m){
			return 0;
		}else{
			return subset(a+v[i], b, i+1) || subset(a, b+v[i], i+1);
		}
	}else if(a == b){
		return 1;
	}

	return 0;
}

int main(){
	
	scanf("%d%d%d", &x, &y, &n);

	while(x != 0 && y != 0 && n != 0){
	
		for(i=0; i<n; i++){
			scanf("%d", &v[i]);
			t += v[i];
		}

		m = (x+y+t)/2;

		printf("Teste %d\n", cont);
		if(subset(x, y, 0)) printf("S\n");
		else printf("N\n");
		printf("\n");

		scanf("%d%d%d", &x, &y, &n);
		cont++;

	}

	return 0;
}
