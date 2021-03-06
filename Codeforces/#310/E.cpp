// Jun 29 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

const int MAXV = 222222;

int N,M,Q, a,b;
int fr[MAXV], to[MAXV], br[MAXV];
vector<vi> linkd;

int disc[MAXV], low[MAXV], dfscount, sccId[MAXV], sccCount;
vi st;
int dfs1(int u, int pid){
	low[u] = disc[u] = ++dfscount;
	st.push_back( u );
	for(auto it : linkd[u]){
		if( it == pid ) continue;
		int v = fr[it] + to[it] - u;
		if( disc[v] == 0 ){
			low[u] = min(low[u], dfs1(v, it));
			if( low[v] > disc[u] ) br[it] = 1;
		}
		else
			low[u] = min(low[u], disc[v]);
	}
	if( low[u] == disc[u] ){
		while(1){
			int top = st.back(); st.pop_back();
			sccId[top] = sccCount;
			if( top == u ) break;
		}	++sccCount;
	}
	return low[u];
}

// par[i][j] : 2^jth parent of i
int dep[MAXV], par[MAXV][20];
vi preorder;
void dfs2(int u, int p){
	preorder.push_back(u);
	par[u][0] = p; dep[u] = dep[p]+1;
	for(auto v : linkd[u]){
		if( v == p ) continue;
		dfs2(v, u);
	}
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

int main(){
	scanf("%d%d%d",&N,&M,&Q);
	vector<vi>(N).swap(linkd);
	for(int i=0; i<M; i++){
		scanf("%d%d",&a,&b); a--;b--;
		linkd[a].push_back(i);
		linkd[b].push_back(i);
		fr[i]=a, to[i]=b;
	}
	for(int i=0; i<N; i++) if( disc[i] == 0 )
		dfs1(i, -1);

	vector<vi>(sccCount).swap(linkd);
	for(int i=0; i<M; i++) if( br[i] ){
		int u = sccId[fr[i]], v = sccId[to[i]]; assert( u!= v );
		linkd[u].push_back(v);
		linkd[v].push_back(u);
	}

	memset( par, -1, sizeof par );
	for(int i=0; i<sccCount; i++)
		if( par[i][0] == -1 ) dfs2( i, i );

	for(int j=1; j<20; j++)
		for(int i=0; i<sccCount; i++)
			par[i][j] = par[ par[i][j-1] ][j-1];

	bool ans = true;
	vector<int> in(sccCount), out(sccCount);
	while( Q-- ){
		scanf("%d%d",&a,&b); a--; b--;
		a = sccId[a]; b = sccId[b];
		if( a == b ) continue;
		int l = lca(a, b);
		if( l == -1 ) ans = false;
		out[a]++; out[l]--;
		in[b]++; in[l]--;
	}
	for(auto it = preorder.rbegin(); it!= preorder.rend() && ans; ++it){
		int u = *it, p = par[u][0];
		if( u!=p ) in[p]+=in[u], out[p]+=out[u];
		if( in[u] > 0 && out[u] > 0 ) ans=false;
	}
	puts( ans? "Yes" : "No");
	return 0;
}