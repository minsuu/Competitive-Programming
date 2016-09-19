#include <bits/stdc++.h>
using namespace std;
map<int,int> h;
int n,p,a,c;
int main(){
    cin>>n>>p; a=n;
    while(1){
        if(h.count(a)){
            cout<<c-h[a];
            break;
        }
        h[a]=c++;
        a=a*n%p;
    }
	return 0;
}
