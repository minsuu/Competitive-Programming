#include <bits/stdc++.h>
using namespace std;
int T,N;
int main(){
	cin>>T;
    while(T--){
        cin>>N;
        int A=0,B=987654321;
        for(int i=0;i<N;i++){
            int a; cin>>a;
            A=max(A,a); B=min(B,a);
        }
        cout<<(A-B)*2<<"\n";
    }
	return 0;
}
