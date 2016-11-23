#include<stdio.h>

char c[1325];
int v[1325];

long long int toDec(int n, int m){
  long long int d = 0;
  for (int i = 0; i < n; i++){
    d = d%m + v[i]%m;
  }

  return d%m;
}

int main(){
  while(scanf("%s", c) != EOF){
    int m = 1;
    int i;

    for(i = 0; c[i] != '\0'; i++){
      v[i] = 0;
      if(c[i] >= '0' && c[i] <= '9'){
        v[i] = c[i] - '0';
      }else if(c[i] >= 'A' && c[i] <= 'Z'){
        v[i] = c[i] - 'A' + 10;
      }else if(c[i] >= 'a' && c[i] <= 'z'){
        v[i] = c[i] - 'a' + 36;
      }
      if(v[i] > m) m = v[i];
    }

    if(m > 61){
      printf("such number is impossible!\n");
    }else{
      int j;

      for(j = m; j < 62; j++){
        long long int dec = toDec(i, j);
        if(!dec){
          printf("%d\n", j+1);
          break;
        }
      }

      if(j == 62){
        printf("such number is impossible!\n");
      }
    }
  }
  return 0;
}
