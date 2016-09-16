#include <bits/stdc++.h>
using namespace std;
int T,a,b;
int main(){
    cin>>T;
    while(T--){
        int A=0,B=0;
        for(int i=0;i<9;i++){
            cin>>a>>b;
            A+=a; B+=b;
        }
        if(A>B) cout<<"Yonsei\n";
        else if(A<B) cout<<"Korea\n";
        else cout<<"Draw\n";
    }
	return 0;
}
