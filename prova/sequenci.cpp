#include<stdio.h>
#include <iostream>
int v[31];
int matriz[31][1001];

using namespace std;

int n;

void pd(int w){
	for (int i=0;i<=n;i++){
		for (int j=0;j<=w;j++){
			if(j == 0)matriz[i][j] = 1;
			else matriz[i][j] = 0;
		}
	}

	matriz[0][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=w;j++){
			matriz[i][j] = matriz[i-1][j] || matriz[i][j];
			if(j-v[i-1] >= 0) matriz[i][j] |= matriz[i-1][j-v[i-1]];
		}

	}   
}

int main(){
	int t = 0;
	while((cin >> n) != EOF){
		t++;
		int flag = 1;
		for(int i = 0; i < n; i++){
			cin >> v[i];
		}
		pd(v[n-1]);
		cout << "Case #" << t < ":";
		for(int i = 0; i < n; i++){
			cout << " " << v[i];
		}
		cout << endl;
		for(int j = n; j >= 2; j--){
			if(matriz[j-1][v[j-1]]) flag = 0;
		}

		if(flag) printf("This is an A-sequence.\n");
		else printf("This is not an A-sequence.\n");
	}
}
