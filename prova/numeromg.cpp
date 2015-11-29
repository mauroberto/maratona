#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

string n1, n2;
vector<int> resposta;
int r;


int main(){
	cin >> n1 >> n2;
	while(n1 != "0" || n2 != "0"){
		resposta.clear();
		int a = 0; 
		int pos1, pos2;
		for(int i = n1.size()-1, j = n2.size()-1; i >= 0 && j >= 0; i--, j--){
			int vn1, vn2;
			if(n1[i] >= 65){
				vn1 = n1[i] - 55;
			}else{
				vn1 = n1[i] - 48;
			}		

			if(n2[j] >= 65){
				vn2 = n2[j] - 55;
			}else{
				vn2 = n2[j] - 48;
			}
	
			if(vn1 + vn2 + a >= 36){
				resposta.push_back((vn1+vn2+a)%36);
				a = 1;
			}else{
				resposta.push_back(vn1+vn2+a);
				a = 0;
			}
			pos1 = i; pos2 = j;
		}

		for(int i = pos1-1; i>=0; i--){
			int vn1;
			if(n1[i] >= 65){
				vn1 = n1[i] - 55;
			}else{
				vn1 = n1[i] - 48;
			}		
	
			if(vn1+a >= 36){
				resposta.push_back((vn1+a)%36);
				a = 1;
			}else{
				resposta.push_back(vn1+a);
				a = 0;
			}
		}

		for(int j = pos2-1; j>=0; j--){
			int vn2;
			if(n2[j] >= 65){
				vn2 = n2[j] - 55;
			}else{
				vn2 = n2[j] - 48;
			}		
	
			if(vn2+a >= 36){
				resposta.push_back((vn2+a)%36);
				a = 1;
			}else{
				resposta.push_back(vn2+a);
				a = 0;
			}
		}

		if(a == 1){
			resposta.push_back(1);
		}

		for(int i = resposta.size()-1; i>=0; i--){
			if(resposta[i] >= 10){
				printf("%c", resposta[i]+55);
			}else{
				printf("%c", resposta[i]+48);
			}
		}

		printf("\n");
		cin >> n1 >> n2;
	}
}
