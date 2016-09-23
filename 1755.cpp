#include<stdio.h>
#include <math.h>

int main(){
	int t, q;
	scanf("%d", &t);
	while(t--){
		double i, r, d;
		scanf("%lf %d", &d, &q);
		int d2, i2, maior = 0;
		d2 = round(d * 100);
		while(q--){
			scanf("%lf", &i);
			i2 = round(i * 100);
			if(i2 > d2) continue;
			r = d2 % i2;
			if (r > maior) maior = r;
		}

		printf("%d.%02d\n", maior/100, maior%100);
	}

	return 0;
}
