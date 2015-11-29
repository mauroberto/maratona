#include<iostream>
using namespace std;int i,m[101][101],N,j,c;main(){cin>>c;while(c--){cin>>N;i=0;while(i<N){j=0;while(j<=i){cin>>m[i][j++];}i++;}i=0;i=N-2;while(i>=0){j=0;while(j<=i){m[i][j]+=max(m[i+1][j],m[i+1][j+1]);j++;}i--;}cout<<m[0][0]<<"\n";}}
