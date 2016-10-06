#include<stdio.h>

double area(double B, double b, double h){
  return ((B+b)*h)/2.0;
}

int main(){
  int h = 5, t, q;
  double a, b, total;
  scanf("%d", &t);
  while(t != 0){

    for(int i=1; i<=t; i++){
      scanf("%d", &q);
      scanf("%lf %lf", &a, &b);
      total = area(a, b, h);
      total *= q;
      printf("Size #%d:\n", i);
      printf("Ice Cream Used: %.2lf cm2\n", total);
    }
    printf("\n");
    scanf("%d", &t);
  }
  return 0;
}
