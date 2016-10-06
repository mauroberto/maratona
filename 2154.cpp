#include<stdio.h>

int main(){
  int n;

  while(scanf("%d", &n) != EOF){
    int a, b;
    //printf("n = %d\n", n);
    for(int i=0; i<n; i++){
      //printf("i = %d\n", i);
      if(i > 0 && i < n){
          printf(" + ");
      }

      scanf(" %dx%d ", &a, &b);
      if(i < n-1) getchar();
      //if(b == 1){
        //printf("1");
      //}else
      if(b == 2){
        printf("%dx", a*b);
      }else{
        printf("%dx%d", a*b, b-1);
      }
    }
    printf("\n");
  }
  return 0;
}
