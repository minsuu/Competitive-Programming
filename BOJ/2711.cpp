#include <bits/stdc++.h>
using namespace std;
int T,i;
string s;
int main(){
    cin>>T;
    while(T--){
        cin>>i>>s;
        s.erase(s.begin()+i-1);
        cout<<s<<"\n";
    }
	return 0;
}
