#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

int p[102];
int ps[102];
int v[102];

int main(){
  int n, c = 1;
  scanf("%d", &n);

  while(n != 0){
    if(c > 1) printf("\n");
    for(int i=0; i<=n; i++){p[i] = 0; v[i] = 0; ps[i] = 0;}
    priority_queue <pair<pair<int, double>, int>, vector< pair<pair<int, double>, int> > > pq;

    int s = (n*(n-1))/2;

    int t1, t2, p1, p2;
    for(int i=0; i<s; i++){
      scanf("%d %d %d %d", &t1, &p1, &t2, &p2);

      if(p1 > p2){
        v[t1]+=2;
        v[t2]++;
      }else{
        v[t2]+=2;
        v[t1]++;
      }

      p[t1]+=p1;
      ps[t1]+=p2;
      p[t2]+=p2;
      ps[t2]+=p1;
    }

    for(int i = 1; i <=n; i++){
      if(ps[i] == 0){
        pq.push(make_pair(make_pair(v[i], p[i]), i));
      }else{
        pq.push(make_pair(make_pair(v[i], p[i]/double(ps[i])), i));
      }
    }
    printf("Instancia %d\n", c++);

    while(!pq.empty()){
      pair<pair<int, double>, int> p = pq.top(); pq.pop();
      if(pq.empty()){
        printf("%d\n", p.second);
      }else{
        printf("%d ", p.second);
      }
    }
    scanf("%d", &n);
  }

  return 0;
}
