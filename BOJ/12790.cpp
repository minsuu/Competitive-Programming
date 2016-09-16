#include <bits/stdc++.h>
using namespace std;
int T,z[4];
int main(){
    cin>>T;
    while(T--){
        for(int i=0;i<4;i++) cin>>z[i];
        for(int i=0;i<4;i++){
            int j; cin>>j; z[i]+=j;
        }
        z[0] = max(1,z[0]);
        z[1] = max(1,z[1]);
        z[2] = max(0,z[2]);
        cout<<z[0] + 5*z[1] + 2*z[2] + 2*z[3]<<"\n";
    }
	return 0;
}
