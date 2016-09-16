#include <bits/stdc++.h>
using namespace std;
int c[26];
string S;
int main(){
    memset(c, -1, sizeof c);
    cin>>S;
    for(int i=0; i<S.size(); i++){
        int j=S[i]-'a';
        if(c[j]==-1) c[j]=i;
    }
    for(int i=0;i<26;i++)
        cout<<c[i]<<' ';
	return 0;
}
