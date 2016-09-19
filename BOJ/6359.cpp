#include <bits/stdc++.h>
using namespace std;
const int LIM = 110;
int T,n;
int siv[110];
int main(){
	cin>>T;
    for(int i=1;i<LIM;i++){
        for(int j=i;j<LIM;j+=i)
            siv[j]^=1;
    }
    while(T--){
        cin>>n;
        int ans = 0;
        for(int i=1;i<=n;i++)
            ans+=siv[i];
        cout<<ans<<"\n";
    }
	return 0;
}
