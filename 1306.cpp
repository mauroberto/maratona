#include<stdio.h>

int main(){
  int r, n, c = 1;
  scanf("%d %d", &r, &n);
  while(n != 0 && r != 0){
    printf("Case %d: ", c++);
    double x = r/(n*1.0);

    if(x > int(x)){
      x = int(x)+1;
    }

    if(x > 27){
      printf("impossible\n");
    }else{
      printf("%d\n", int(x-1));
    }
    scanf("%d %d", &r, &n);
  }

  return 0;
}
