#include<stdio.h>

char pre[53],em[53],pos[53];
int count;
int n;

void r(int ini, int fim){
	if(ini > fim) return;
	if(ini == fim){
		pos[count] = em[ini];
		count++;
		return;
	}else{
		for(int i=0; i<n; i++){
			for(int j=ini; j<=fim; j++){
				if(pre[i] == em[j]){
					r(ini, j-1);
					r(j+1,fim);
					pos[count] = em[j];
					count++;
					return;
				}
			}
		}
	}
}


int main(){
	int c;
	scanf("%d", &c);
	while(c--){
		count = 0;
		scanf("%d", &n);
		scanf("%s %s", pre, em);
		r(0, n-1);
		pos[count] = '\0';
		printf("%s\n", pos);
	}
	return 0;
}
