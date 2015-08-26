// Aug 25 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAXN = 111111;
vvi linkd;
int dep[MAXN], par[MAXN][20];

// par[i][j] : 2^jth parent of i
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

int q[MAXN], ql, qh, N,a;
int main(){
	scanf("%d",&N);
	vvi(N).swap(linkd);
	for(int i=1; i<N; i++){
		scanf("%d",&a); a--;
		linkd[a].push_back(i);
		par[i][0] = a;
	}
    for(int j=1; j<20; j++)
        for(int i=0; i<N; i++)
            par[i][j] = par[ par[i][j-1] ][j-1];

  	q[ql] = 0; qh = 1;
  	while( ql != qh ){ 
  		int now = q[ql++]; dep[now] = dep[ par[now][0] ] + 1;
  		for( auto it : linkd[now] )
  			q[qh++] = it;
  	}

  	long long ans = 0LL;
  	for(int i=0; i<N-1; i++){
  		int l = lca( q[i], q[i+1] );
  		// printf("%d %d %d\n",dep[q[i]], dep[l], dep[ q[i+1] ] );
  		ans += dep[ q[i] ] - dep[l] + dep[ q[i+1] ] - dep[l];
  	}
  	printf("%lld\n",ans);
	return 0;
}