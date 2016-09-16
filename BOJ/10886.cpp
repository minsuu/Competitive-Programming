#include <bits/stdc++.h>
using namespace std;
int N,a,b,n;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>n;
        if(n) a++; else b++;
    }
    if(a>b) cout<<"Junhee is cute!";
    else cout<<"Junhee is not cute!";
	return 0;
}
