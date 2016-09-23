#include <bits/stdc++.h>
using namespace std;
int T,N,a[55];
int main(){
	cin>>T;
    for(int t=1;t<=T;t++){
        cin>>N;
        for(int i=0;i<N;i++) cin>>a[i];
        sort(a, a+N);
        int d=0;
        for(int i=1;i<N;i++)
            d=max(d,a[i]-a[i-1]);
        cout<<"Class "<<t<<"\n";
        cout<<"Max "<<a[N-1]<<", Min "<<a[0]<<", Largest gap "<<d<<"\n";
    }
	return 0;
}
