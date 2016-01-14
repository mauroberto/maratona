#include<stdio.h>
#include<set>
#include<vector>
#define INF 0x7FFFFFFF

using namespace std;

vector<pair<int,int> >graph[1003];

int N, M;

vector<int> dist(1003);

int dijkstra(){
	for(int i=0; i<=N+1; i++){
		dist[i] = INF;
	}
	set<pair<int, int> > td;
	td.insert(make_pair(0, 0));
	dist[0] = 0;
	while(!td.empty()){
		int v = td.begin()->second;
		td.erase(td.begin());
		int s = graph[v].size();
		for(int i=0; i<s; i++){
			pair<int, int> it = graph[v][i];
			if( dist[it.first] > dist[v] + it.second ){
				if( dist[it.first] != INF )
					td.erase(td.find(make_pair(dist[it.first], it.first)));
				dist[it.first] = dist[v] + it.second;
				td.insert(make_pair(dist[it.first], it.first));
			}
		}
	}

	return dist[N+1];
}

int main(){
	scanf("%d %d", &N, &M);

	for(int i=0; i<M; i++){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		graph[x].push_back(make_pair(y, z));
		graph[y].push_back(make_pair(x, z));
	}

	printf("%d\n", dijkstra());
	return 0;
}
