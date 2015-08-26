// Aug 17 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
const lld MOD = 1e9+7;
lld myhash( string s ){
	lld ret = 0;
	for(auto it : s ){
		if( 'A' <= it && it <= 'Z' ) it += 'a' - 'A';
		if( 'a' <= it && it <= 'z' )
			ret = ( ret * 26 + it - 'a') % MOD;
	}
	return ret;
}
int N;
string buf;
int main(){
	while( 1 ){
		if( scanf("%d\n",&N) == 0 ) break;
		while( 1 ) {
			getline(cin, buf);
			if( buf == "*" ) break;
			
		}
		while( 1 ) {
			getline(cin, buf);
			if( buf == '#' ) break;

		}
	}	
	return 0;
}