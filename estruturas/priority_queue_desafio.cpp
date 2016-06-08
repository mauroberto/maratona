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





int main(){
  clock_t clk;
  double elapsed;

  default_random_engine generator;
  uniform_int_distribution<int> distribution(1, 1000000000);

  vi v1, v2;
  for(int i = 0; i < 10000000; i++)
  {
    int x = distribution(generator);
    v1.push_back ( x );
    v2.push_back ( x );
  }

  clk = clock();
  sort(v1.begin(), v1.end(), greater <int>() );
  for(int i = 0; i < 10; i++) cout << v1[i] << " ";
  cout << endl;
  elapsed = ((double) (clock() - clk)) / CLOCKS_PER_SEC;
  printf("time                 = %10.5f\n", elapsed);

  clk = clock();

  make_heap(v2.begin() , v2.end() );
  for(int i = 0; i < 10; i++)
  {
    cout << v2.front() << " ";
    std::pop_heap (v2.begin(),v2.end());
    v2.pop_back();
  }
  cout << endl;

  elapsed = ((double) (clock() - clk)) / CLOCKS_PER_SEC;
  printf("time                 = %10.5f\n", elapsed);


}
