#include <bits/stdc++.h>
using namespace std;
int a[3];
string s;
int main(){
    for(int i=0;i<3;i++) cin>>a[i];
    sort(a, a+3);
    cin>>s;
    for(char c : s){
        cout<<a[c-'A']<<' ';
    }
	return 0;
}
