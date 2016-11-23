#include<stdio.h>

int main(){
  int n = 0;
  double t = 0, v;

  while(n < 2){
    scanf("%lf", &v);

    if(v < 0 || v > 10){
      printf("nota invalida\n");
    }else{
      n++;
      t += v;
    }
  }

  printf("media = %.2lf\n", t/2);
  return 0;
}
