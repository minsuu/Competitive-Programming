#include <bits/stdc++.h>
using namespace std;
int T,K,N;
int main(){
	cin>>T;
    while(T--){
        cin>>K>>N;
        vector<int> a(N,1),b(N);
        for(int i=0;i<=K;i++){
            for(int j=0;j<N;j++)
                b[j]=(j?b[j-1]:0)+a[j];
            a.swap(b);
        }
        cout<<a[N-1]<<"\n";        
    }
	return 0;
}
