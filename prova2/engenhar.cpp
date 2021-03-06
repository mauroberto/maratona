#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <vector>

#define MAXN 210
#define INF 0x7FFFFFFF
using namespace std;

struct Edge{
  int from,to, rev, f, cap;
  Edge(int from, int to, int rev, int f, int cap):
    from(from),to(to), rev(rev), f(f), cap(cap) {};
};

vector <Edge> g[MAXN];
int nodes;
int src,dest;
bool vis[MAXN];
int dist[MAXN];

void init_flow(){
	for(int i = 0; i <= nodes; i++)
    		g[i].clear();
}

void addEdge(int s, int t, int cap){
  	g[s].push_back( Edge(s,t, g[t].size(), 0, cap));
  	g[t].push_back( Edge(t,s, g[s].size()-1, 0, 0));
}


int find_path(int s, int t, int f){
	int v, df;
  	if( s == t ){
    		return f;
  	}
  	vis[s] = true;
	int size = g[s].size();
  	for(int i = 0; i < size; i++){
    		Edge & e = g[s][i];
    		if( e.cap - e.f <= 0) continue;
    		v  = e.to;
    		if( !vis[v] ){
     	 		df = find_path(v, t, min(f, e.cap-e.f) );
      			if( df > 0){
        			e.f += df;
        			g[v][e.rev].f -= df;
        			return df;
      			}
    		}
  	}
  	return 0;
}

int ford_fulkerson(int _src, int _dest){
  	int totflow = 0;
  	src = _src;
  	dest = _dest;
  	fill(vis, vis + nodes, false);
  	while(find_path(src, dest, INF)){
    		totflow ++;
    		fill(vis, vis + nodes, false);
  	}
  	return totflow;
}

int main(){
	int n, k, N;
	scanf("%d", &k);
	for(int j=1; j<=k; j++){
		scanf("%d", &n);
		N = n+n+4;
		nodes = N+1;
		init_flow();
		
		for(int i=1; i<=n; i++){
			addEdge(0, i, 1); 	
		}

		for(int i=1; i<=n; i++){
			int p;
			scanf("%d", &p);
			while(p--){
				int x;
				scanf("%d", &x);
				addEdge(i, x+n+1, 1);
				addEdge(x, n+i+1, 1);
			}
		}	

		for(int i=1; i<=n; i++){
			addEdge(i+n+1, N, 1);
		}

		printf("Instancia %d\n", j);

		if(n%2==1 || ford_fulkerson(0, N) != n){
			printf("extreme programming\n");
		}else{
			printf("pair programming\n");
		}	
		printf("\n");
	}
	return 0;
}
