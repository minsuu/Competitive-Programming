#include <bits/stdc++.h>
using namespace std;
int T,N;
map<int,string> m;
int main(){
	cin>>T;
    while(T--){
        cin>>N;
        for(int i=0;i<N;i++){
            int a; string b;
            cin>>b>>a;
            m[a]=b;
        }
        cout<<m.rbegin()->second<<"\n";
    }
	return 0;
}
