#include <bits/stdc++.h>
using namespace std;
int V,a,b;
string s;
int main(){
	cin>>V>>s;
    for(int i=0;i<V;i++){
        if(s[i]=='A') a++;
        if(s[i]=='B') b++;
    }
    if(a>b) cout<<"A";
    if(a<b) cout<<"B";
    if(a==b) cout<<"Tie";
	return 0;
}
