#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
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
  vi v;
  v.push_back(3);
  v.push_back(5);
  v.push_back(4);
  sort(v.begin(), v.end(), less <int> () );
  do{
    TRvi(v, it)  cout << *it << " ";
    cout << endl;
  }while( next_permutation(v.begin(), v.end() ) );
}
