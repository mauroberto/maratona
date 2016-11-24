#include<stdio.h>

int main(){
  unsigned long long int a, b;

  while(scanf("%lld %lld", &a, &b) != EOF){
    printf("%lld\n", a^b);
  }

  return 0;
}
