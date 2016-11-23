#include<stdio.h>

int t[9][9];

int x[8] = {2, 2, 1, -1, -2, -2, 1, -1};
int y[8] = {1, -1, 2, 2, 1, -1, -2, -2};

int main(){
  int cont = 1;
  int xc, yc;
  char c;
  scanf("%d", &xc);
  while(xc != 0){
    scanf("%c", &c);
    yc = c - 'a' + 1;
    xc = 9 - xc;

    for(int i=0; i<9; i++){
      for(int j=0; j<9; j++){
        t[i][j] = 0;
      }
    }

    int px, py;
    for(int i=0; i<8; i++){
      scanf("%d%c", &px, &c);
      py = c - 'a' + 1;
      px = 9 - px;

      t[px][py] = 1;

    }

    int r = 8;

    for(int i = 0; i < 8; i++){
      int nx = xc + x[i];
      int ny = yc + y[i];
      if(ny > 8 || ny < 1 || nx > 8 || nx < 1){
        r--;
        continue;
      }

      if(ny > 1 && nx > 1 && t[nx - 1][ny - 1]){
        r--;
      }

      if(ny < 8 && nx > 1 && t[nx - 1][ny + 1]){
        r--;
      }
    }

    printf("Caso de Teste #%d: %d movimento(s).\n", cont++, r);

    scanf("%d", &xc);
  }
  return 0;
}
