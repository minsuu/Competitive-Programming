#include <bits/stdc++.h>
using namespace std;
int T,a[5];
int main(){
	cin>>T;
    while(T--){
        for(int i=0;i<5;i++){
            cin>>a[i];
        }
        sort(a,a+5);
        if(a[3]-a[1]>=4) cout<<"KIN\n";
        else cout<<a[1]+a[2]+a[3]<<"\n";
    }
	return 0;
}
