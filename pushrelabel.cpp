#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#define MAXN 100
#define INF 0x7FFFFFFF

using namespace std;

int capacity[MAXN][MAXN];
int flow[MAXN][MAXN];
int excess[MAXN];
int height[MAXN];
int nodes;
int src,dest;
queue <int> q;

void addEdge(int u, int v, int c)
{
  capacity[u][v] = c;
}

void push(int u, int v)
{
  int send = min( excess[u], capacity[u][v] - flow[u][v]);
  printf("empurrando %d pela aresta (%d,%d)\n", send, u, v);
  flow[u][v] += send;
  flow[v][u] -= send;
  excess[u] -= send;
  excess[v] += send;
  printf("excess[%d] = %d\n", u, excess[u]);
  printf("excess[%d] = %d\n", v, excess[v]);

  if( excess[u] > 0) q.push(u);
  if( excess[v] > 0 && v != dest) q.push(v);


}

void relabel(int u)
{
  int min_height = INF;
  int old_height = height[u];

  printf("relabel vertex %d\n", u);
  for(int v = 0; v < nodes; v++)
  {
    if( capacity[u][v] - flow[u][v] > 0)
    {
      min_height = min( min_height, height[v] );
      height[u] = min_height + 1;
    }
  }

  printf("old_height %d new_height %d\n", old_height, height[u]);
  if( height[u] > old_height)
    q.push(u);

}

int check_node(int i)
{
  if( excess[i] <= 0) return -1;

  //printf("checking\n");
  for(int j = 0; j < nodes; j++)
  {
    //printf("capacidade %d\n", capacity[i][j] - flow[i][j] );
    //printf("height[%d] = %d height[%d] = %d\n",i, height[i], j, height[j]);
    //printf("%d\n", (height[i] == (height[j] + 1) ) );
    if( capacity[i][j] - flow[i][j] > 0 && (height[i] == (height[j] + 1) )  )
    {
      return j;
    }
  }
  return -1;
}

void preflow()
{
  fill( excess, excess + nodes, 0);
  fill( height, height + nodes, 0);

  height[src] = nodes;
  for(int i = 0; i < nodes; i++)
  {
    if( capacity[src][i] > 0)
    {
      flow[src][i] = capacity[src][i];
      flow[i][src] = -capacity[src][i];
      excess[i] = capacity[src][i];
      excess[src] -= capacity[src][i];
      if( i != dest)
      {
        q.push(i);
      }
    }
  }

  for(int i = 0; i < nodes; i++)
  {
    printf("height[%d] = %d, excess[%d] = %d\n", i, height[i], i, excess[i]);
  }
}

void push_relabel(int _src, int _dest)
{
  src = _src;
  dest = _dest;
  preflow();
  while(!q.empty())
  {
    int current = q.front();
    int target = check_node(current);
    //printf("analisando vertice %d height %d excess %d\n",
    //       current , height[current] , excess[current]);
    if( target >= 0)
    {
      //printf("push\n");
      push(current, target);
    }else{
      if( excess[current] > 0)
      {
        //printf("relabel\n");
        relabel(current);
      }
    }
    q.pop();

    for(int i = 0; i < nodes; i++)
      printf("excess[%d] = %d, height[%d] = %d\n", i, excess[i],i, height[i]);


    system("PAUSE");
  }


  printf("flow matrix: \n");
  for(int i = 0; i < nodes; i++)
  {
    for(int j = 0; j < nodes; j++)
    {
      printf("%3d ", flow[i][j]);
    }
    printf("\n");
  }

  int totflow = 0;
  for(int i = 0; i < nodes; i++)
  {
    totflow += flow[src][i];
  }

  printf("maximum flow %d\n", totflow );

}

void push_relabel2(int _src, int _dest)
{
  src = _src;
  dest = _dest;
  preflow();
  while(!q.empty())
  {
    int u = q.front();
    int m = INF;
    for(int v = 0; v < nodes && excess[u] > 0; v++)
    {
      if( capacity[u][v] - flow[u][v] > 0)
      {
        if( height[u] > height[v] )
        {
          push(u,v);
          if( height[v] == 0 && v != src && v != dest)
          {
            q.push(v);
            height[v] = 1;
          }
        }
        else m = min(m, height[v]);
      }
    }
    if( excess[u] != 0 )
      height[u] = m + 1;
    else
      q.pop();
  }



  printf("flow matrix: \n");
  for(int i = 0; i < nodes; i++)
  {
    for(int j = 0; j < nodes; j++)
    {
      printf("%3d ", flow[i][j]);
    }
    printf("\n");
  }

  int totflow = 0;
  for(int i = 0; i < nodes; i++)
  {
    totflow += flow[src][i];
  }

  printf("maximum flow %d\n", totflow );

}



int main(){

  memset( capacity, 0, sizeof(capacity));
  memset( flow, 0, sizeof(flow));

  //nodes = 3;
  //addEdge(0,1,3);
  //addEdge(1,2,2);
  //addEdge(0,2,2);
  //push_relabel(0,2);

  nodes = 6;
  addEdge(0,1,15);
  addEdge(1,2,8);
  addEdge(2,1,4);
  addEdge(2,3,3);
  addEdge(3,0,4);
  addEdge(3,4,6);
  addEdge(4,3,4);
  addEdge(1,4,4);
  addEdge(4,1,1);
  addEdge(4,5,10);
  addEdge(2,5,3);
  addEdge(5,2,4);
  push_relabel2(0,5);




}
