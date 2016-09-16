#include <bits/stdc++.h>
using namespace std;
string a;
int n;
int main(){
    for(int i=0;i<8;i++){
        cin>>n;
        a.push_back(n+'0');
    }
    if(a=="12345678") cout<<"ascending";
    else if(a=="87654321") cout<<"descending";
    else cout<<"mixed";
	return 0;
}
