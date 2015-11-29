#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

unsigned int chaves[20];

int fb(int m, int d){
	int pos = 0;
	unsigned int cc = 0;
	int r = 21;
	for(int x = 0; x < 1<<d; x++){
		cc = 0;
		for (int i=0; i<d; i++){
			if(x&(1<<i)){
				cc |= chaves[i];
			}
		}
		if (__builtin_popcount(cc) >= m){
			if(__builtin_popcount(x) < r){
				r = __builtin_popcount(x);
			}
		}
	}
	return r;
}

int main (){
	int t, m, d, r, aux;

	scanf("%d", &t);
	while (t--){
		scanf("%d %d", &m, &d);		
		for (int cont=0; cont<d; cont++){
			scanf("%d", &r);
			chaves[cont] = 0;
			for (int i=0; i<r; i++){
				scanf("%d", &aux);
				chaves[cont] |= 1<<aux;	
			}
		}
		r = fb(m, d);
		if (r == 21 && m != 0){
			printf("Desastre!\n");
		}else{
			printf("%d\n", r);
		}

	}

	return 0;
}
	
 
