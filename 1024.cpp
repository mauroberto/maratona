#include<stdio.h>
#include<iostream>

using namespace std;

void clear (void){    
  while ( getchar() != '\n' );
}

int main(){
	int N;
	scanf("%d", &N);	
	clear();
	while(N--){
		char string[1010];
		cin.getline(string,sizeof(string));
		int i;
		for(i=0; string[i] != '\0'; i++){
			if(string[i] >= 97 && string[i] <= 122 || string[i] >= 65 && string[i] <= 90)
				string[i]+=3;
		}

		int metade = (i-1)/2;

		for(int j=i-1; j>=0; j--){
			if(j<=metade){
				printf("%c", string[j]-1);
			}else{
				printf("%c", string[j]);
			}	
		}
		printf("\n");
	}
}
