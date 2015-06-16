#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int T,N,M, a,b;
int disc[MAXN], low[MAXN], vCnt;
int sccId[MAXN], sCnt, sccSz[MAXN];
vvi linkd;

void tarjanSCC(){
	struct STE { int here, iter; };
	memset( disc, -1, sizeof disc );
	memset( sccId, -1, sizeof sccId );
	for(int b=0; b<N; b++){
		if( disc[b] != -1 ) continue;
		stack<STE> st, scc; st.push( { b, 0 } );
		while( !st.empty() ){
			int here = st.top().here, iter = st.top().iter; st.top().iter++;
			if( iter == 0 ){
				low[here] = disc[here] = vCnt++;
				scc.push( here );
			}
			if( iter == linkd[here].size() ){
				st.pop();
				for( auto it : linkd[here] )
					low[here] = min( low[here], low[])
				if( low[here] == disc[here] ){ // new SCC!
					while(1){
						sccId[ scc.top() ] = sCnt;
						sccSz[ sCnt ] ++;
						if( scc.top() == here ) break;
						scc.pop();
					} sCnt++;
				} continue;
			}
			int there = linkd[here][iter];
			if(  )
		}
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		vvi(N).swap(linkd);
		for(int i=0; i<M; i++){
			scanf("%d%d",&a,&b); a--;
			linkd[a].push_back(b);
		}

	}
	return 0;
}