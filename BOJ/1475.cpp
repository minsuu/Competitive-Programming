#include <bits/stdc++.h>
using namespace std;
int N,c[10],ans;
int main(){
	cin>>N;
    for(;N;N/=10) c[N%10]++;
    c[9]=c[6]=(c[6]+c[9]+1)/2;
    for(int i=0;i<10;i++)
        ans=max(ans,c[i]);
    cout<<ans;
	return 0;
}
