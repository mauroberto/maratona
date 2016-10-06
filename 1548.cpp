#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

priority_queue < pair<int, int>, vector< pair <int, int> > > pq;
vector < pair<int, int> > fila;
vector < pair<int, int> > fila2;


int main(){
  int n, m, v, nt;
  scanf("%d", &n);
  while(n--){
    fila.clear();
    fila2.clear();
    scanf("%d", &m);
    for(int j=0; j<m; j++){
      scanf("%d", &v);
      pair <int, int> p = make_pair(v, j);
      pq.push(p);
      fila.push_back(p);
    }

    int s = fila.size(), s2 = s;
    while(!pq.empty()){
      pair <int, int> p = pq.top();
      pq.pop();
      fila2.push_back(p);
    }

    int c = 0;
    for(int i=0; i<m; i++){
      if(fila[i].second != fila2[i].second || fila[i].first != fila2[i].first){
        c++;
      }
    }
    printf("%d\n", m-c);
  }
  return 0;
}
