#include <bits/stdc++.h>
using namespace std;
string a = "* ";
string b = " *";
string c,d;
int N;
int main(){
	cin>>N;
    for(int i=0;i<N;i++){
        c+=a; d+=b;
    }
    for(int i=0;i<N;i++){
        if(i%2) cout<<d<<"\n";
        else cout<<c<<"\n";
    }

	return 0;
}
