#include<stdio.h>


int main(){
  int n, c = 0, r = 0, s = 0, t = 0;

  scanf("%d", &n);
  int cb; char tp;
  while(n--){
    scanf("%d %c", &cb, &tp);

    if(tp == 'C'){
      c += cb;
    }else if(tp == 'R'){
      r += cb;
    }else{
      s += cb;
    }

    t += cb;
  }

  printf("Total: %d cobaias\n", t);
  printf("Total de coelhos: %d\n", c);
  printf("Total de ratos: %d\n", r);
  printf("Total de sapos: %d\n", s);

  float perc = (c / (t*1.0))*100;

  printf("Percentual de coelhos: %.2f %c\n", perc, '%');

  perc = (r / (t*1.0))*100;

  printf("Percentual de ratos: %.2f %c\n", perc, '%');

  perc = (s / (t*1.0))*100;

  printf("Percentual de sapos: %.2f %c\n", perc, '%');
  return 0;
}
