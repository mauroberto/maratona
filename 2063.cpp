#include<stdio.h>
#include<bits/stdc++.h>

int b[101];
int p[101];

using namespace std;

int n;


int main(){
  scanf("%d", &n);

  for(int i=1; i<=n; i++){
    scanf("%d", &b[i]);
    p[i] = i;
  }

  int res = 1;

  for(int i=1; i<=n; i++){
    int pos = b[i];
    int t = 1;

    while(pos != i){
      t++;
      pos = b[pos];
    }

    res = (res / __gcd (res, t)) * t;
  }

  printf("%d\n", res);

  return 0;
}
