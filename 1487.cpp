#include<stdio.h>
#include<queue>

using namespace std;


int pontos[101], tempo[101];


int main(){
  int n, t, p, tg, c=1;
  scanf("%d %d", &n, &t);

  while(n != 0){
    priority_queue <pair<float, int>, vector<pair<float, int> > > pq;

    for(int i=0; i<n; i++){
      scanf("%d %d", &tempo[i], &pontos[i]);
      pq.push(make_pair(pontos[i]/tempo[i], i));
    }

    int pt = 0;

    while(!pq.empty()){
      pair <float, int> p = pq.top(); pq.pop();
      if(tempo[p.second] > t){
        continue;
      }

      int v = t / tempo[p.second];

      pt += v*pontos[p.second];
      t -= v*tempo[p.second];
    }
    printf("Instancia %d\n", c++);
    printf("%d\n\n", pt);
    scanf("%d %d", &n, &t);
  }
  return 0;
}
