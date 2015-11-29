#include<stdio.h>

int euclides_estendido(int a, int b, int &x1, int &x2){
	int Z = a, z = b, q, aux, v11, v10;
	int v1[2] = {1, 0};
	int v2[2] = {0, 1};
	while(z > 0){
		q = Z/z;
		v10 = v1[0];
		v11 = v1[1];
		v1[0] = v2[0];
		v1[1] = v2[1];
		aux = Z;
		Z = z;
		v2[0] = v10 - q*v2[0];
		v2[1] = v11 - q*v2[1];
		z = aux-q*z;
	}

	x1 = v1[0];
	x2 = v1[1];
	return Z;
}

int main(){
	int x1, x2;
	int z = euclides_estendido(24, 23, x1, x2);	
	printf("%d %d %d\n", z, x1, x2);
}


