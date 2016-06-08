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

bool IsOdd(int n) { return n%2==1; }

int main()
{
  ios::sync_with_stdio(false);
  vi v;
  v.push_back(5);
  v.push_back(3);
  v.push_back(4);
  v.push_back(2);
  //ordem crescente
  sort( v.begin() , v.end() , less <int>()   );
  TRvi(v, it){
    cout << *it << " ";
  }
  cout << endl;
  //ordem decrescente
  sort( v.begin() , v.end() , greater <int>()   );
  int mycount = count_if (v.begin(), v.end(), IsOdd);
  cout << "numeros impares " << mycount << endl;
}
