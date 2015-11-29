#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int m[500][500];

int pd(vector<pair<int, int> > v, int l){
    for(int i = 0; i < 500; i++){
        for(int j = 0; j < 500; j++){
            m[i][j]=0x3f3f3f3f;
        }
    }
    for(int i = 0; i < v.size(); i++){
        m[i][0] = (i+1)*v[i].second;
    }
    for(int j = 1; j < l; j++){
        for(int i = j; i < v.size(); i++){
            int mini=0x3f3f3f3f;
            for(int k=1; i-k >= 0; k++){
                mini = min(mini, m[i-k][j-1] + k*v[i].second);
            }
            m[i][j] = mini;
        }
    }
    return m[v.size()-1][l-1];
}

int main(){
    int k, l, d, p;
    vector<pair<int, int> > v;
    scanf("%d %d", &k, &l);
    while(k != 0 || l != 0){
        v.clear();
        while(k--){
            scanf("%d %d", &d, &p);
            v.push_back(make_pair(d, p));
        }

        sort(v.begin(), v.end());
        printf("%d\n", pd(v, l));
        scanf("%d %d", &k, &l);
    }
    
    return 0;
}
