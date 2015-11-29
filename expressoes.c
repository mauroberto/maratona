#include<stdio.h>

int v[10];
int n;

int calc(int i, int s){
	if(i >= n) return 0;
	if((s + v[i] == v[0] || s - v[i] == v[0]) && i == n){
		return 1;
	}

	return calc(i+1, s+v[i]) || calc(i+i, s-v[i]); 
}

int main(){
	calc(1, 0);
}
