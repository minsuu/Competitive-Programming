#include <bits/stdc++.h>
using namespace std;
int N,r,e,c;
int main(){
	cin>>N;
    for(int i=0;i<N;i++){
        cin>>r>>e>>c;
        e-=c;
        if(r>e) cout<<"do not advertise\n";
        else if(r<e) cout<<"advertise\n";
        else cout<<"does not matter\n";
    }
	return 0;
}
