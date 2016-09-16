#include <bits/stdc++.h>
using namespace std;
int N,A,B;
int main(){
	cin>>N>>A>>B;
    if(A>B) swap(A,B);
    for(int r=1;;r++){
        if(A%2==1 && A+1==B){
            cout<<r<<"\n"; break;
        }
        A = (A+1)/2; B = (B+1)/2;
    }
	return 0;
}
