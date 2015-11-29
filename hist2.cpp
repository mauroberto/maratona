#include <stdio.h>
#include <cmath>
using namespace std;

typedef struct pair{
	int first;
	int second;
	int vezes;
} pair;

int t[15];
int n;
pair m[15][1<<15];

pair r(int i, int s){
	if(m[i][s].first != -1) return m[i][s];
	int maior = 0;
	int lado;
	int vezes = 0;
	int count = 0;
	if(i==0){
		for(int j=0; j<n; j++){
			if(s&1<<j){
				pair p;
				p.first = 2+2*t[j];
				p.second = t[j];
				p.vezes = 1; 
				return p;
			}
		}

		pair p;
		p.first = 0;
		p.second = 0; 
		p.vezes = 0;
		return p;
	}else{
		for(int j=0; j<n; j++){
			if(s&1<<j){
				int perimetro = 2+2*t[j];
				pair v = r(i-1, s^(1<<j));
				int p = v.first + perimetro;
				if(v.second > t[j]){ 
					p -= 2*t[j];
				}else{
					p -= 2*v.second;
				}

				if(p > maior){
					maior = p;
					count = v.vezes;
					lado = j;
				}else if(p == maior){
					count += v.vezes;
				}
				printf("%d %d\n", count, i);
			}
		}
	}

	pair pair;
	pair.first = maior;
	pair.second = t[lado];
	pair.vezes = count;
	m[i][s] = pair;
	return m[i][s];
}

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<(1<<n); j++){
			pair p;
			p.first = -1;
			m[i][j] = p;
		}
	}

	for(int i=0; i<n; i++){
		scanf("%d", &t[i]);
	}	

	pair p = r(n-1, (1<<n)-1);
	printf("%d %d\n", p.first, p.vezes);
	return 0;
}
