#include<stdio.h>

typedef struct matriz{
	int v[2][2];
	matriz operator*(const matriz& m) const;
}Matriz;

Matriz Matriz::operator*(const Matriz& m) const{
	Matriz tmp = (*this);
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			int r=0;
			for(int k=0; k<2; k++){
				r += v[i][k] * m.v[k][j];
			}
			tmp.v[i][j] = r;
		}
	}
	return tmp;
}

Matriz exp_matriz(Matriz m, int n){
	if(n == 1){
		return m;
	}else if(n%2 == 0){
		Matriz m2;
		m2 = exp_matriz(m, n/2);
		return m2*m2;
	}else{
		return m*exp_matriz(m, n-1);
	}
}


int main(){
	Matriz m2, m3;

	m2.v[0][0] = 1;
	m2.v[0][1] = 1;
	m2.v[1][0] = 1;
	m2.v[1][1] = 0;

	m3 = exp_matriz(m2, 5);
	
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			printf("%d ",m3.v[i][j]);
		}
		printf("\n");
	}
}

