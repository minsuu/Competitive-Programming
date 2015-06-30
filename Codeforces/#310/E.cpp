// Jun 29 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

const int MAXV = 222222;

int N,M,Q, a,b;
int fr[MAXV], to[MAXV], br[MAXV];
vi linkd[MAXV];

int disc[MAXV], low[MAXV], dfscount, sccId[MAXV], sccCount;
vi st;
int dfs1(int u, int pid){
	low[u] = disc[u] = dfscount++;
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
void dfs2(int u, int p){
	par[u][0] = p; dep[u] = p==-1? 0: dep[p]+1;
	for(auto v : linkd[u]){
		if( v == p ) continue;
		dfs2(v, u);
	}
}

int main(){
	scanf("%d%d%d",&N,&M,&Q);
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
	for(int i=0; i<N; i++)

	return 0;
} 