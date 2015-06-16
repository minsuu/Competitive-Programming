#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int MAXN = 222;

int T,N,M, a,b;
int disc[MAXN], low[MAXN], loop[MAXN], vCnt;
int sccId[MAXN], sCnt, sccSz[MAXN];
vvi linkd;

void tarjanSCC(){
	struct STE { int here, iter; };
	vCnt = sCnt = 0;
	memset( disc, -1, sizeof disc );
	memset( sccId, -1, sizeof sccId );
	memset( sccSz, 0, sizeof sccSz );
	for(int b=0; b<N; b++){
		if( disc[b] != -1 ) continue;
		stack<STE> st; stack<int> scc; st.push( { b, 0 } );
		while( !st.empty() ){
			int here = st.top().here, iter = st.top().iter; st.top().iter++;
			if( iter == 0 ){
				low[here] = disc[here] = vCnt++;
				scc.push( here );
			}
			if( iter == linkd[here].size() ){
				st.pop();
				for( auto there : linkd[here] ){
					if( disc[here] < disc[there] ){ // tree edge
						low[here] = min( low[here], low[there] );
					} else if ( sccId[there] == -1 ){ // back edge, no-scc cross edge
						low[here] = min( low[here], disc[there] );
					}
				}
				if( low[here] == disc[here] ){ // new SCC!
					while(1){
						sccId[ scc.top() ] = sCnt;
						sccSz[ sCnt ] ++;
						if( scc.top() == here ) break;
						scc.pop();
					} sCnt++; scc.pop();
				} continue;
			}
			int there = linkd[here][iter];
			if( disc[there] == -1 )
				st.push( { there, 0 } );
		}
	}
}
struct EDGE{
	int u, v;
	bool operator<(const EDGE &r) const {
		return sccId[u]==sccId[r.u] ? sccId[v] > sccId[r.v] : sccId[u] < sccId[r.u] ;
	}
};
vector<EDGE> edge;
bool conn[MAXN][MAXN];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		vvi(N).swap(linkd); edge.clear();
		memset( loop, 0, sizeof loop );
		memset( conn, 0, sizeof conn );
		for(int i=0; i<M; i++){
			scanf("%d%d",&a,&b); a--; b--;
			if( a == b ) loop[a] = 1;
			else linkd[a].push_back(b);
		}
		tarjanSCC();
		//for(int i=0; i<N; i++) printf("%d ",sccId[i]); printf("\n");
		//for(int i=0; i<N; i++) printf("%d ",sccSz[i]); printf("\n");
		for(int i=0; i<N; i++) for(auto j : linkd[i])
			if( sccId[i] != sccId[j] )
				edge.push_back( {i, j} );
		sort( edge.begin(), edge.end() );
		int ans = 0;
		for(int i=0; i<sCnt; i++){
			if( sccSz[i] != 1 ) ans+=sccSz[i];
			conn[i][i] = true;
		}
		for(int i=0; i<N; i++)
			if( loop[i]==1 && sccSz[sccId[i]]==1 ) // need loop
				ans++;
		for( auto it : edge ){
			int u=sccId[it.u], v=sccId[it.v];
			bool changed = false;
			for(int i=0; i<sCnt; i++)
				if( conn[v][i] && !conn[u][i] )
					changed = conn[u][i] = true;
			if( changed ) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
