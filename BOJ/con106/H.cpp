#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int cache[1111][11][11][11];
// ll, l, [i]
int rec( int i, int g, int ll, int l ){
	if( i == 0 ) return (g==0);
	if( g>=10 ) return 0;

	int& ret = cache[i][g][ll][l];
	if( ret != -1 ) return ret;

	ret = 0;
	if( ll == 0 ){
		if( l == 0 ){
			for(int n=1; n<=9; n++){
				ret += rec( i-1, g-1, 0, n );
				ret %= MOD;
			}
		}else{
			for(int n=l; n<=9; n++){
				ret += rec( i-1, g, l, n );
				ret %= MOD;
			}
		}
	}else{
		int d = ( l - ll );
		for(int n=l; n<=9; n++){
			if( (n-l) == d ){
				ret += rec( i-1, g, l, n);
				ret %= MOD;
			}else{
				ret += rec( i-1, g-1, 0, n);
				ret %= MOD;
			}
		}
	}
	return ret;
}
int N,A;
int main(){
	memset( cache, -1, sizeof cache );
	while(1){
		if( scanf("%d%d",&N,&A) != 2 ) break;
		printf("%d\n",rec(N, A, 0, 0 ) );
	}
	return 0;
}