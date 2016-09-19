#include <bits/stdc++.h>
using namespace std;
int n,a;
int main(){
	cin>>n;
    while(1){
        cin>>a; if(a==0) break;
        if(a%n) cout<<a<<" is NOT a multiple of "<<n<<".\n";
        else cout<<a<<" is a multiple of "<<n<<".\n";
    }
	return 0;
}
