#include<stdio.h>

int main(){
  int n, m, g, c;
  scanf("%d %d", &n, &m);
  c = n;

  for(int i = 0; i<n; i++){
    bool v = true;
    for(int j = 0; j<m; j++){
      scanf("%d", &g);
      if(g == 0){
        v = false;
      }
    }
    if(!v){
      c--;
    }
  }

  printf("%d\n", c);
  return 0;
}
