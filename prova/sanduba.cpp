#include<stdio.h>
long long int v[100000];
int N;

long long int total=0;

long long int fb(){
	long long int soma = 0;
	for(int i=0; i<N; i++){
		soma += ((total%1300031)*(v[i]%1300031))%1300031;
		total -= v[i];
	}
	return soma;	
}

int main(){	
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &N);
		for(int i = 0; i < N; i++){
			scanf("%lld", &v[i]);
			total += v[i];
		} 
		printf("%lld\n", fb()%1300031);
	}
}
