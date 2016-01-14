#include<stdio.h>
#include<set>
#include<vector>
#define INF 0x7FFFFFFF

using namespace std;

vector<pair<int,int> >graph[1003];

int N, M;

vector<int> dist(1003);


int dijkstra(int ini, int fim){
	for(int i=0; i<=N; i++){
		dist[i] = INF;
	}
	set<pair<int, int> > td;
	td.insert(make_pair(0, ini));
	dist[ini] = 0;
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

	return dist[fim];
}


int main(){
	scanf("%d %d", &N, &M);
	
	while(N != 0 || M != 0){

		for(int i=0; i<=N; i++){
			graph[i].clear();
		}

		for(int i=0; i<M; i++){
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			graph[x].push_back(make_pair(y, z));
		}

		int ini, fim;
		scanf("%d %d", &ini, &fim);
		int r = dijkstra(ini, fim);
		if(r == INF) printf("%d\n", -1);
		else printf("%d\n", r);

		scanf("%d %d", &N, &M);
	}
	return 0;
}
