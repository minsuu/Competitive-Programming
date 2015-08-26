// Aug 24 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
map<lld, lld> ans;

const lld MOD = 1234567891;

int T;
lld N,M, now[4], nxt[4]; // 0,0 0,1 1,0 1,1
inline void add( lld a, lld b, lld c ){
	if( a==1 ) { ans[b]+=c; ans[b]%=MOD; return; }
	if( b==1 ) { ans[a]+=c; ans[a]%=MOD; return; }
	nxt[ 2*(a == N/2+1) + (b == M/2+1) ] += c;
	nxt[ 2*(a == N/2+1) + (b == M/2+1) ] %= MOD;
}
inline void go( lld n, lld m, lld s ){
	if( s==0 ) return;
	if( n==1 ) { ans[m]+=s; ans[m]%=MOD; return; }
	if( m==1 ) { ans[n]+=s; ans[n]%=MOD; return; }
	lld a = n/2, b = n - a, c = m/2, d = m - c;
	add(a,c,s); add(a,d,s); add(b,c,s); add(b,d,s);
}
int main(){
	scanf("%d",&T);
	while( T-- ){
		scanf("%lld%lld",&N,&M);
		ans.clear(); memset( now, 0, sizeof now );
		if( N > M ) swap(N, M);
		now[0] = 1;
		while( now[0] || now[1] || now[2] || now[3] ){
			memset( nxt, 0, sizeof nxt );

			go( N, M, now[0] );
			go( N, M+1, now[1] );
			go( N+1, M, now[2] );
			go( N+1, M+1, now[3] );

			memcpy( now, nxt, sizeof nxt );
			N/=2; M/=2;
		}
		printf("%lld\n",(lld)ans.size());
		for(auto it : ans )
			printf("%lld %lld\n",it.first,it.second);
	}
	return 0;
} 