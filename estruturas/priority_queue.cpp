#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
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
  //fila de prioridade mínima
  priority_queue <int, vector <int>, greater <int> > pq;
  pq.push(30);
  pq.push(20);
  pq.push(25);
  pq.push(40);
  while( !pq.empty() )
  {
    cout << pq.top() << " ";
    pq.pop();
  }
  cout << endl;
}



