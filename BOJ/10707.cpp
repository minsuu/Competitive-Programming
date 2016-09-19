#include <bits/stdc++.h>
using namespace std;
int A,B,C,D,P,ans=987654321;
int main(){
    cin>>A>>B>>C>>D>>P;
    cout<<min(P*A, B+max(0,P-C)*D);
	return 0;
}
