#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define pii pair<int, int>
#define pip pair<int, pii>
#define F first
#define S second

const int MAX = 200001;

class Union_Find{
  public:

	int id[MAX], sz[MAX];
	Union_Find(int n){
		for (int i = 0; i < n; i++){
			id[i] = i;
			sz[i] = 1;
		}
	}
	
	int root(int i){
		while(i != id[i]){
			id[i] = id[id[i]];
			i = id[i];
		}
		return i;
	}

	int find(int p, int q){
		return root(p)==root(q);
	}
	void unite(int p, int q){
		int i = root(p);
		int j = root(q);

		if(sz[i] < sz[j]){
			id[i] = j;
			sz[j] += sz[i];
		} else {
			id[j] = i;
			sz[i] += sz[j];
		}
	}
};


priority_queue < pip, vector<pip>, greater <pip> > graph;
int n, e;

int Kruskal_MST(){
	Union_Find UF(n);
	int u, v;
	int T = 0;
		
	while(!graph.empty()){
		pip ini = graph.top(); graph.pop();
		u = ini.S.F;
		v = ini.S.S;
		if(!UF.find(u, v)){
			UF.unite(u, v);
			T += ini.F;
		}
	}
	return T;
}

int main(){
	while(1){
		scanf("%d %d", &n, &e);
		if(e == 0 && n == 0) break;
		int x, y, z;
		int total = 0;
		for(int i=0; i<e; i++){
			scanf("%d %d %d", &x, &y, &z);
			graph.push(make_pair(z, make_pair(x, y)));
			total += z;
		}
		printf("%d\n", total - Kruskal_MST());
	}
	return 0;
}
