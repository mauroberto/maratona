#include<stdio.h>
#include<set>
#include<vector>
#define INF 0x7FFFFFFF

using namespace std;
enum Cor {WHITE, GREY, BLACK};

vector<pair<int,int> >graph[10050];

int N, M;


int primMST() {
	int p[10050], w[10050];
  	int i, imin, v, r=0, cor[10050];

	vector<int> f;
  	for (i=0; i<=N; i++) {
		w[i] = INF;
    		p[i] = -1;
    		cor[i] = WHITE;
  	}
  	cor[0] = GREY;
  	w[0] = 0;
  	f.push_back(0);
  	
  	while (!f.empty()) {
    		imin = 0;
		int fsize = f.size(); 
    		for (i=1; i<fsize; i++)
      			if (w[f[i]] < w[f[imin]]) imin = i;
    		v = f[imin];
    		f[imin] = f[fsize-1];
		f.pop_back();
    		cor[v] = BLACK;
    		r += w[v];
 		int size = graph[v].size();
    		for (int i=0; i<size; i++){
      			switch (cor[graph[v][i].first]){
				case WHITE:
	  				cor[graph[v][i].first] = GREY;
	  				f.push_back(graph[v][i].first); 
          				w[graph[v][i].first] = graph[v][i].second;
	  				p[graph[v][i].first] = v;
	  				break;
				case GREY:
	  				if (graph[v][i].second < w[graph[v][i].first]) {
	    					p[graph[v][i].first] = v;
	   	 				w[graph[v][i].first] = graph[v][i].second;
	  				}
	  				break;
				default:
	  				break;
			}
		}
  	}
  	return r;
}

int main(){
	scanf("%d %d", &N, &M);

	for(int i=0; i<M; i++){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		graph[x].push_back(make_pair(y, z));
		graph[y].push_back(make_pair(x, z));
	}

	printf("%d\n", primMST());
	return 0;
}
