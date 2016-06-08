#include <iostream>
#include<stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
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


char string[30001];
int n, i, j, nOp, t;

void check(){
	int r = 1;
	stack <int> pilha;
	for(j=0; string[j] != '\0'; j++){
		if(string[j] == '[' || string[j] == '('){
			pilha.push(string[j]);
		}else{
			if(string[j] == ']' && !pilha.empty() && pilha.top() == '['){
				pilha.pop();
			}else if(string[j] == ')' && !pilha.empty() && pilha.top() == '('){
				pilha.pop();
			}else{
				r = 0;
				break;
			}
		}
	}		
		
	if(r == 1){
		if(!pilha.empty()) r = 0;
	}		

	if(r == 1) printf("Yes\n");
	else printf("No\n");		
}

int main(){

	for(i=0; i<9; i++){
		scanf("%d", &n);
		scanf("%s",string);
		scanf("%d", &nOp);

		while(nOp != 0){
			scanf("%d", &t);
			if(t==0){
				check();
			}else{
				if(string[k] == '(') ? string[k] = ')': string[k] = '(';	
			}
			nOp --;
		}		
	}
	
	return 0;
}
