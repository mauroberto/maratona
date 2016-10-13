#include<stdio.h>
using namespace std;

int v[201];

int main(){

  int n, c = 1, m, cd, ct, mt;
  scanf("%d", &n);

  while(n != 0){
    for(int i=0; i<=200; i++){
      v[i] = -1;
    }
    ct = 0, mt = 0;

    while(n--){
      scanf("%d %d", &m, &cd);
      ct += cd;
      mt += m;
      int md = cd/m;
      if(v[md] == -1) v[md] = 0;
      v[md] += m;
    }

    if(c > 1){
      printf("\n");
    }
    printf("Cidade# %d:\n", c++);
    for(int i=0; i<=200; i++){
      if(v[i] != -1){
        printf("%d-%d ", v[i], i);
      }
    }
    printf("\n");
    int r = (ct/(mt*1.0))*100;
    printf("Consumo medio: %.2lf m3.\n", r/100.0);
    scanf("%d", &n);
  }

  return 0;
}
