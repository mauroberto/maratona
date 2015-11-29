#include<stdio.h>

int n, v[10000];

int max_sum(){
	int max_atual = 0;
	int max_total = -1;
	for(int i=0; i<n; i++){
		max_atual += v[i];
		if(max_atual < 0) max_atual = 0;
		if(max_atual > max_total) max_total = max_atual;
	}

	return max_total;
}

int main(){
	scanf("%d", &n);
	while(n!=0){
		for(int i=0; i<n; i++){
			scanf("%d", &v[i]);	
		}
		int r = max_sum();
		if(r > 0) printf("The maximum winning streak is %d.\n", r);
		else printf("Losing streak.\n");
		scanf("%d", &n);
	}

	return 0;
}
