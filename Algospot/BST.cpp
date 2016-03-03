#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int T,N,l[111],r[111],v[111], mn[111], mx[111];
bool dfs( int nw ){
	int rmn = INF, lmx = -INF;
	mn[nw] = v[nw], mx[nw] = v[nw];
	if( r[nw] != -1 ){
		if( !dfs(r[nw]) ) return false;
		rmn = min( rmn, mn[ r[nw] ] );
		mn[nw] = min( mn[nw], mn[ r[nw] ] );
		mx[nw] = max( mx[nw], mx[ r[nw] ] );
	}
	if( l[nw] != -1 ){
		if( !dfs(l[nw]) ) return false;
		lmx = max( lmx, mx[ l[nw] ] );
		mn[nw] = min( mn[nw], mn[ l[nw] ] );
		mx[nw] = max( mx[nw], mx[ l[nw] ] );
	}
	if( !( v[nw] < rmn && lmx < v[nw] ) ) return false;
	return true;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		set<int> root;
		for(int i=0; i<N; i++) root.insert( i );
		for(int i=0; i<N; i++){
			scanf("%d%d%d",&l[i],&r[i],&v[i]);
			l[i]--; r[i]--; root.erase( l[i] ); root.erase( r[i] );
		}
		int r = *root.begin(); assert( root.size() == 1 );
		if( dfs(r) ) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}