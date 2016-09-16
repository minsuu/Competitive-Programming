
#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int N;
// 1,2,4 : each
lld d[33][8],f[8][8];

int main(){
    for(int i=0;i<8;i++){
        int j=0;
        if(!(i&1)) j|=1;
        if(!(i&2)) j|=2;
        if(!(i&4)) j|=4;
        f[i][j] = 1;
        if(((~j)&3)==3) f[i][j|3]=1;
        if(((~j)&6)==6) f[i][j|6]=1;
    }
    cin>>N;
    d[0][7]=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<8;j++){
            for(int k=0;k<8;k++){
                d[i+1][k]+=d[i][j]*f[j][k];
            }
        }
    }
    cout<<d[N][7];
	return 0;
}
