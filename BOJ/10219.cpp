#include <bits/stdc++.h>
using namespace std;
int T,H,W;
string a[12];
int main(){
	cin>>T;
    while(T--){
        cin>>H>>W;
        for(int i=0;i<H;i++)
            cin>>a[i];
        for(int i=H-1;i>=0;i--)
            cout<<a[i]<<"\n";
    }
	return 0;
}
