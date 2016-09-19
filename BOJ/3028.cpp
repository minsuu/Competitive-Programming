#include <bits/stdc++.h>
using namespace std;
string s;
int a[3]={1,0,0};
int main(){
	cin>>s;
    for(char c:s){
        if(c=='A') swap(a[0],a[1]);
        if(c=='B') swap(a[1],a[2]);
        if(c=='C') swap(a[0],a[2]);
    }
    if(a[0]) cout<<"1";
    if(a[1]) cout<<"2";
    if(a[2]) cout<<"3";
	return 0;
}
