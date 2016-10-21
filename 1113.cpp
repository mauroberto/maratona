#include<stdio.h>

int main(){
  int x, y;

  scanf("%d %d", &x, &y);
  while(x != y){
    if(x < y){
      printf("Crescente\n");
    }else if(y < x){
      printf("Decrescente\n");
    }

    scanf("%d %d", &x, &y);
  }
  return 0;

}
