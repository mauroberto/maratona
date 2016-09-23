#include<stdio.h>

int v[5] = {1, 10, 100, 1000, 10000};

int main(){
	int n, m;

	scanf("%d %d", &n, &m);
	long long int tg = 0, te = 0;

	while(m--){
		int b, d;
		scanf("%d %d", &b, &d);

		long long int s = 0; 
		int j;

		for(int i=0; i<n-1; i++){
			scanf("%d", &j);
			s += j;	
		}
		if(d+s <= b){
			tg += d;
		}

		for(int i=4; i>=0; i--){
			if(v[i] + s <= b){
				te += v[i];
				break;
			}
		}		
	}

	printf("%lld\n", te-tg);

	return 0;
}
