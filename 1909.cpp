#include<stdio.h>
#include<map>
#include<cmath>

using namespace std;

int divisores[100002];

void f2(long long int n){
	divisores[1] = 1;
	divisores[n] = 1;
	for(int i=2; i<=(n/2)+1; i++){
		if(n%i == 0)divisores[i] = 1;
		else divisores[i] = 0;
	}
}

long long int mdc(long long int a, long long int b){
	if(a<0) a = -a;
	if(b<0) b = -b;

	while(b > 0){
		long long int r = a%b;
		a = b;
		b = r;
	}
	return a;
}


int main(){
	long long int n, mmc;
	
	scanf("%lld %lld", &n, &mmc);
	while(n != 0 || mmc != 0){
		long long int m = 1;		
		f2(mmc);
		while(n--){
			long long int aux;
			scanf("%lld", &aux);
			m = (m*aux)/mdc(m, aux);
			divisores[aux] = 0;
		}
	
		long long int flag = -1;
		for(long long int i=2; i<=(mmc/2); i++){
			if(divisores[i] == 0) continue; 
			long long int r = (i*m)/mdc(i, m);
			if(r == mmc){
				flag = i;
				break;
			}
		}
		if(divisores[mmc] == 1 && flag == -1){
			long long int r = (mmc*m)/mdc(mmc, m);
			if( r == mmc ) flag = mmc;
		}

		if(flag != -1) printf("%lld\n", flag);
		else printf("impossivel\n");
		scanf("%lld %lld", &n, &mmc);
	}
	return 0;
}
