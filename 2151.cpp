#include<stdio.h>
#include<queue>

using namespace std;

int x[8] = {0, -1, 0, 1, 1, -1, 1, -1};
int y[8] = {1, 0, -1, 0, 1, -1, -1, 1};

int M, N;

int m[101][101];
int n[101][101];
bool v[101][101];


void bfs(int sx, int sy){
  queue< pair<int , int> > q;
  q.push(make_pair(sx,sy));
  n[sy][sx] = 10;
  v[sy][sx] = true;

  while(!q.empty()){
    pair <int, int> p = q.front(); q.pop();
    sx = p.first;
    sy = p.second;

    for(int i=0; i<8; i++){
      int nsy = sy + y[i];
      int nsx = sx + x[i];
      if(nsy < M && nsy >= 0 && nsx < N && nsx >= 0 && !v[nsy][nsx]){
        v[nsy][nsx] = true;
        if(n[sy][sx] == 1){
          n[nsy][nsx] = 1;
        }else{
          n[nsy][nsx] += (n[sy][sx] - 1);
        }
        q.push(make_pair(nsx, nsy));
      }
    }
  }
}


int main(){
  int t;
  scanf("%d", &t);

  for(int i=1; i<=t; i++){
    printf("Parede %d:\n", i);

    scanf("%d %d", &M, &N);
    for(int l = 0; l < M; l++){
      for(int k = 0; k < N; k++){
        v[l][k] = false;
        n[l][k] = 0;
      }
    }

    int X, Y;
    scanf("%d %d", &X, &Y);

    for(int l = 0; l < M; l++){
      for(int k = 0; k < N; k++){
        scanf("%d", &m[l][k]);
      }
    }

    bfs(Y-1, X-1);

    for(int l = 0; l < M; l++){
      for(int k = 0; k < N; k++){
        if(k == N-1){
            printf("%d", n[l][k] + m[l][k]);
            break;
        }
        printf("%d ", n[l][k] + m[l][k]);
      }
      printf("\n");
    }

  }
  return 0;
}
