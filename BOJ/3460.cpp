#include <bits/stdc++.h>
using namespace std;
int T,N;
int main(){
	cin>>T;
    while(T--){
        cin>>N;
        for(int i=0;(1<<i)<=N;i++){
            if((1<<i)&N) cout<<i<<" ";
        }
        cout<<"\n";
    }
	return 0;
}
