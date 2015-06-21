#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
const int MAXN = 5e4+10;
struct Edge { int to, co; };
int T, N,M,S, a,b,c, visited[MAXN];
lld sl[MAXN][111];
vector<Edge> linkd[MAXN];

int main(){
	scanf("%d",&T);
	while(T--){ 
		scanf("%d%d%d",&N,&M,&S);
		memset( visited, 0, sizeof visited );
		memset( sl, 0, sizeof sl );
		for(int i=0;i<N;i++) linkd[i].clear();
		for(int i=0;i<M;i++){
			scanf("%d%d%d",&a,&b,&c); a--; b--;
			linkd[a].push_back( {b, c} );
		}
		lld ans = 0;
		for(int here = 0; here < N; here++ ){
			for( auto it : linkd[here] ){
				sl[it.to][1] = max( sl[it.to][1], (lld) it.co ); ans = max(ans, sl[it.to][1]);
				for( int i = 1; i < S; i++ )
					sl[it.to][i+1] = max( sl[it.to][i+1] , sl[here][i] + it.co ), ans = max(ans, sl[it.to][i+1]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}