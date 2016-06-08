#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <stdio.h>
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

int n, m, testes;
priority_queue <int, vector <int>, less <int> > pq;
queue <ii> fila;


int print(){
	int r = 0;
	while(1){
		ii p = fila.front();
		fila.pop();
		int maxP = pq.top();
		if(p.second == maxP){
			r++;
			pq.pop();
			if(p.first == m){
				return r;
			}
		}else{
			fila.push(p);
		}
	}
}

int main(){
	scanf("%d", &testes);
	
	REP(i, 0, testes-1){
		pq = priority_queue <int, vector <int>, less <int> >();
  		fila = queue <ii> ();

		scanf("%d%d", &n, &m);
		REP(j, 0, n-1){
			ii par;
			par.first = j;
			int second;
			scanf("%d", &second);
			par.second = second;
			fila.push(par);
			pq.push(second);
		}		
		
		printf("%d\n", print());	
	}  	

	return 0;
}
