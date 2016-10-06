#include<stdio.h>

int matriz[101][101];
int c[101][101];

int x[4] = {1, 0, 1,  0};
int y[4] = {1, 1, 0,  0};

int main(){
  int n;

  scanf("%d", &n);

  for(int i=0; i<=n; i++){
    for(int j=0; j<=n; j++){
      scanf("%d", &matriz[i][j]);
      c[i][j] = 0;
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      for(int k=0; k<4; k++){
        if(matriz[i+x[k]][j+y[k]] == 1){
          c[i][j]++;
        }
      }
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(c[i][j] >= 2){
        printf("S");
      }else{
        printf("U");
      }
    }
    printf("\n");
  }

  return 0;
}
