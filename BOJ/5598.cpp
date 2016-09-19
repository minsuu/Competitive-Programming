#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin>>s;
    for(char& c : s){
        c = (c-'A'-3+26)%26+'A';
    }
    cout<<s;
	return 0;
}
