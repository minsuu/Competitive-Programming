#include <bits/stdc++.h>
using namespace std;
int L,P,n;
int main(){
    cin>>L>>P;
    for(int i=0;i<5;i++){
        cin>>n;
        cout<<n-L*P<<' ';
    }
	return 0;
}
