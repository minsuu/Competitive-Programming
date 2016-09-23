#include <bits/stdc++.h>
using namespace std;
int T,N;
int main(){
	cin>>T;
    while(T--){
        cin>>N;
        stringstream s;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                s<<(i==0 || j==0 || i==N-1 || j==N-1 ?"#" : "J");
            }
            s<<"\n";
        }
        cout<<s.str()<<"\n";
    }
	return 0;
}
