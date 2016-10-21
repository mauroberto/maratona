#include<stdio.h>

int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    int epr = 0, ehd = 0, in = 0;
    int m;
    char t[100];
    while(n--){
      scanf("%d %s", &m, t);
      if(t[0] == 'E' && t[1] == 'P' && t[2] == 'R'){
        epr ++;
      }else if(t[0] == 'E' && t[1] == 'H' && t[2] == 'D'){
        ehd ++;
      }else{
        in ++;
      }
    }

    printf("EPR: %d\n", epr);
    printf("EHD: %d\n", ehd);
    printf("INTRUSOS: %d\n", in);
  }
  return 0;
}
