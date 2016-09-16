#include <bits/stdc++.h>
using namespace std;
int N,a,b,c;
int sc(int a,int b,int c){
    if(a==b && b==c) return 10000+a*1000;
    if(a==b || a==c) return 1000+a*100;
    if(b==c) return 1000+b*100;
    return max(a,max(b,c))*100;
}
int ans;
int main(){
    cin>>N;
    while(N--){
        cin>>a>>b>>c;
        ans = max(ans,sc(a,b,c));
    }
    cout<<ans;
	return 0;
}
