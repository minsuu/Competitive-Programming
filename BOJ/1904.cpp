#include <bits/stdc++.h>
using namespace std;
int n,a=1,b=1,c,MOD=15746;
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        c=(a+b)%MOD; a=b; b=c;
    }
    cout<<b;
	return 0;
}
