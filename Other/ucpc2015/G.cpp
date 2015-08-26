// Aug 25 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int MAXV = 222222;
vvi linkd;
int N,M,Q, a,b;
int disc[MAXV], low[MAXV], sz[MAXV], par[MAXV][20], dep[MAXV], dfscnt;
int pre[MAXV];

int dfs( int now, int p ){
	disc[now] = low[now] = ++dfscnt; pre[dfscnt] = now;
	par[now][0] = p; dep[now] = dep[p]+1; sz[now] = 1;

	for( auto it : linkd[now] ){
		if( it == p ) continue;
		if( disc[it] == -1 ){
			low[now] = min( low[now], dfs( it, now ) );
			sz[now] += sz[it];
		}else
			low[now] = min( low[now], disc[it] );
	}
	return low[now];
}

int up(int v, int k){
    for(int i=0; i<20; i++)
        if( 1<<i & k ) v = par[v][i];
    return v;
}
int lca(int u, int v){
    if( dep[u] < dep[v] )
        swap( u, v );
    u = up(u, dep[u] - dep[v]);
    if( u==v ) return u;

    for(int i=19; i>=0; i--)
        if( par[u][i] != par[v][i] )
            u = par[u][i], v = par[v][i];
    
    u = par[u][0], v = par[v][0];
    return u!=v ? -1 : u;
}

int T;
int main(){
	scanf("%d",&T);
	while( T-- ){
		scanf("%d%d",&N,&M);
		vvi(N).swap( linkd );
		for(int i=0; i<M; i++){
			scanf("%d%d",&a,&b); a--;b--;
			linkd[a].push_back(b);
			linkd[b].push_back(a);
		}
		memset( disc, -1, sizeof disc );
		memset( sz, 0, sizeof sz );
		memset( dep, 0, sizeof dep );
		memset( par, 0, sizeof par );
		memset( low, 0, sizeof low );
		dfscnt = 0;
		dfs( 0, 0 );
		assert( sz[0] == N );

		for(int j=1; j<20; j++)
        	for(int i=0; i<N; i++)
            	par[i][j] = par[ par[i][j-1] ][j-1];

		scanf("%d",&Q);
		while(Q--){
			scanf("%d%d",&a,&b); a--;b--;
			int l = lca( a,b );
			if( l == a || l == b ){
				int p = l, chd = ( a + b ) - l;
				int lst = up( chd, dep[chd] - dep[p] - 1 );
				assert( par[lst][0] == p );

				int ans = sz[lst] - sz[chd];
				if( low[lst] < disc[p] ){
					ans += sz[0] - sz[p];
					for( auto it : linkd[p] ){
						if( dep[it] != dep[p] + 1 ) continue;
						if( it == lst ) continue;
						if( low[it] < disc[p] ) ans += sz[it];
					}
				}

				for( auto it : linkd[chd] ){
					if( dep[it] != dep[chd] + 1 ) continue;
					if( low[it] < disc[chd] ) ans += sz[it];
				}
				assert( ans+2 <= N );
				printf("%d\n",ans+2);
			}else{
				int ans = sz[0] - sz[a] - sz[b];
				for( auto it : linkd[a] ){
					if( dep[it] != dep[a] + 1 ) continue;
					if( low[it] < disc[a] ) ans += sz[it];
				}
				for( auto it : linkd[b] ){
					if( dep[it] != dep[b] + 1 ) continue;
					if( low[it] < disc[b] ) ans += sz[it];
				}
				assert( ans+2 <= N );
				printf("%d\n",ans+2);
			}
		}
	}
	return 0;
}