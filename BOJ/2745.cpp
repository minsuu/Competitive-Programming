#include <bits/stdc++.h>
using namespace std;
char cn[256];
string n;
int b,ans;
int main(){
	for(int i=0;i<=9;i++) cn[i+'0']=i;
    for(int i='A';i<='Z';i++) cn[i]=i-'A'+10;
    cin>>n>>b;
    for(char i : n){
        ans *= b;
        ans += cn[i];
    }
    cout<<ans;
	return 0;
}
