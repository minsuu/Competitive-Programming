// Sep 08 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;

int T,R,a,b,c, mteam;

struct FRACTION{
	int a,b,i;
	bool operator<(const FRACTION& rhs ) const {
		return ( a*rhs.b == b*rhs.a ) ? i==mteam : a*rhs.b > b*rhs.a ;
	}
};

map<string, int> nmap;
string name, myname, n1,n2;
FRACTION wr[8];

int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		for(int i=0; i<8; i++){
			cin>>name>>a>>b>>c;
			wr[i] = { a, a+b+c, i };
			nmap[name] = i;
		}
		cin>>myname; mteam = nmap[myname];
		cin>>R;
		for(int i=0; i<R; i++){
			cin>>n1>>n2;
			a = nmap[n1], b = nmap[n2];
			wr[a].b++; wr[b].b++;
			if( a == mteam ) wr[a].a++;
			if( b == mteam ) wr[b].a++;
		}
		sort( wr, wr+8 );

		bool poss = false;
		for(int i=0; i<4; i++)
			if( wr[i].i == mteam ) poss = true;
		
		if( poss ) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}