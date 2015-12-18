#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
#include <stdio.h>
using namespace std;
 
#define V 2001
int rGraph[V][V];
int parent[V];
bool visited[V];
int N;


bool bfs(int s, int t){
    memset(visited, 0, sizeof(visited)); 
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    while (!q.empty()){
        int u = q.front();
        q.pop();
 
        for (int v=0; v<=N; v++){
            if (visited[v]==false && rGraph[u][v] > 0){
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    } 
    return (visited[t] == true);
}
 
int fordFulkerson(int s, int t){
    int u, v;
    int max_flow = 0;
    memset(parent, -1, sizeof(parent)); 
    
    while (bfs(s, t)){
        for (v=t; v != s; v=parent[v]){
            u = parent[v];
            rGraph[u][v] --;
            rGraph[v][u] ++;
        }

        max_flow ++;
    }
    
    return max_flow;
}
 
int main(){
    	int n, m, k, count = 1;
    	while(scanf("%d%d%d", &n, &m, &k) > 0){
		N = n+m+2;

		for(int i=0; i<=N; i++){
			for(int j=0; j<=N; j++){
				rGraph[i][j] = 0;
			}
		}

		for(int i=1; i<=n; i++){
			scanf("%d", &rGraph[0][i]);
			rGraph[i][0] = 0; 	
		}

		for(int i=1; i<=k; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			rGraph[x][y+n] = 1;
			rGraph[y+n][x] = 0;
		}

		for(int i=1; i<=m; i++){
			rGraph[i+n][N] = 1;
			rGraph[N][i+n] = 0;
		}

		int c = fordFulkerson(0, N);

		cout << "Instancia " << count++ << "\n" << c << "\n";
	}
    	return 0;
}

