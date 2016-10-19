#include<stdio.h>

int v[1001];
int valor, n;


bool p(int valor, int n){
  if(n < 0 || valor < 0){
    return false;
  }

  if(v[n] == valor){
    return true;
  }

  if(p(valor-v[n], n-1) || p(valor, n-1)){
    return true;
  }

  return false;
}

int main(){
  scanf("%d %d", &valor, &n);

  while(n != 0 && valor != 0){

    for(int i=0; i<n; i++){
      scanf("%d", &v[i]);
    }

    if(p(valor, n-1)){
      printf("sim\n");
    }else{
      printf("nao\n");
    }

    scanf("%d %d", &valor, &n);
  }


  return 0;
}
