#include<stdio.h>
#include<map>

using namespace std;

int e,a,p,f;

int matriz[5001][21];

pair<int,int> v[5002];

int min(int a, int b){
	return a > b ? b : a;
}

int pd(){
	int t = a*e;
	int menor = -1, fm;
	for(int i=0; i<f; i++){
		if(matriz[p-1][i] < menor || menor == -1){
			menor = matriz[p-1][i];
			fm = i;
		}
		matriz[0][i] = 99999999;	
	}
	matriz[0][0] = 0;
	v[p].first = menor;
	v[p].second = fm;
	for(int i=p; i>0; i--){
		int menor = -1, fm;
		for(int j=0; j<f; j++){
			int valor = matriz[i-1][j];
			if(i != v[i].second) valor+=t;
			if(valor < menor || menor == -1){
				menor = valor;
				fm = j;
			}
		}
		v[i-1].first = menor+v[i].first;
		v[i-1].second = fm;
	}

	return v[0].first;
}


int main(){

	scanf("%d %d %d %d", &f, &p, &e, &a);
	while(a !=0 || f != 0 || p != 0 || e != 0){
		for(int i=1; i<=p; i++){
			for(int j=0; j<f; j++){
				int first, second;
				scanf("%d %d", &first, &second);
				matriz[i][j] = first*second;
			}
		}
		printf("%d\n", pd());	
		scanf("%d %d %d %d", &f, &p, &e, &a);	
	}
	return 0;
}
