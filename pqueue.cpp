#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;


int main(){
	priority_queue< pair<int, bool>, vector<pair<int, bool> > > pq;
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m, min = 0;
		pair<int, int> p;
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++){
			int x;
			scanf("%d", &x);
			if(i == m)
				p = make_pair(x, true);
			else
				p = make_pair(x, false);
			pq.push(p);
		}

		while(!pq.empty()){
			p = pq.top(); pq.pop();
			min++;
			if(p.second) break;
		}

		printf("%d\n", min);
	}
	return 0;
}
