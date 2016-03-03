#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
const lld INF = 987654321987654321LL;

int N, RS;
lld R[33], S[33], L;
set<lld> rset, lset;

void dfs( int i, int n, lld num, set<lld>& sss ){
	if( i == n ){
		sss.insert( num );
		return;
	}
	lld cr = L*R[i]/RS;
	if( L*R[i] % RS == 0 && cr % S[i] == 0 ){
		dfs( i+1, n, num + cr, sss );
	}else{
		lld lo = cr/S[i]*S[i];
		dfs( i+1, n, num + lo, sss );
		dfs( i+1, n, num + lo + S[i], sss );
	}
}

lld mini, ans;
inline void upans( lld ss ){
	lld dd = L - ss; if(dd<0) dd*=-1LL;
	if( mini > dd ){
		mini = dd; ans = ss;
	}else if( mini == dd && ans > ss ){
		ans = ss;
	}
}

int main(){
	freopen( "splitter.in", "r", stdin );
	freopen( "splitter.out", "w", stdout );
	scanf("%d%lld",&N,&L);
	for(int i=0; i<N; i++){
		scanf("%lld",&R[i]);
		RS += R[i];
	}
	for(int i=0; i<N; i++){
		scanf("%lld",&S[i]);
	}
	dfs( 0, N/2, 0, lset );
	dfs( N/2, N, 0, rset );

	mini = INF, ans = -1;
	for( auto it : lset ){
		auto jt = rset.lower_bound( L-it );
		if( jt == rset.begin() ){
			upans( it + *jt );
		}else{
			upans( it + *jt );
			upans( it + *(--jt) );
		}
	}
	printf("%lld\n",ans);
	fclose( stdin );
	fclose( stdout );
	return 0;
}
