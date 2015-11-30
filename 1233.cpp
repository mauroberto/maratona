#include<stdio.h>
#include<cmath>

using namespace std;

unsigned long long int f(unsigned long long int n){
	if( n < 2 ) return 0;
	unsigned long long int p = 2;
	unsigned long long int res = n;
	unsigned long long int limite = sqrt(n) + 1;
	while ( n > 1 && p < limite){
		if(n%p == 0){
			res = res/p*(p-1);
			n = n/p;
			while(n%p == 0){
				n = n/p;
			}
			limite = sqrt(n) + 1;
		}
		p++;
	}
	
	if(n > 1) {
		res = res/n*(n-1);
	}
	
	return res/2;
}


int main(){
	unsigned long long int n;
	while(scanf("%lld", &n) != EOF){
		unsigned long long int k = f(n);
		printf("%lld\n", k);
	}	
	return 0;
}
