#include <bits/stdc++.h>
using namespace std;
int T,b[11];
int main(){
	cin>>T;
    while(T--){
        for(int i=0;i<10;i++) cin>>b[i];
        sort(b, b+10);
        cout<<b[7]<<"\n";
    }
	return 0;
}
