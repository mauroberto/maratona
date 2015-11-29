#include<stdio.h>
#include<map>
int n;
int v[1000];
int p[1000];
int q[1000];

using namespace std;
map <pair<int, int>, int> mapa;

int max(int a, int b) {
	return a > b ? a : b;
}

int m(int w, int num){
	pair<int, int> par = make_pair(w, num);
	int r = mapa[par];
	if(r != 0) return r;
	if(n == 0) return 0;
	if(w == 0) return 0;
	int i, maximo = 0, aux;
	for(i=0; i<num; i++){
		if(p[i] <= w && q[i] > 0){
			q[i]--;
			aux = max(m(w, num-1), m(w-p[i], num-1)+v[i]);
			q[i]++;
		}else{
			aux = m(w, num-1);
		}
			
		if(aux>maximo) maximo = aux;
	}

	mapa[par] = maximo;
	return maximo;
} 
int m2 (int w, int num){
	if(n == 0) return 0;
	if(w == 0) return 0;
	int i, maximo = 0, aux;
	for(i=0; i<num; i++){
		if(p[i] <= w && q[i] > 0){
			q[i]--;
			aux = max(m(w, num-1), m(w-p[i], num-1)+v[i]);
			q[i]++;			
		}else{
			aux = m(w, num-1);
		}
			
		if(aux>maximo) maximo = aux;
	}

	return maximo;
} 

int main(){
	int w;
	scanf("%d %d", &w, &n);
	int i;
	for(i=0; i<n; i++){
		scanf("%d %d %d", &p[i], &v[i], &q[i]);
	}

	printf("%d\n", m(w, n));
}
