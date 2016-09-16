#include <bits/stdc++.h>
using namespace std;
int ans2=101010,ans,M,N;
int main(){
    cin>>M>>N; 
    for(int i=1;i<=200;i++){
        int j = i*i;
        if(M<=j && j<=N){
            ans+=j;
            ans2=min(ans2,j);
        }
    }
    if(ans)
        cout<<ans<<'\n'<<ans2;
    else
        cout<<"-1";
	return 0;
}
