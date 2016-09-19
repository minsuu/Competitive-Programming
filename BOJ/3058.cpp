#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
    cin>>T;
    while(T--){
        int a,s=0,mm=101010;
        for(int i=0;i<7;i++){
            cin>>a;
            if(a%2==0){
                s+=a;
                mm=min(mm,a);
            }
        }
        cout<<s<<" "<<mm<<"\n";
        
    }
	return 0;
}
