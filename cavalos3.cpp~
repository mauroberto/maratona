#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <vector>
#include <string.h>

#define MAXN 2001
using namespace std;



typedef struct Edge{
  int from,to, rev, f, cap;
  Edge(int from, int to, int rev, int f, int cap):
    from(from),to(to), rev(rev), f(f), cap(cap) {};
} Edge;

vector <Edge> g[MAXN];
int nodes;
int src,dest;
bool vis[MAXN];
int N;

void init_flow(){
  for(int i = 0; i < nodes; i++)
    g[i].clear();
}

void addEdge(int s, int t, int cap){
  g[s].push_back( Edge(s,t, g[t].size(), 0, cap)  );
  g[t].push_back( Edge(t,s, g[s].size()-1, 0, 0)  );
}


int find_path(int s, int t, int f)
{
  int v, df;
  if( s == t )
  {
    return f;
  }
  vis[s] = true;
  for(int i = 0; i < g[s].size(); i++)
  {
    Edge & e = g[s][i];
    if( e.cap - e.f <= 0) continue;
    v  = e.to;
    if( !vis[v] )
    {
      df = find_path(v, t, min(f, e.cap-e.f) );
      if( df > 0)
      {
        e.f += df;
        g[v][e.rev].f -= df;
        return df;
      }
    }
  }
  return 0;
}

int ford_fulkerson(int _src, int _dest){
  int totflow, flow;
  src = _src;
  dest = _dest;
  totflow = 0;
  fill( vis, vis + nodes, false);
  while( flow = find_path(src, dest, 0x7fffffff) )
  {
    totflow += flow;
    fill( vis, vis + nodes, false);
  }
  return totflow;
}

int main(){
    	int n, m, k, count = 1;
    	while(scanf("%d%d%d", &n, &m, &k) > 0){
		N = n+m+1;
		nodes = N+1;
		init_flow();

		for(int i=1; i<=n; i++){
			int cap;
			scanf("%d", &cap);
			addEdge(0, i, cap); 	
		}

		for(int i=1; i<=k; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			addEdge(x, y+n, 1);
		}

		for(int i=1; i<=m; i++){
			addEdge(i+n, N, 1);
		}

		int c = ford_fulkerson(0, N);

		printf("Instancia %d\n%d\n", count++, c);
	}
    	return 0;
}

