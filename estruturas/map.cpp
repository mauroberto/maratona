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





int main()
{
  char poema [] = "Sou chama sem luz jardim \
  sem luar luar sem amor";
  map <char, int> mapa;
  map<char,int>::iterator it;
  for(int i = 0; poema[i] != '\0'; i++)
  {
    char c = poema[i];
    mapa[c]++;
  }

  for(it = mapa.begin(); it != mapa.end(); it++)
  {
    if( it->second > 0 )
    printf("mapa[%c] = %d\n", it->first, it->second );
  }
}
