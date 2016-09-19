#include <bits/stdc++.h>
using namespace std;
int T;
string S;
int main(){
	cin>>T;
    while(T--){
        cin>>S;
        cout<<*S.begin()<<S.back()<<"\n";
    }
	return 0;
}
