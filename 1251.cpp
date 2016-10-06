#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

struct greater1{
  bool operator()(const pair<int, int>& a,const pair<int, int>& b) const{
    if(a.first > b.first){
      return true;
    }else if(b.first > a.first){
      return false;
    }else{
      if(a.second < b.second){
        return true;
      }else{
        return false;
      }
    }
  }
};

priority_queue < pair<int, int>, vector<pair<int, int> >, greater1 > pq;

int main(){
  int c[201];
  char s[1001];
  bool primeiro = true;
  while(scanf("%s", s) != EOF){
    //printf("%c\n", s[0]);
    if(primeiro){
      primeiro = false;
    }else{
      printf("\n");
    }
    
    for(int k=32; k<=200; k++){
      c[k] = 0;
    }

    for(int i=0; s[i] != '\0'; i++){
      int k = s[i];
      c[k]++;
    }

    for(int i=200; i>=32; i--){
      if(c[i] != 0){
        pq.push(make_pair(c[i], i));
      }
    }

    while(!pq.empty()){
      pair<int, int> p = pq.top(); pq.pop();

      printf("%d %d\n", p.second, p.first);
    }
  }
  return 0;
}
