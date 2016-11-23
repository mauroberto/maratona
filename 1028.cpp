#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  int f1, f2;

  scanf("%d", &n);
  while(n--){
    scanf("%d %d", &f1, &f2);
    int mdc = __gcd(f1, f2);
    printf("%d\n", mdc);
  }
  return 0;
}
