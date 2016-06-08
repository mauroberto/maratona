#include<stdio.h>
#include<queue>
using namespace std;

int main(){
	priority_queue< pair<int, int>, vector < pair<int, int> >, greater <pair<int, int> > > ocupados;
	int qtd[10002];
	int N, L;
	scanf("%d%d", &N, &L);
	for(int i=1; i<=N; i++){
		qtd[i] = 0;
		ocupados.push(make_pair(0, i));
	}
	for(int i=0; i<L; i++){
		int l;
		scanf("%d", &l);
		pair<int, int> p;
		p = ocupados.top();
		ocupados.pop();
		qtd[p.second]++;		
		ocupados.push(make_pair(p.first+l, p.second));
	}
	
	for(int i = 1; i<=N; i++){
		printf("%d %d\n", i, qtd[i]);
	}
	return 0;
}
