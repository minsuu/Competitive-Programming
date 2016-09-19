#include <bits/stdc++.h>
using namespace std;
int N,K,a[11];
int main(){
	cin>>N>>K;
    for(int i=0;i<N;i++) cin>>a[i];
    int ans = 0;
    for(int i=N-1;i>=0;i--){
        ans += K/a[i];
        K%=a[i];
    }
    cout<<ans;
	return 0;
}
