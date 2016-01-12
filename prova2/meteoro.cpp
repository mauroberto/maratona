#include<stdio.h>

int main(){
	int cont = 1;
	int x1, x2, y1, y2;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	while(x1 != 0 || x2 != 0 || y1 != 0 || y2 != 0){
		int r = 0;
		int n;
		int x, y;
		scanf("%d", &n);
		while(n--){
			scanf("%d %d", &x, &y);
			if(x >= x1 && x <= x2 && y <= y1 && y >= y2){
			 	r++;
			}
		}
		printf("Teste %d\n", cont);
		printf("%d\n\n", r);
		cont++;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	}
	return 0;
}
