#include <bits/stdc++.h>
using namespace std;
string a,b,c;
int cr;
int main(){
	cin>>a>>b;
	while( !a.empty() || !b.empty() || cr ){
		int na = a.empty()? 0 : (a.back()-'0');
		int nb = b.empty()? 0 : (b.back()-'0');
		c.push_back( (na+nb+cr)%10 +'0' );
		cr = (na+nb+cr)/10;	
		if( !a.empty() ) a.pop_back();
		if( !b.empty() ) b.pop_back();
	}
	reverse(c.begin(), c.end() );
	cout<<c<<"\n";
	return 0;
}