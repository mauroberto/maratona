#include<stdio.h>

int matriz[1502][1502];
int a[] = {0, -1, 1, 0}; 
int b[] = {-1, 0, 0, 1};
int cerca = 0;
int km = 0;

void fb(){
	for(int i=0; i<=1501; i++){
		for(int j=0; j<=1501; j++){
			if(matriz[i][j] == 0) continue;
			km++;
			for(int k=0; k<4; k++){
				if((i+a[k] > 1501 || i+a[k] < 0) || (j+b[k] > 1501 || j+b[k] < 0) || matriz[i+a[k]][j+b[k]] == 0){
					cerca++;
				}
			}	
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	while(n != 0){
		km = 0, cerca = 0;
		int x, y, l, c;
		for(int i=0; i<1502; i++){
			for(int j=0; j<1502; j++){
				matriz[j][i] = 0;
			}
		}

		for(int i=1; i<=n; i++){
			scanf("%d %d %d %d", &x, &y, &l, &c);
			for(int k=x; k<x+l; k++){
				for(int j=y; j<y+c; j++){
					matriz[k][j] = 1;
				}
			}
		}

		fb();
		printf("%d %d\n", km, cerca);
		scanf("%d", &n);
	}
	return 0;
}
