// Jun 27 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 222222;
typedef long long lld;
typedef pair<lld, lld> ii;
typedef pair<ii, int> iii;

int N,M; lld land[MAXN][2]; ii br[MAXN];
int main(){
	scanf("%d%d",&N,&M);
	vector<iii> conds;
	for(int i=0; i<N; i++){
		scanf("%lld%lld",&land[i][0],&land[i][1]);
		if( i ) conds.push_back( iii( ii( land[i][0] - land[i-1][1], land[i][1] - land[i-1][0] ) , i ) );
	}
	for(int i=0; i<M; i++){
		scanf("%lld",&br[i].first); br[i].second = i+1;
	}
	sort( conds.begin(), conds.end() );
	sort( br, br + M );

	int nb = 0;
	bool poss = true;
	vector<ii> ans;
	for( auto it : conds ){
		printf("%lld %lld\n", it.first.first, it.first.second);
		while( nb < M && br[nb].first < it.first.first ) nb++;
		if( nb >= M || it.first.second < br[nb].first ) { poss = false; break; }
		ans.push_back( { it.second, br[nb].second } ); nb++;
	}
	if( !poss ) printf("No");
	else{
		printf("Yes\n");
		sort( ans.begin(), ans.end() );
		for(auto it : ans) printf("%d ",(int)it.second);
	}
	return 0;
}