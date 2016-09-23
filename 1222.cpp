#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main(){
	long long int N, M, C;
	char p[100];
	while(scanf("%lld %lld %lld", &N, &M, &C) != EOF){
		int cl = 0, cc = 0;		

		while(N--){
			scanf(" %s", p);
			int t = strlen(p);
			if (t + cc <= C){
				cc += t;
			}else{
				cl ++;
				cc = t;
			}

			cc++;
		}

		if(cc != 0){
			cl ++;
		}

		//printf("%d\n", cl);

		printf("%d\n", (int) ceil(cl*1.0/M));
	}
	return 0;
}
