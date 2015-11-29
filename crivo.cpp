//Crivo
#include<iostream>
#include<bitset>

using namespace std;

int main(){
	bitset <1000001> bs;
	bs.set();
	bs.set(1,0);
	for(int i=2; i<=1000; i++){
		for(int j=i*i; j <= 1000000; j=j+i){
			bs.set(j,0);
		}
	}
	cout << bs.count() << endl;

	return 0;
}
