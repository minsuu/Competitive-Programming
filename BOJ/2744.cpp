#include <bits/stdc++.h>
using namespace std;

string s;
char op(char a){
    if('A'<=a && a<='Z')
        return a-'A'+'a';
    if('a'<=a && a<='z')
        return a-'a'+'A';
    return -1;
}
int main(){
    cin>>s;
    for(char& i : s)
        i = op(i);
    cout<<s;
    return 0;
}
