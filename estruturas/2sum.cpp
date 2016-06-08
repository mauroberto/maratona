#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <time.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef set<int> si;
typedef map<string, int> msi;

#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++)
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)

#define MAX 10000000
int v[MAX];
int sum;
double elapsed;

int compara(const void *pa, const void *pb)
{
  return *(int*)pa - *(int*)pb;
}

bool twosum(int * v, int n, int sum)
{
  int i, j;

  i = 0;
  j = n;

  while( i < j)
  {
    if( v[i] + v[j] == sum) return true;
    else if( v[i] + v[j] > sum){
      j--;
    }else{
      i++;
    }
  }

  return false;
}

bool twosum_with_map(int * v, int n, int sum)
{
  map <int, int> mapa;
  map <int,int>::iterator it;

  for(int i = 0; i < n; i++)
  {
    it = mapa.find(sum-v[i]);

    if( it != mapa.end() ) return true;

    mapa[v[i]] = i;
  }


}

bool twosum_with_unordered_map(int * v, int n, int sum)
{
  unordered_map <int, int> mapa;
  unordered_map <int,int>::iterator it;

  for(int i = 0; i < n; i++)
  {
    it = mapa.find(sum-v[i]);

    if( it != mapa.end() ) return true;

    mapa[v[i]] = i;
  }


}


int main(){

  clock_t clk;

  srand (time(NULL));

  for(int i = 0; i < MAX; i++)
    v[i] = rand();

  qsort(v, MAX, sizeof(int), compara);

  sum  = rand();

  clk = clock();

  printf("twosum\n");

  twosum(v, MAX-1, sum) ? printf("Found\n") : printf("Not found\n");

  elapsed = ((double) (clock() - clk)) / CLOCKS_PER_SEC;

  printf("time                 = %10.5f\n", elapsed);

  clk = clock();

  printf("twosum_with_map\n");

  twosum_with_map(v, MAX-1, sum) ? printf("Found\n") : printf("Not found\n");

  elapsed = ((double) (clock() - clk)) / CLOCKS_PER_SEC;

  printf("time                 = %10.5f\n", elapsed);

  clk = clock();

  printf("twosum_with_unordered_map\n");

  twosum_with_unordered_map(v, MAX-1, sum) ? printf("Found\n") : printf("Not found\n");

  elapsed = ((double) (clock() - clk)) / CLOCKS_PER_SEC;

  printf("time                 = %10.5f\n", elapsed);


}
