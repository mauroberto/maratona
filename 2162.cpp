#include<stdio.h>


int main(){

  int n;

  int x, y;
  scanf("%d", &n);
  bool p;

  bool v = true;
  n-=2;
  scanf("%d %d", &x, &y);
  if(x > y){
    p = false;
  }else if(x < y){
    p = true;
  }else{
    v = false;
  }

  int u = y;
  while(n--){
    scanf("%d", &y);
    if(p){
      if(y >= u){
        v = false;
      }
      p = false;
    }else{
      if (y <= u){
        v = false;
      }
      p = true;
    }

    u = y;
  }

  if(v){
    printf("1\n");
  }else{
    printf("0\n");
  }

  return 0;
}
