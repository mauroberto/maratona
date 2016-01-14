#include<stdio.h>
#include<math.h>
#include<stdint.h>

int main() {
	int n;
	int bacteria = 0;
	float bi = -1;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int b,p;
		scanf("%d%d", &p, &b);
		float r = b*log(p);
		if(r > bi){
			bi = r;
			bacteria = i;
		}
	}
	printf("%d\n", bacteria);
    	return 0;
}
