#include <bits/stdc++.h>
using namespace std;
int rev(int x){
    int r=0;
    for(;x;x/=10) r=r*10+x%10;
    return r;
}
int T,N;
int main(){
    cin>>T;
    while(T--){
        cin>>N;
        int a=N+rev(N);
        cout<<(a==rev(a)? "YES":"NO")<<"\n";
    }
	return 0;
}
