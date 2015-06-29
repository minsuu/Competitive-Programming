// Jun 27 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 222222;
typedef long long lld;
typedef pair<lld, lld> ii;
typedef pair<ii, int> iii;

int N,M; lld land[MAXN][2]; ii br[MAXN];
int ans[MAXN];
int main(){
	scanf("%d%d",&N,&M);
	vector<iii> conds;
	for(int i=0; i<N; i++){
		scanf("%lld%lld",&land[i][0],&land[i][1]);
		if( i ) conds.push_back( iii( ii( land[i][1] - land[i-1][0], land[i][0] - land[i-1][1] ) , i ) );
	}
	for(int i=0; i<M; i++){
		scanf("%lld",&br[i].first); br[i].second = i+1;
	}
	sort( conds.begin(), conds.end() );
	sort( br, br + M );

	int nb = 0;
	bool poss = true;
	set<ii> avbrid;
	for( auto it : conds ){
		while( nb < M && br[nb].first <= it.first.first ){
			avbrid.insert( br[nb++] );
		}
		auto jt = avbrid.lower_bound( ii( it.first.second, 0 ) );
		if( jt == avbrid.end() ) { poss = false; break; }
		ans[ it.second ] = jt->second;
		avbrid.erase(jt);
	}
	if( !poss ) printf("No");
	else{
		printf("Yes\n");
		for(int i=1; i<N; i++)
			printf("%d ",ans[i]);
	}
	return 0;
} 