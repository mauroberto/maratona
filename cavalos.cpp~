#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
using namespace std;
 
struct Edge{
	int to, rev, f, cap;
	Edge(int to, int rev, int f, int cap) :
		to(to), rev(rev), f(f), cap(cap) {};
};

#define V 2015
vector<Edge> g[V];
int dist[V];
int N;
int source, dest;
 
void addEdge(int s, int t, int cap){
	g[s].push_back(Edge(t, g[t].size(), 0, cap));
	g[t].push_back(Edge(s, g[s].size()-1, 0, 0));
}

bool bfs(){
    	memset(dist, -1, sizeof(dist));

	dist[source] = 0; 
    	int q[V];
	int qi = 0, qf = 0;
	q[qf++] = source;
    	
	for( qi = 0; qi < qf; qi++){
        	int u = q[qi];
 
        	for (int j=0; j < g[u].size(); j++){
			Edge & e = g[u][j];
			int v = e.to;
            		if (dist[v] < 0 && e.cap > e.f){
                		q[qf++] = v;
                		dist[v] = dist[u]+1;
            		}
       		}
    	} 
    	return (dist[dest] >= 0);
}
 

int dfs(int u, int f) {
  	if (u == dest) return f;

  	for (int i = 0; i < g[u].size(); i++) {
    		Edge & e = g[u][i];

	    	if (e.cap <= e.f) continue;

	    	int v = e.to;

	    	if (dist[v] == dist[u] + 1) {
	      		int df = dfs(v, min(f, e.cap - e.f));
	      		if (df > 0) {
				e.f += df;
				g[v][e.rev].f -= df;
				return df;
	      		}
	   	}
	}
	return 0;
}

int maxFlow(int _src, int _dest){
	source = _src;
	dest = _dest;
	int result = 0;
	int delta;
	while(bfs()){
		while(delta = dfs(source, 0x7FFFFFFF))
			result += delta;
	}

	return result;
}


int main(){
    	int n, m, k, count = 1;
    	while(scanf("%d%d%d", &n, &m, &k) > 0){
		N = n+m+2;

		for(int i=0; i<=N; i++){
			g[i].clear();
		}

		for(int i=1; i<=n; i++){
			int x;
			scanf("%d", &x);
			addEdge(0, i, 1);	
		}

		for(int i=1; i<=k; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			addEdge(x, y+n, 1);
		}

		for(int i=1; i<=m; i++){
			addEdge(i+n, N, 1);
		}

		int c = maxFlow(0, N);

		cout << "Instancia " << count++ << "\n" << c << "\n";
	}
    	return 0;
}
