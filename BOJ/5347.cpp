#include <bits/stdc++.h>
using namespace std;
int n,a,b;
int gcd(int a,int b){
    while(b){
        int r=a%b; a=b;b=r;
    }
    return a+b;
}
int main(){
    cin>>n;
    while(n--){
        cin>>a>>b;
        cout<<a*1LL*b/gcd(a,b)<<"\n";
    }
	
	return 0;
}
