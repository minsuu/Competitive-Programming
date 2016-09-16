
#include <bits/stdc++.h>
using namespace std;
int N,a[1010],s,ans;
int main(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>a[i];
    sort(a,a+N);
    for(int i=0;i<N;i++){
        s+=a[i];
        ans+=s;
    }
    cout<<ans;
	return 0;
}
