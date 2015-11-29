#include<stdio.h>
#include<stdlib.h>
#include <string.h>
using namespace std;

int ve[1001], n;

int min(int a, int b){
	return a > b ? b : a;
}

int main(){
	scanf("%d", &n);		
	while(n != 0){
		int flag = 1;
		memset(ve,0,sizeof(ve));
		for(int i=0; i<n; i++){
			int aux;
			scanf("%d", &aux);
			ve[aux]++;
		}
		for(int i=0; i<n; i++){
			int aux;
			scanf("%d", &aux);
			int p = ve[1000];
			for(int j=1000; aux > 0 && j > 0 && flag; j--){
				int m = min(p, aux);
				p = ve[j-1];
				ve[j] -= m;
				ve[j-1] += m;
				aux -= m;
			}
			if(aux > 0){
				flag = 0;
			}
		}
		if(ve[0] != n) flag = 0;

		if(flag)
			printf("E\n");
		else
			printf("N\n");
		scanf("%d", &n);
	}
	return 0;
}
