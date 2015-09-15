#include <bits/stdc++.h>
using namespace std;
int N, del[222],pos[222], st[222];

int cache[222][222];
int dp(int l, int r){
	printf("%d %d\n",l,r);
	if( l + r == N ) return 0;
	
	int& ret = cache[l][r];
	if( ret != -1 ) return ret;

	int s;
	for( s = l+1; st[s] <= l || N+1-r <= st[s] ; s++ );
	int ss;
	for( ss = r+1; N+1-r <= st[N+1-ss] || st[N+1-ss] <= l ; ss++ );

	return ret = min( dp( s, ss-1 ) , dp( s-1, ss ) ) + 1;
}
int main(){
	memset( cache, -1, sizeof cache );
	scanf("%d",&N);
	for(int i=1; i<=N; i++){
		scanf("%d",&st[i]);
	}
	printf("%d",dp(0,0));
	return 0;
}