#include<stdio.h>


int g[20][20];
int pd[20][1<<20];
int n;

long long int r(int i, int s){
	if(pd[i][s] != -1) return pd[i][s];
	long long int soma = 0;
	if(i==0){
		for(int j=0; j<n; j++){
			if(g[i][j] && (s&1<<j))
				return 1ll;
		}
		return 0ll;
	}else{
		for(int j=0; j<n; j++){
			if(g[i][j] && (s&1<<j)){
				soma += r(i-1, s^(1<<j));
			}
		}
	}
	
	pd[i][s] = soma;
	return soma;
}

int main(){
	int c;
	scanf("%d", &c);
	for(int ct=0; ct<c; ct++){
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				scanf("%d", &g[i][j]);
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<(1<<n); j++){
				pd[i][j] = -1;
			}
		}
		printf("%lld\n", r(n-1, (1<<n)-1));
	}
	return 0;
}
