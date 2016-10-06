#include<stdio.h>
#include<queue>

using namespace std;


int main(){
  long long int t, n, k, v;
  scanf("%lld", &t);
  while(t--){
    priority_queue < long long int, vector<long long int> > pq;
    scanf("%lld %lld", &n, &k);
    while(n--){
      scanf("%lld", &v);
      pq.push(v);
    }
    long long int r = pq.top();pq.pop();
    //printf("%lld\n", r);
    k--;
    while(k--){
      v = pq.top();pq.pop();
      //printf("%lld\n", v);
      r = r & v;
    }

    printf("%lld\n", r);
  }
  return 0;
}
