#include<stdio.h>
int v[31];
int matriz[31][30000];

using namespace std;

void pd(int n, int w){
	matriz[0][0] = 1;
	for(int i=1; i<=w; i++) matriz[0][i] = 0;
	for(int i=1; i<=n; i++){
		for(int j=w; j>=0; j--){
			if(matriz[i-1][j] == 1){
				matriz[i][j] = 1;
				if(j+v[i] <= w){
					matriz[i][j+v[i]] = 1;
				}
			}else{
				matriz[i][j] = 0;
			}
		}
	}
	
	int flag = 1;
	for(int i=1; i<=n; i++){
		if(matriz[i-1][v[i]] == 1){
			flag = 0;
		}
		printf(" %d", v[i]);	
	}
	printf("\n");

	if(flag == 1) printf("This is an A-sequence.\n");
	else printf("This is not an A-sequence.\n");
}

int main(){
	int t=1, ts;
	while(scanf("%d", &ts) != EOF){
		int w=0;
		for(int j=1; j<=ts; j++){
			scanf("%d", &v[j]);
			w += v[j];
		}
		printf("Case #%d:",t);
		pd(ts,w);
		t++;
	}	
	return 0;
}
