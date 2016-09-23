#include <bits/stdc++.h>
using namespace std;
int T,a,b;
int gcd(int a,int b){
    while(b){ int r=a%b;a=b;b=r; }
    return a+b;
}
int main(){
	cin>>T;
    while(T--){
        cin>>a>>b;
        cout<<a*b/gcd(a,b)<<" "<<gcd(a,b)<<"\n";
    }
	return 0;
}
