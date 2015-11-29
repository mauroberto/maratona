#include<stdio.h>
#include<map>

using namespace std;

int e,a,p,f;

pair<int,int> matriz[5001][21];

int v[5002];

int min(int a, int b){
	return a > b ? b : a;
}

int pd(){
	v[p] = 0;
	int t = a*e;
	int fa = 0;
	for(int i=p-1; i>=0; i--){
		int menor = -1, fm;
		for(int j=0; j<f; j++){
			if(j == fa){
				printf("%d %d\n", i, j);
				int valor = matriz[i][j].first*matriz[i][j].second + t;
				if(valor < menor || menor == -1){
					menor = valor;
					fm = j;
				}
			}else{
				int valor = (matriz[i][j].first*matriz[i][j].second);
				if(valor < menor || menor == -1){
					menor = valor;
					fm = j;
				}
			}

		}

		printf("%d\n", menor);
		v[i] = menor+v[i+1];
		fa = fm;
	}

	return v[0];
}


int main(){

	scanf("%d %d %d %d", &f, &p, &e, &a);
	while(a !=0 || f != 0 || p != 0 || e != 0){
		for(int i=0; i<p; i++){
			for(int j=0; j<f; j++){
				int first, second;
				scanf("%d %d", &first, &second);
				matriz[i][j] = make_pair(first, second);
			}
		}
		printf("%d\n", pd());	
		scanf("%d %d %d %d", &f, &p, &e, &a);	
	}
	return 0;
}
