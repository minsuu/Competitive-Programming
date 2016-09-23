#include <bits/stdc++.h>
using namespace std;
int T,C,c[4]={25,10,5,1};
int main(){
	cin>>T;
    while(T--){
        cin>>C;
        for(int i=0;i<4;i++){
            cout<<C/c[i]<<" ";
            C%=c[i];
        }
        cout<<"\n";
    }
	return 0;
}
