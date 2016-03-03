#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int N, K, a[222];
int cache[222][222][1010];
int dp( int i, int j, int k ){
	if( i == N ) return j==0;
	int& ret = cache[i][j][k];
	if( ret != -1 ) return ret;
	
	int kk = k + j * ( a[i] - (i?a[i-1]:0) );
	if( kk > K ) return 0;
	ret = ( (j+1)*1LL*dp(i+1,j,kk) + dp(i+1,j+1,kk) + j*1LL*(j?dp(i+1,j-1,kk):0) ) % MOD;
	return ret;
}

int main(){
	scanf("%d%d",&N,&K);
	for(int i=0; i<N; i++) scanf("%d",&a[i]);
	sort( a, a+N );

	memset( cache, -1, sizeof cache );
	printf("%d", dp(0,0,0) );
	return 0;
}
