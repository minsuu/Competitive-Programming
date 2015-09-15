#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int cache[111][111][111];
int dp(int N, int L, int R ){
	if( N == 0 ) return 1;
	if( L == 0 || R == 0 ) return 0;
	if( N == 1 ) return ( L==1 && R==1 );

	int& ret = cache[N][L][R];
	if( ret != -1 ) return ret;

	ret = 0;
	if( N == 2 ){
		ret += dp( N-1, L-1, R ); ret %= MOD;
		ret += dp( N-1, L, R-1 ); ret %= MOD;
	}else{
		ret = ( ret + (N-2) * 1LL * dp( N-1, L, R ) ) % MOD;
		ret += dp( N-1, L-1, R ); ret %= MOD;
		ret += dp( N-1, L, R-1 ); ret %= MOD;
	}
	return ret;
}
int main(){
	memset( cache, -1, sizeof cache );
	int N,L,R;
	scanf("%d%d%d",&N,&L,&R);
	printf("%d",dp(N,L,R));
	return 0;
}