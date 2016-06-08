#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <time.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef set<int> si;
typedef map<string, int> msi;

#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++)
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)


void init_segment_tree(vi & segment_tree, int N) {

  int x = (int)(ceil(log2(N))); //Height of segment tree
  int max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
  segment_tree.resize(max_size, 0); // resize this vector and fill with 0
}

int build_segment_tree(vi & segment_tree, int arr[], int node, int b, int e)
{
    if (b == e)
    {
      printf("(%d,%d) = %d\n", b ,e, b);
      return segment_tree[node] = b;
    }
    else
    {
      int left = 2*node + 1;
      int right = 2*node + 2;
      build_segment_tree(segment_tree, arr, left , b, (b+e)/2);
      build_segment_tree(segment_tree, arr, right, (b+e)/2 + 1, e);
      segment_tree[node] =
      arr[segment_tree[left]] <= arr[segment_tree[right]]? segment_tree[left]
                                                         : segment_tree[right];
      printf("(%d,%d) = %d\n", b, e, segment_tree[node] );
    }
}

int query(vi segment_tree,int arr[], int node, int b, int e, int i, int j) {
  if (i > e || j < b) return -1;
  if (b >= i && e <= j) return segment_tree[node];
  int p1 = query(segment_tree, arr, 2*node+1, b , (b + e) / 2, i, j);
  printf("(%d-%d)=%d\n", b, (b + e) / 2 , p1);
  int p2 = query(segment_tree, arr, 2*node+2, (b + e) / 2 + 1, e , i, j);
  printf("(%d-%d)=%d\n", (b + e) / 2 + 1, e , p2);

  if (p1 == -1) return p2;
  if (p2 == -1) return p1;
  return (arr[p1] <= arr[p2]) ? p1 : p2;
}

void update_segment_tree(vi & segment_tree, int arr[], int node, int b, int e, int i)
{
  printf("update(%d,%d)\n", b, e);
  if( b== e) return ;
  if( i >= b && i <= e)
  {
    int left = 2*node + 1;
    int right = 2*node + 2;
    int mid = b+e/2;
    if( i <= mid )update_segment_tree(segment_tree, arr, left , b, (b+e)/2, i);
    else update_segment_tree(segment_tree, arr, right, (b+e)/2 + 1, e, i);

    segment_tree[node] =
      arr[segment_tree[left]] <= arr[segment_tree[right]]
      ? segment_tree[left]: segment_tree[right];

    printf("(%d-%d)=%d\n", b, e , segment_tree[node] );
  }
}

int main(){
  int A[] = {8,7,3,9,5,1,-3};
  vi segment_tree;
  init_segment_tree(segment_tree, 7);
  build_segment_tree(segment_tree, A, 0, 0, 6);
  //int p = query(segment_tree, A, 0, 0, 6, 1, 5);
  //cout << A[p] << endl;
  A[0] = 2;
  update_segment_tree(segment_tree, A, 0, 0 , 6, 0);
}
