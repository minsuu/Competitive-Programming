#include <bits/stdc++.h>
using namespace std;
int N,v[1111],d[1111];
int main(){
    cin>>N;
    for(int i=1;i<=N;i++)cin>>v[i];
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j++){
            d[j]=max(d[j],d[j-i]+v[i]);
        }
    }
    cout<<d[N];
	return 0;
}
