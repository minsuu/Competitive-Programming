#include <bits/stdc++.h>
using namespace std;
int T;
string A,B;
int main(){
    cin>>T;
    while(T--){
        cin>>A>>B;
        cout<<"Distances: ";
        for(int i=0;i<A.size();i++){
            int r = B[i]-A[i];
            if(r<0) r+=26;
            cout<<r<<" ";
        }
        cout<<"\n";
    }
	return 0;
}
