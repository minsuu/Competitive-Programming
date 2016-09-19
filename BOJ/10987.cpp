#include <bits/stdc++.h>
using namespace std;
const string vow="aeiou";
bool aeae(char i){
    return vow.find(i) != string::npos;
}
string a;
int ans;
int main(){
    cin>>a;
    for(char c : a){
        ans += aeae(c);
    }
    cout<<ans;
	return 0;
}
