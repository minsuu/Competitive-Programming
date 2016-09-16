#include <bits/stdc++.h>
using namespace std;
char rot(char c){
    if('A'<=c && c<='Z'){
        c -= 'A';
        c += 13;
        c %= 26;
        c += 'A';
        return c;
    }
    if('a'<=c && c<='z'){
        c -= 'a';
        c += 13;
        c %= 26;
        c += 'a';
        return c;
    }
    return c;
}
string s;
int main(){
    
    getline(cin,s);
    for(char& c : s) c=rot(c);
    cout<<s;
	return 0;
}
