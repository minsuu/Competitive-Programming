#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long lld;
typedef pair<lld, lld> ii;
ii s[55];
lld w[55], c[55], W;
int N;

map< pair<int,lld> , lld> cache;

lld rec( int i, lld ww ){
	if( i == -1 ) return 0;
	if( ww == 0LL ) return 0;
	if( w[i] < ww ) return c[i];

	if( cache.count( {i, ww} ) ){
		return cache[ {i,ww} ];
	}
	lld ret = 0LL;
	if( s[i].F <= ww ){
		ret = max( ret, s[i].S + rec( i-1, ww - s[i].F ) );
	}
	ret = max( ret, rec( i-1, ww ) );
	return cache[ {i,ww} ] = ret;
}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%lld%lld",&s[i].F, &s[i].S );
	}
	scanf("%lld",&W);

	sort( s, s+N );
	for(int i=0; i<N; i++){
		w[i] = ( ( i == 0 ) ? 0 : w[i-1] ) + s[i].F;
		c[i] = ( ( i == 0 ) ? 0 : c[i-1] ) + s[i].S;
	}
	printf("%lld", rec(N-1, W) );
	return 0;
}