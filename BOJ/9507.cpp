#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
lld T,N,kk[111];
int main(){
	cin>>T;
    kk[0] = kk[1] = 1;
    kk[2] = 2;
    kk[3] = 4;
    for(int i=4;i<100;i++)
        kk[i] = kk[i-1] + kk[i-2] + kk[i-3] + kk[i-4];
    
    while(T--){
        cin>>N;
        cout<<kk[N]<<"\n";
    }
	return 0;
}
