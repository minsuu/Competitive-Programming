#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    getline(cin,s);
    while(getline(cin,s)){
        if('a'<=s[0] && s[0]<='z')
            s[0]=s[0]-'a'+'A';
        cout<<s<<"\n";
    }
	return 0;
}
